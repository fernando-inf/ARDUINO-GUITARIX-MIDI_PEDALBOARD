
void voidPedal1() {
  //MODO BANCO-DOWN
  if (tgSt[0] == 0) {
    valBank--;
    if (valBank < 0) valBank = valBankMax;  // Decrementa el Valor del Banco. Si disminuye por debajo de 0 pasa a valBankMax.
    pc = 128; //Hace parpadear los LEDs de los preset. Ver pestaña "VoidBlinkLED"
    LCD_OLED(); //Escribe en el LCD/OLED.
    LED_Presets(); //LEDs indicadores de BANCO y PRESET. Ver pestaña "VoidLED_Presets"
    digitalWrite(LED[1], HIGH);
    delay(100);
    digitalWrite(LED[1], LOW);
  }

  //MODO INDIVIDUAL
  else if (tgSt[0] == 1) {
    if (tgSt[1] == 1) {
      MIDI.sendControlChange(CC[0], valOn, Ch);
      digitalWrite(LED[1], HIGH);
      tgSt[1] = 0;
      tgStB[0] = 0;
    } else if (tgSt[1] == 0) {
      MIDI.sendControlChange(CC[0], valOff, Ch);
      digitalWrite(LED[1], LOW);
      tgSt[1] = 1;
      tgStB[0] = 1;
    }

#if SWITCHING_PEDAL_1_2
    if (tgSt[2] == 0) { //Pedal 1 es OverDrive y Pedal 2 es Distorsión, no pueden encenderse los 2, esta línea mantiene encendido uno solo.
      MIDI.sendControlChange(CC[1], valOff, Ch);
      digitalWrite(LED[2], LOW);
      tgSt[2] = 1;
      tgStB[1] = 1;
    }
#endif
  }

  //MODO LOOPD
  else if (tgSt[0] == 2) {
    valPCLoopD--; //Decrementa el Valor del preset
    if (valPCLoopD < 0) valPCLoopD = valPCLoopDMax;
    LCD_OLED();
    MIDI.sendProgramChange(valPCLoopD, ChLoopD);
    digitalWrite(LED[1], HIGH);
    delay(100);
    digitalWrite(LED[1], LOW);
  }
}
