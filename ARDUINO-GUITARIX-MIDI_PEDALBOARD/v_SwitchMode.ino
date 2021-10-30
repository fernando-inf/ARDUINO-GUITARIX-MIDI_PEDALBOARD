
void switchMode() {  //Cambio de MODO.

  //MODO BANCO
  if (tgSt[0] == 0) {
    LEDs_Off();
    LCD_OLED(); //Escribe en el LCD/OLED.
    LED_Presets(); //LEDs indicadores de BANCO y PRESET. Ver pestaña "VoidLED_Presets"
#if NO_USE_MIDI_INPUT
#else
    MIDI.sendControlChange(CCtuner[1], valOff, Ch); //Tuner Off
#endif
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    LEDs_Off();
    LCD_OLED();                  //Escribe en el LCD/OLED.
    digitalWrite(LED[0], HIGH);  //ENCENDER Primer LED = Indica encendido de MODO INDIVIDUAL
#if NO_USE_MIDI_INPUT
#else
    MIDI.sendControlChange(CCtuner[1], valOff, Ch); //Tuner Off
#endif
#if NO_USE_MIDI_INPUT
    for (byte i = 0; i <= 5; i++) {
      MIDI.sendControlChange(CC[i], valOff, Ch);  //Apaga todos los pedales individuales al pasar del MODO BANCO al INDIVIDUAL. Esto indica al usuario en forma directa el estado de los pedales en el software. Así queda en evidencia que el MODO BANCO y el INDIVIDUAL solo son totalmente compatibles/viables si se tiene MIDIInput y Output juntos.
      digitalWrite(LED[i + 1], LOW);
      tgSt[i + 1] = 1;
    }

#else
    //Cambia el estado de TgStB (TgSt solo para MODO Banco). Su objetivo es encender o apagar los LEDS cuando se pasa del MODO BANCO al MODO INDIVIDUAL, para esto se usan otros TgSt denominados "TgStB".
    for (byte i = 0; i <= 5; i++) {
      if (tgStB[i] == 0) {
        digitalWrite(LED[i + 1], HIGH);
        tgSt[i + 1] = 0;
      } else {
        digitalWrite(LED[i + 1], LOW);
        tgSt[i + 1] = 1;
      }
    }

#endif
#if USE_LEDs
    for (byte i = 7; i <= 10; i++) {
      digitalWrite(LED[i], LOW);  //Apaga LEDs BANCO.
    }
#endif
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    LEDs_Off();
    LCD_OLED();  //Escribe en el LCD/OLED.
    if (tgStLoopD[0] == 0) {
      digitalWrite(LED[3], HIGH);
    } else if (tgStLoopD[0] == 1) {
      digitalWrite(LED[3], LOW);
    }
#if NO_USE_MIDI_INPUT
#else
    MIDI.sendControlChange(CCtuner[1], valOff, Ch); //Tuner Off
#endif
  }

#if NO_USE_MIDI_INPUT
#else
  //MODO TUNER
  else if (tgSt[0] == 3) {
    LEDs_Off();
    MIDI.sendControlChange(CCtuner[1], valOn, Ch);
    LCD_OLED();  //Escribe en el LCD/OLED.

#if USE_7SEGMENTS_16bits
    //           Bedcpabgf; // Digit Left
    numLeft[0] = B10101111; // A
    numLeft[1] = B11101111; // B
    numLeft[2] = B11001001; // C
    numLeft[3] = B11101101; // D
    numLeft[4] = B11001011; // E
    numLeft[5] = B10001011; // F
    numLeft[6] = B11101011; // G
    numLeft[7] = B10100111; // H
#endif
  }
#endif
}
