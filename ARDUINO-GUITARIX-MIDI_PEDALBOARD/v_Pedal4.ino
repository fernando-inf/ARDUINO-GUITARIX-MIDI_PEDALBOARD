
unsigned long startTime1 = 0;
unsigned long startTime2 = 0;
unsigned long lapsetime = 0;
const int MAX_INTERVAL_TAP = 1000; //ms = 60 BPM - https://guitargearfinder.com/guides/convert-ms-milliseconds-bpm-beats-per-minute-vice-versa/

void voidPedal4() {

  //MODO BANCO
  if (tgSt[0] == 0) {
    pc = 1;
    MIDI.sendControlChange(CCBank, valBank, Ch);
    MIDI.sendProgramChange(pc, Ch);
    LCD_OLED();
    LED_Presets();
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[4] == 1) {
      MIDI.sendControlChange(CC[3], valOn, Ch);
      digitalWrite(LED[4], HIGH);
      tgSt[4] = 0;
      tgStB[3] = 0;
    } else if (tgSt[4] == 0) {
      MIDI.sendControlChange(CC[3], valOff, Ch);
      digitalWrite(LED[4], LOW);
      tgSt[4] = 1;
      tgStB[3] = 1;
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (tgStLoopD[1] == 1) {
      MIDI.sendControlChange(CC[3], valOn, ChLoopD);
      tgStLoopD[1] = 0;

      //**Obtención de TAP en ms** - Ver prestaña v_LEDs
      startTime2 = millis();
      startTime1 = millis();
      BlinkLEDLoopD();
      //**************************

    } else if (tgStLoopD[1] == 0) {
      MIDI.sendControlChange(CC[3], valOff, ChLoopD);
      tgStLoopD[1] = 1;
      
      //**Obtención de TAP en ms** - Ver prestaña v_LEDs
      startTime2 = millis();
      lapsetime = startTime2 - startTime1;
      if (lapsetime < MAX_INTERVAL_TAP && lapsetime > 0) {
        INTERVAL_TAP = lapsetime;
        startTime1 = millis();
      }
      BlinkLEDLoopD();
      //**************************
    }
  }

#if NO_USE_MIDI_INPUT
#else
  //MODO TUNER
  else if (tgSt[0] == 3) {
    if (tgStTuner[1] == 1) {
      MIDI.sendControlChange(CCtuner[3], valOn, Ch);// Mute On

      //***Encender punto en Display 7 Segmentos***
#if USE_7SEGMENTS_16bits
      //             Bfgbapcde / Digit Right
      numRight[13] = B00001000; // Off
      numRight[11] = B11101101; // H
      numRight[12] = B01001000; // -
#endif
      LCD_OLED();
      //********************************************

      tgStTuner[1] = 0;

    } else if (tgStTuner[1] == 0) {
      MIDI.sendControlChange(CCtuner[3], valOff, Ch);// Mute Off

      //***Apagar punto en Display 7 Segmentos***
#if USE_7SEGMENTS_16bits
      //             Bfgbapcde / Digit Right
      numRight[13] = B00000000; // Off
      numRight[11] = B11100101; // H
      numRight[12] = B01000000; // -
#endif
      LCD_OLED();
      //********************************************

      tgStTuner[1] = 1;
    }
  }
#endif
}
