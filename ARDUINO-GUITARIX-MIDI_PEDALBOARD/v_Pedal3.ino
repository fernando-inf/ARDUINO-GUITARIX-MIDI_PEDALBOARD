
void voidPedal3() {
  //MODO BANCO
  if (tgSt[0] == 0) {
    pc = 0;
    MIDI.sendControlChange(CCBank, valBank, Ch); //MIDI.sendControlChange(cc, valor, ch); CC=0 es MSB, CC=32 es LSB.
    MIDI.sendProgramChange(pc, Ch);
    LCD_OLED();
    LED_Presets();
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[3] == 1) {
      MIDI.sendControlChange(CC[2], valOn, Ch);
      digitalWrite(LED[3], HIGH);
      tgSt[3] = 0;
      tgStB[2] = 0;
    } else if (tgSt[3] == 0) {
      MIDI.sendControlChange(CC[2], valOff, Ch);
      digitalWrite(LED[3], LOW);
      tgSt[3] = 1;
      tgStB[2] = 1;
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (tgStLoopD[0] == 1) {
      MIDI.sendControlChange(CC[2], valOn, ChLoopD);
      digitalWrite(LED[3], HIGH);
      tgStLoopD[0] = 0;
    } else if (tgStLoopD[0] == 0) {
      MIDI.sendControlChange(CC[2], valOff, ChLoopD);
      digitalWrite(LED[3], LOW);
      tgStLoopD[0] = 1;
    }
  }

#if NO_USE_MIDI_INPUT
#else
  //MODO TUNER
  else if (tgSt[0] == 3) {
    if (tgStTuner[0] == 1) {
      MIDI.sendControlChange(CCtuner[2], valOn, Ch);// Bypass On

      //***Encender punto en Display 7 Segmentos***
#if USE_7SEGMENTS_16bits
      //            Bedcpabgf; // Digit Left
      numLeft[0] =  B10111111; // A
      numLeft[1] =  B11111111; // B
      numLeft[2] =  B11011001; // C
      numLeft[3] =  B11111101; // D
      numLeft[4] =  B11011011; // E
      numLeft[5] =  B10011011; // F
      numLeft[6] =  B11111011; // G
      numLeft[11] = B00010010; // -
#endif
      LCD_OLED();
      //********************************************

      tgStTuner[0] = 0;
    } else if (tgStTuner[0] == 0) {
      MIDI.sendControlChange(CCtuner[2], valOff, Ch);// Bypass Off

      //***Apagar punto en Display 7 Segmentos***
#if USE_7SEGMENTS_16bits
      //            Bedcpabgf; // Digit Left
      numLeft[0] =  B10101111; // A
      numLeft[1] =  B11101111; // B
      numLeft[2] =  B11001001; // C
      numLeft[3] =  B11101101; // D
      numLeft[4] =  B11001011; // E
      numLeft[5] =  B10001011; // F
      numLeft[6] =  B11101011; // G
      numLeft[11] = B00000010; // -
#endif
      LCD_OLED();
      //******************************************

      tgStTuner[0] = 1;
    }
  }
#endif
}
