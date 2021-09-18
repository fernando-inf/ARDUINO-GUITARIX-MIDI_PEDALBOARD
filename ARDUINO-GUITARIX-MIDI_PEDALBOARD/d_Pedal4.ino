Bounce2::Button pedal_4 = Bounce2::Button();

void Pedal4() {
  pedal_4.update();

  //MODO BANCO
  if (tgSt[0] == 0) {
    if (pedal_4.pressed()) {
      pc = 1;
      MIDI.sendControlChange(CCBank, valBank, Ch); 
      MIDI.sendProgramChange(pc, Ch);
      LCD_OLED();        
      LEDBank_Preset();
    }
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (pedal_4.pressed()) {
      if (tgSt[4] == 1) {
        MIDI.sendControlChange(CC[3], valOn, Ch);
        digitalWrite(LED[4], HIGH);
        tgSt[4] = 0;
      } else if (tgSt[4] == 0) {
        MIDI.sendControlChange(CC[3], valOff, Ch);
        digitalWrite(LED[4], LOW);
        tgSt[4] = 1;
      }
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (pedal_4.pressed()) {
      if (tgStLoopD[1] == 1) {
        MIDI.sendControlChange(CC[3], valOn, ChLoopD);
        tgStLoopD[1] = 0;
      } else if (tgStLoopD[1] == 0) {
        MIDI.sendControlChange(CC[3], valOff, ChLoopD);
        tgStLoopD[1] = 1;
      }
    }
    if (pedal_4.isPressed()) {
      digitalWrite(LED[4], HIGH);
    } else {
      digitalWrite(LED[4], LOW);
    } 
  }
}
