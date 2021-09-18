Bounce2::Button pedal_6 = Bounce2::Button();

void Pedal6() {
  pedal_6.update();

  //MODO BANCO
  if (tgSt[0] == 0) {
    if (pedal_6.pressed()) {
      pc = 3;
      MIDI.sendControlChange(CCBank, valBank, Ch);
      MIDI.sendProgramChange(pc, Ch);
      LCD_OLED();
      LEDBank_Preset();  
    }
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (pedal_6.pressed()) {
      if (tgSt[6] == 1) {
        MIDI.sendControlChange(CC[5], valOn, Ch);
        digitalWrite(LED[6], HIGH);
        tgSt[6] = 0;
      } else if (tgSt[6] == 0) {
        MIDI.sendControlChange(CC[5], valOff, Ch);
        digitalWrite(LED[6], LOW);
        tgSt[6] = 1;
      }
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (pedal_6.pressed()) {
      if (tgStLoopD[3] == 1) {
        MIDI.sendControlChange(CC[5], valOn, ChLoopD);
        tgStLoopD[3] = 0;
      } else if (tgStLoopD[3] == 0) {
        MIDI.sendControlChange(CC[5], valOff, ChLoopD);
        tgStLoopD[3] = 1;
      }
    }
    if (pedal_6.isPressed()) {
      digitalWrite(LED[6], HIGH);
    } else {
      digitalWrite(LED[6], LOW);
    }
  }
}
