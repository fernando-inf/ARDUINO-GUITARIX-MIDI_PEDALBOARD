
void voidPedal5() {
  //MODO BANCO
  if (tgSt[0] == 0) {
    pc = 2;
    MIDI.sendControlChange(CCBank, valBank, Ch);
    MIDI.sendProgramChange(pc, Ch);
    LCD_OLED();
    LED_Presets();
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[5] == 1) {
      MIDI.sendControlChange(CC[4], valOn, Ch);
      digitalWrite(LED[5], HIGH);
      tgSt[5] = 0;
      tgStB[4] = 0;
    } else if (tgSt[5] == 0) {
      MIDI.sendControlChange(CC[4], valOff, Ch);
      digitalWrite(LED[5], LOW);
      tgSt[5] = 1;
      tgStB[4] = 1;
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (tgStLoopD[2] == 1) {
      MIDI.sendControlChange(CC[4], valOn, ChLoopD);
      digitalWrite(LED[5], HIGH);
      tgStLoopD[2] = 0;
    } else if (tgStLoopD[2] == 0) {
      MIDI.sendControlChange(CC[4], valOff, ChLoopD);
      digitalWrite(LED[5], LOW);
      tgStLoopD[2] = 1;
    }
  }
}
