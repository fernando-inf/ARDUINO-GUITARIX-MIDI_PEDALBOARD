
void setup() 
              {
                MIDI.begin(MIDI_CHANNEL_OMNI);//MIDI_CHANNEL_OMNI= Lee los mensajes de todos los Canales, si esta vacio solo lee el Canal 1 en MIDI IN.
                Serial.begin(115200); // Si conecta directo a MIDI sin serial: 31250
                //MIDI.turnThruOff(); //Evita que la señales que entran vuelvan a salir.
                MIDI.setHandleControlChange(MIDI_Input_CC); //Trabaja en la recepciòn de mensajes MIDI ControlChange junto con el Void MIDI_Input
                MIDI.setHandleProgramChange(MIDI_Input_ProgramChange);//Trabaja en la recepciòn de mensajes MIDI ProgramChange junto con el Void MIDI_Input
                for (int x = 0; x < 7; x++) //Para 7 Pines Digitales, subir valor si se colocan mas pines en "const int buttonPin[]" lo mismo para los LED "const int LED[]"
                    {pinMode(buttonPin[x], INPUT_PULLUP);}// X numero de PINES DIGITALES para los Pulsadores
              
                for (int i = 0; i < 11; i++) 
                    {pinMode(LED[i],OUTPUT);}//i = numero de PINES DIGITALES para los LEDs
              
                //BOUNCE2
                          buttonP1_pedal1.attach(buttonPin[1]);  buttonP1_pedal1.interval(70);  buttonP1_pedal1.setPressedState(LOW); 
                          buttonP1_downBank.attach(buttonPin[1]);buttonP1_downBank.interval(70);buttonP1_downBank.setPressedState(LOW); 
                          
                          buttonP2_pedal2.attach(buttonPin[2]);  buttonP2_pedal2.interval(70);  buttonP2_pedal2.setPressedState(LOW); 
                          buttonP2_upBank.attach(buttonPin[2]);  buttonP2_upBank.interval(70);  buttonP2_upBank.setPressedState(LOW); 
                          
                          buttonP3_pedal3.attach(buttonPin[3]);  buttonP3_pedal3.interval(70);  buttonP3_pedal3.setPressedState(LOW); 
                          buttonP4_pedal4.attach(buttonPin[4]);  buttonP4_pedal4.interval(70);  buttonP4_pedal4.setPressedState(LOW);
                          buttonP5_pedal5.attach(buttonPin[5]);  buttonP5_pedal5.interval(70);  buttonP5_pedal5.setPressedState(LOW);
                          buttonP6_pedal6.attach(buttonPin[6]);  buttonP6_pedal6.interval(70);  buttonP6_pedal6.setPressedState(LOW); 
          
                //SI USA LCD 16x2 CON ARDUINO MEGA
                lcd.begin(16, 2);
                lcd.setCursor(0,0);
                
                //Mensajes MIDI enviados al inicio
                delay(500);
                MIDI.sendControlChange(0, 0, Ch); //Inicia en Banco = 0- MIDI.sendControlChange(CCBank, ValBank, ch); CC=0 es MSB, CC=32 es LSB.
                MIDI.sendProgramChange(0, Ch); //Inicia en el Preset 0.
                //delay(100);
                //MIDI.sendControlChange(1, ValOn, Ch); //Trabaja con Noise Repellent con Noise_Learn- Al iniciarse la pedalera envia un CC1 con Valor ON para iniciar la lectura de ruido por 100ms (delay). Se coloca esta linea aqui para que se ejecute solo una vez al inicio.
                //delay(100);
                //MIDI.sendControlChange(1, ValOff, Ch); // Luego de 100ms se apaga la toma de muestra de Ruido con un Valor OFF.
                
              }

void loop() 
              {
                MIDI.read();//Lee todo el tiempo los valores MIDI que el Software esta enviando a Arduino- Lee los mensajes de todos los Canales, si quiere leer solo el Canal 1 = MIDI.read(1)
                button1 ();//LLama a la funciones "void buttonX" para ejecutarse en este Loop- un button por cada pulsador conectado
                button2 ();
                button3 ();
                button4 ();
                button5 ();
                button6 ();
                button7 ();
                BlinkLED();
              }
