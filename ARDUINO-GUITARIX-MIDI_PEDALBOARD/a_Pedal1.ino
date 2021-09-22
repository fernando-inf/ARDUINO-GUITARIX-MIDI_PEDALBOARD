Bounce2::Button pedal_1 = Bounce2::Button(); //pedal_1 = Pedal 1

void Pedal1() {
  pedal_1.update();
  if (pedal_1.changed()) {
    if ( pedal_1.read() == HIGH ) {

      //CHANGE MODE- Para comentarios adicionales ver pestaña “Void_SwitchButton”
      if ( pedal_1.previousDuration() > 500 ) {
        tgSt[0]++;
        if (tgSt[0] > tgSt_0_Max) tgSt[0] = 0;
        //MODO BANCO
        if (tgSt[0] == 0) {
          digitalWrite(LED[1], LOW);
          
          digitalWrite(LED[0], LOW);
          LCD_OLED();
          LEDBank_Preset();
        }

        //MODO INDIVIDUAL
        else if (tgSt[0] == 1) {
          digitalWrite(LED[1], LOW);

          digitalWrite(LED[0], HIGH);
          LCD_OLED();
#if NO_USE_MIDI_INPUT
          for (byte i = 0; i <= 5; i++) {
            MIDI.sendControlChange(CC[i], valOff, Ch);
            digitalWrite(LED[i + 1], LOW);
            tgSt[i + 1] = 1;
          }

#else
          for (byte i = 0; i <= 5; i++) {
            if (tgStB[i] == 0) {
              digitalWrite(LED[i + 1], HIGH);
              tgSt[i + 1] = 0;
            } else {
              digitalWrite(LED[i + 1], LOW);
              tgSt[i + 1] = 1;
            }
          }
#endif
          for (byte i = 7; i <= 10; i++) {
            digitalWrite(LED[i], LOW);
          }
        }
        //MODO LOOPD
        else if (tgSt[0] == 2) {
          digitalWrite(LED[1], LOW);

          LCD_OLED();
        }
      }

      //NORMAL MODE
      else {
        digitalWrite(LED[1], LOW);

        //MODO BANCO-DOWN
        if (tgSt[0] == 0) {
          valBank--;
          if (valBank < 0) valBank = valBankMax;  // Decrementa el Valor del Banco. Si disminuye por debajo de 0 pasa a valBankMax.
          pc = 128; //Hace parpadear los LEDs de los preset. Ver pestaña "VoidBlinkLED"
          LCD_OLED(); //Escribe en el LCD/OLED.
          LEDBank_Preset(); //LEDs indicadores de BANCO y PRESET. Ver pestaña "VoidLEDBank_Preset"
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
          } else if (tgSt[1] == 0) {
            MIDI.sendControlChange(CC[0], valOff, Ch);
            digitalWrite(LED[1], LOW);
            tgSt[1] = 1;
          }

          //if (tgSt[2] == 0) { //Pedal 1 es OverDrive y Pedal 2 es Distorsión, no pueden encenderse los 2, esta línea mantiene encendido uno solo.
            //MIDI.sendControlChange(CC[1], valOff, Ch);
            //digitalWrite(LED[2], LOW);
            //tgSt[2] = 1;
          //}
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
    }
  }
}
