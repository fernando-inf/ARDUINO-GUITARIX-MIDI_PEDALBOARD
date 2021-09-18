Bounce2::Button pedal_3 = Bounce2::Button();

void Pedal3() {
  pedal_3.update();

  //MODO BANCO
  if (tgSt[0] == 0) {
    if (pedal_3.pressed()) {
      pc = 0;
      MIDI.sendControlChange(CCBank, valBank, Ch); //MIDI.sendControlChange(cc, valor, ch); CC=0 es MSB, CC=32 es LSB.
      MIDI.sendProgramChange(pc, Ch);
      LCD_OLED();        
      LEDBank_Preset();
    }
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (pedal_3.pressed()) {
      if (tgSt[3] == 1) {
        MIDI.sendControlChange(CC[2], valOn, Ch);
        digitalWrite(LED[3], HIGH);
        tgSt[3] = 0;
      } else if (tgSt[3] == 0) {
        MIDI.sendControlChange(CC[2], valOff, Ch);
        digitalWrite(LED[3], LOW);
        tgSt[3] = 1;
      }
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (pedal_3.pressed()) {
      if (tgStLoopD[0] == 1) {
        MIDI.sendControlChange(CC[2], valOn, ChLoopD);
        tgStLoopD[0] = 0;
      } else if (tgStLoopD[0] == 0) {
        MIDI.sendControlChange(CC[2], valOff, ChLoopD);
        tgStLoopD[0] = 1;
      }
    }
    if (pedal_3.isPressed()) {
      digitalWrite(LED[3], HIGH);
    } else {
      digitalWrite(LED[3], LOW);
    } 
  }
}
