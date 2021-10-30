
void voidPedal6() {
  //MODO BANCO
  if (tgSt[0] == 0) {
    pc = 3;
    MIDI.sendControlChange(CCBank, valBank, Ch);
    MIDI.sendProgramChange(pc, Ch);
    LCD_OLED();
    LED_Presets();
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[6] == 1) {
      MIDI.sendControlChange(CC[5], valOn, Ch);
      digitalWrite(LED[6], HIGH);
      tgSt[6] = 0;
      tgStB[5] = 0;
    } else if (tgSt[6] == 0) {
      MIDI.sendControlChange(CC[5], valOff, Ch);
      digitalWrite(LED[6], LOW);
      tgSt[6] = 1;
      tgStB[5] = 1;
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (tgStLoopD[3] == 1) {
      MIDI.sendControlChange(CC[5], valOn, ChLoopD);
      digitalWrite(LED[6], HIGH);
      delay(100);
      digitalWrite(LED[6], LOW);
      tgStLoopD[3] = 0;
    } else if (tgStLoopD[3] == 0) {
      MIDI.sendControlChange(CC[5], valOff, ChLoopD);
      digitalWrite(LED[6], HIGH);
      delay(100);
      digitalWrite(LED[6], LOW);
      tgStLoopD[3] = 1;
    }
  }
}
