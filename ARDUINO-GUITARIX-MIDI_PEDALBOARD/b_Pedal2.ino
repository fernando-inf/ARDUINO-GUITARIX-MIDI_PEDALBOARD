Bounce2::Button pedal_2 = Bounce2::Button();

void Pedal2() {
  pedal_2.update();

  //MODO BANCO-UP
  if (tgSt[0] == 0) {
    if (pedal_2.pressed()) {
      valBank++;
      if (valBank > valBankMax) valBank = 0; //Incrementa el Valor de Banco. Si supera por encima del valor asignado a valBankMax pasa a 0
      pc = 128;
      LCD_OLED();
      LEDBank_Preset();
    }
    if (pedal_2.isPressed()) { //En MODO BANCO el LED del Pedal 1 se enciende al pulsarlo y apaga al soltarlo
      digitalWrite(LED[2], HIGH);
    } else {
      digitalWrite(LED[2], LOW);
    }
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (pedal_2.pressed()) {
      if (tgSt[2] == 1) {
        MIDI.sendControlChange(CC[1], valOn, Ch);
        digitalWrite(LED[2], HIGH);
        tgSt[2] = 0;
      } else if (tgSt[2] == 0) {
        MIDI.sendControlChange(CC[1], valOff, Ch);
        digitalWrite(LED[2], LOW);
        tgSt[2] = 1;
      }

      if (tgSt[1] == 0) { //Pedal 1 es OverDrive y Pedal 2 es Distorsion, no pueden encenderse los 2, esta linea mantiene encendido uno solo.
        MIDI.sendControlChange(CC[0], valOff, Ch);
        digitalWrite(LED[1], LOW);
        tgSt[1] = 1;
      }
    }
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    if (pedal_2.pressed()) {
      valPCLoopD++;//Incrementa el Valor del Preset
      if (valPCLoopD > valPCLoopDMax) valPCLoopD = 0;
      LCD_OLED();
      MIDI.sendProgramChange(valPCLoopD, ChLoopD);
    }
    if (pedal_2.isPressed()) {
      digitalWrite(LED[2], HIGH);
    } else {
      digitalWrite(LED[2], LOW);
    }
  }
}
