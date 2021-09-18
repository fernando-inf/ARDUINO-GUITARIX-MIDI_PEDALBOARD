Bounce2::Button pedal_5 = Bounce2::Button();

void Pedal5() {
  pedal_5.update();

  //MODO BANCO
  if (tgSt[0] == 0) {
    if (pedal_5.pressed()) {
      pc = 2;
      MIDI.sendControlChange(CCBank, valBank, Ch);  
      MIDI.sendProgramChange(pc, Ch);
      LCD_OLED();        
      LEDBank_Preset();
    }
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (pedal_5.pressed()) {
      if (tgSt[5] == 1) {
        MIDI.sendControlChange(CC[4], valOn, Ch);
        digitalWrite(LED[5], HIGH);
        tgSt[5] = 0;
      } else if (tgSt[5] == 0) {
        MIDI.sendControlChange(CC[4], valOff, Ch);
        digitalWrite(LED[5], LOW);
        tgSt[5] = 1;
      }
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (pedal_5.pressed()) {
      if (tgStLoopD[2] == 1) {
        MIDI.sendControlChange(CC[4], valOn, ChLoopD);
        tgStLoopD[2] = 0;
      } else if (tgStLoopD[2] == 0) {
        MIDI.sendControlChange(CC[4], valOff, ChLoopD);
        tgStLoopD[2] = 1;
      }
    }
    if (pedal_5.isPressed()) {
      digitalWrite(LED[5], HIGH);
    } else {
      digitalWrite(LED[5], LOW);
    }
  }
}
