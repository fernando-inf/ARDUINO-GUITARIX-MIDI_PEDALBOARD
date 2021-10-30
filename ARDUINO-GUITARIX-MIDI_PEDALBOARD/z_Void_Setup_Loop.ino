
void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI); //MIDI_CHANNEL_OMNI= Lee los mensajes de todos los Canales, si está vacío solo lee el Canal 1 en MIDI IN.
#if USE_MIDI_DIN_CONNECTOR_OR_HIDUINO
  Serial.begin(31250); // Si conecta Arduino mediante conector MIDI DIN a algún rack o pedal con Midi Input, o si usa Arduino con 16u2 y Firmware Hiduino o similar.
#elif USE_USBMIDI || USE_ESP32BluetoothBLE
#else
  Serial.begin(115200); // Si conecta Arduino por comunicación serial a la PC (Chip FTDI232 o Ch340).
#endif

#if NO_USE_MIDI_INPUT
#else
  MIDI.setHandleControlChange(MIDI_Input_CC); //MIDI Input ControlChange ver "Void MIDI_Input".
  MIDI.setHandleProgramChange(MIDI_Input_ProgramChange);  //MIDI Input ProgramChange ver "Void MIDI_Input".
  MIDI.setHandleNoteOn(Tuner);
#endif

  //*****************
#if USE_MIDI_THRU //ver: https://github.com/brummer10/guitarix/issues/80
#if USE_USBMIDI || USE_ESP32BluetoothBLE
  MIDI.turnThruOn();  //En biblioteca USB-MIDI/BLEEMIDI, MIDI-Thru está desactivado por defecto: https://github.com/lathoub/Arduino-USBMIDI
#else
#endif
#else
#if USE_USBMIDI || USE_ESP32BluetoothBLE
#else
  MIDI.turnThruOff();//Evita que la señales que entran vuelvan a salir, en librería MIDI, MIDI-Thru está activado por defecto.
#endif
#endif
  //*****************

#if USE_ESP32BluetoothBLE
  BLEMIDI.setHandleConnected(OnConnected); //Enciende LED cuando el Dispositivo se ha conectado por Bluetooth.
  BLEMIDI.setHandleDisconnected(OnDisconnected); //Apaga LED cuando el Dispositivo se ha desconectado.
  pinMode(LED_BUILTIN, OUTPUT); //PIN = GPIO2- Habilita LED indicador de conexión Bluetooth
  digitalWrite(LED_BUILTIN, LOW);
#endif

#if USE_LEDs

#if USE_ESP32BluetoothBLE
  for (byte i = 0; i < 7; i++) {
    pinMode(LED[i], OUTPUT);
  }
  for (byte i = 0; i < 7; i++) {
    digitalWrite(LED[i], LOW);
  }
#else
  for (byte i = 0; i < 11; i++) {
    pinMode(LED[i], OUTPUT);
  }
#endif

#elif USE_7SEGMENTS_16bits
  for (byte i = 0; i < 10; i++) {
    pinMode(LED[i], OUTPUT);
  }
#else
  for (byte i = 0; i < 7; i++) {
    pinMode(LED[i], OUTPUT);
  }
#endif

  //BOUNCE2 - http://thomasfredericks.github.io/Bounce2/files/functions.html
#if USE_ESP32BluetoothBLE
  for (byte x = 0; x < 6; x++) {
    pinMode(buttonPin[x], INPUT);  //Sin PULLUP INTERNO
  }
#else
  for (byte x = 0; x < 7; x++) {
    pinMode(buttonPin[x], INPUT_PULLUP);  //Con PULLUP INTERNO
  }
#endif

  switchButton_0.attach(buttonPin[0]);
  switchButton_0.interval(25);
  switchButton_0.setPressedState(LOW);

  pedal_1.attach(buttonPin[1]);
  pedal_1.interval(25);
  //pedal_1.setPressedState(LOW);

  pedal_2.attach(buttonPin[2]);
  pedal_2.interval(25);
  pedal_2.setPressedState(LOW);

  pedal_3.attach(buttonPin[3]);
  pedal_3.interval(25);
  pedal_3.setPressedState(LOW);

  pedal_4.attach(buttonPin[4]);
  pedal_4.interval(25);
  pedal_4.setPressedState(LOW);

  pedal_5.attach(buttonPin[5]);
  pedal_5.interval(25);
  pedal_5.setPressedState(LOW);

  pedal_6.attach(buttonPin[6]);
  pedal_6.interval(25);
  pedal_6.setPressedState(LOW);


#if USE_LEDs
  LED_Presets();
  delay(500);
#elif USE_7SEGMENTS_16bits
  displayNum(0, 0);
  LED_Presets();
  delay(500);
#elif USE_LCD  //LCD 16x2 sin I2C CON ARDUINO MEGA
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("      MIDI      ");
  lcd.setCursor(0, 1);
  lcd.print("   PEDALBOARD   ");

  delay(1000);
  LCD_OLED();
#elif USE_I2C_LCD
  lcd.init();
  lcd.backlight();
  lcd.noAutoscroll();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("      MIDI      ");
  lcd.setCursor(0, 1);
  lcd.print("   PEDALBOARD   ");
  delay(1000);
  LCD_OLED();
#elif USE_OLED  //OLED 128x64
  u8g2.begin();

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr);
  u8g2.setCursor(22, 20);
  u8g2.print("  | MIDI |  ");
  u8g2.sendBuffer();

  u8g2.setFont(u8g2_font_profont22_tr);
  u8g2.setCursor(5, 50);
  u8g2.print("PEDALBOARD");
  u8g2.sendBuffer();

  delay(1000);
  LCD_OLED();
#endif

  //Mensajes MIDI enviados al inicio
  MIDI.sendControlChange(0, 0, Ch);  //Inicia en Banco = 0- MIDI.sendControlChange(CCBank, valBank, ch); CC=0 es MSB, CC=32 es LSB.
  MIDI.sendProgramChange(0, Ch);     //Inicia en el Preset 0.
  //delay(100);
  //MIDI.sendControlChange(1, valOn, Ch); //Trabaja en Noise Repellent con Noise_Learn (usando mod-host en vez de Jalv). Al iniciarse la pedalera envía un CC1 con Valor ON para iniciar la lectura de ruido por 100ms (delay). Se coloca esta línea aquí para que se ejecute solo una vez al inicio.
  //delay(100);
  //MIDI.sendControlChange(1, valOff, Ch); // Luego de 100ms se apaga la toma de muestra de ruido con un Valor OFF.
}

void loop() {
#if NO_USE_MIDI_INPUT
  while (MIDI.read()) {//Los controladores MIDI que solo transmiten datos deben estar diseñados para leer e ignorar todos mensajes entrantes. Si su Software PC está enviando mensajes MIDI, este código simple evitará problemas con los búferes que se llenan con nunca leer mensajes. https://www.pjrc.com/teensy/td_midi.html
    /*read & ignore incoming messages*/
  }
#else
  MIDI.read();  //Lee los mensajes MIDI entrantes de todos los Canales, si quiere leer solo el Canal 1 = MIDI.read(1)
#endif

  switchButton();
  Pedal1();  //Llama a las funciones "void" para ser ejecutadas aquí.
  Pedal2();
  Pedal3();
  Pedal4();
  Pedal5();
  Pedal6();
  BlinkLEDPC();
  BlinkLEDLoopD();
}
