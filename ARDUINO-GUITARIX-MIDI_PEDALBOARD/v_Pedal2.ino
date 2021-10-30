
void voidPedal2() {
  //MODO BANCO-UP
  if (tgSt[0] == 0) {
    valBank++;
    if (valBank > valBankMax) valBank = 0; //Incrementa el Valor de Banco. Si supera por encima del valor asignado a valBankMax pasa a 0.
    pc = 128;
    LCD_OLED();
    LED_Presets();
    digitalWrite(LED[2], HIGH);
    delay(100);
    digitalWrite(LED[2], LOW);
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[2] == 1) {
      MIDI.sendControlChange(CC[1], valOn, Ch);
      digitalWrite(LED[2], HIGH);
      tgSt[2] = 0;
      tgStB[1] = 0;
    } else if (tgSt[2] == 0) {
      MIDI.sendControlChange(CC[1], valOff, Ch);
      digitalWrite(LED[2], LOW);
      tgSt[2] = 1;
      tgStB[1] = 1;
    }

#if SWITCHING_PEDAL_1_2
    if (tgSt[1] == 0) { //Pedal 1 es OverDrive y Pedal 2 es Distorsión, no pueden encenderse los 2, esta linea mantiene encendido uno solo.
      MIDI.sendControlChange(CC[0], valOff, Ch);
      digitalWrite(LED[1], LOW);
      tgSt[1] = 1;
      tgStB[0] = 1;
    }
#endif
  }


  //MODO LOOPD
  else if (tgSt[0] == 2) {
    valPCLoopD++;//Incrementa el Valor del Preset
    if (valPCLoopD > valPCLoopDMax) valPCLoopD = 0;
    LCD_OLED();
    MIDI.sendProgramChange(valPCLoopD, ChLoopD);
    digitalWrite(LED[2], HIGH);
    delay(100);
    digitalWrite(LED[2], LOW);

  }
}
