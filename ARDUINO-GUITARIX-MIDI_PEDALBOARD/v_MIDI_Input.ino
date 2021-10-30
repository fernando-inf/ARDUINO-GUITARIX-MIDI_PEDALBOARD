#if NO_USE_MIDI_INPUT
#else
void MIDI_Input_CC(byte channel, byte number, byte value) { //Revisar Channel, podría traer problemas si se recibe mensajes MIDI de otro Canal distinto al Canal 1.

  //MODO INDIVIDUAL: Recibe mensajes MIDI Control Change de la PC y enciende y apaga LED de los pedales 1 al 6
  if (tgSt[0] == 1) {
    for (byte i = 0; i <= 5; i++) {
      if (number == CC[i]) {
        if (value == valOn && tgSt[i + 1] == 1) {
          digitalWrite(LED[i + 1], HIGH);
          tgSt[i + 1] = 0;
          tgStB[i] = 0;
        }
        if (value == valOff && tgSt[i + 1] == 0) {
          digitalWrite(LED[i + 1], LOW);
          tgSt[i + 1] = 1;
          tgStB[i] = 1;
        }
      }
    }
  }

  if (tgSt[0] != 1) {
    for (byte i = 0; i <= 5; i++) { //Estando la pedalera en MODO distinto al MODO INDIVIDUAL, obtiene el estado on/off de los Pedales (los almacena en la variable tgStB) para cuando se pase al MODO INDIVIDUAL se refleje en los led- Ver Void_D2
      if (number == CC[i]) {
        if (value == valOn) {
          tgStB[i] = 0;
        }
        if (value == valOff) {
          tgStB[i] = 1;
        }
      }
    }
  }

  //MODO BANCO: Recibe mensajes MIDI Control Change de la PC y refleja en número de banco seleccionado ene l software.
  if (tgSt[0] == 0 && (number == 32 || number == 0)) {
    valBank = value;
    LED_Presets();
    LCD_OLED();  //Escribe en el LCD/OLED.
  }

  if (tgSt[0] != 0 && (number == 32 || number == 0)) { //Estando la pedalera en MODO distinto al MODO BANCO, obtiene el estado controlChange (CC32 o CC0) para cuando se pase al MODO BANCO se refleje en los led- Ver Void_D2
    for (int i = 0; i <= valBankMax; i++) {
      if (value == i) {
        valBank = i;
      }
    }
  }

  //MODO TUNER
  if (tgSt[0] == 3) {
    if (number == CCtuner[0] && value == 0) {
      tunerNote = 12;
      LCD_OLED();
      for (byte i = 0; i <= 6; i++) {
        digitalWrite(LED[i], LOW);
      }
    }
  }
}

void MIDI_Input_ProgramChange(byte channel, byte number) {

  //MODO BANCO: Recibe mensajes MIDI ProgramChange de la PC y enciende y apaga LED de cada Preset según se elija en el software, a la vez cambia el estado de la variable "pc", este cambio sirve para el parpadeo de LED, si "pc" distinto de 128 no parpadean, ya que se ha elegido un preset/programa.
  if (tgSt[0] == 0) {
    for (byte i = 0; i <= 3; i++) {
      pc = number;
      LED_Presets();
      LCD_OLED();  //Escribe en el LCD/OLED.
    }
  }

  if (tgSt[0] != 0) { //Estando la pedalera en un MODO distinto al MODO BANCO, obtiene el estado programChange (Variable "pc") para cuando se pase al MODO BANCO se refleje en los leds- VER Void Pedal1
    for (byte i = 0; i <= 3; i++) {
      if (number == i) {
        pc = i;
      }
    }
  }
}
#endif
