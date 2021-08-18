//-----------------PIN D6----------------------------
Bounce2::Button buttonP4_pedal4 = Bounce2::Button();

void button5 () 
                {
                  //FUNCION PEDALES INDIVIDUALES
                  if (TgSt[0] == 0)  // SI EL ESTADO DE PIN D2 ES ENCENDIDO
                        { 
                           buttonP4_pedal4.update();
                           if (buttonP4_pedal4.pressed())
                                { 
                                  if      (TgSt[4] == 1){MIDI.sendControlChange(CC[3], ValOn, Ch);   digitalWrite(LED[4], HIGH);TgSt[4] = 0;}
                                  else if (TgSt[4] == 0){MIDI.sendControlChange(CC[3], ValOff, Ch);  digitalWrite(LED[4], LOW); TgSt[4] = 1;}
                                }                         
                       }

                  //FUNCION PRESET/PROGRAMA
                  else { // SI EL ESTADO DE PIN D3 ES APAGADO
                           buttonP4_pedal4.update(); 
                           if (buttonP4_pedal4.pressed())
                                {
                                  pc = 1;
                                  MIDI.sendControlChange(CCBank, ValBank, Ch); //MIDI.sendControlChange(cc, valor, ch); CC=0 es MSB, CC=32 es LSB.
                                  MIDI.sendProgramChange(pc, Ch);
                                  LCD(); //Escribe en el LCD solo si se pulsa un pulsador.
                                  digitalWrite(LED[4], HIGH);//ENCENDER LED
                                  digitalWrite(LED[3], LOW); //APAGAR LED DE LOS OTROS PEDALES
                                  digitalWrite(LED[5], LOW); //APAGAR LED DE LOS OTROS PEDALES
                                  digitalWrite(LED[6], LOW); //APAGAR LED DE LOS OTROS PEDALES
                            
                                  //LEDs indicadores de BANCO, son 4.
/*OPCION 1*/                    //for (int i = 0; i <= 3; i++) {if (ValBank == i) {digitalWrite(LED[i+7], HIGH);}  else {digitalWrite(LED[i+7], LOW);}}//Enciende LEDS Banco de a uno //Apaga LED cuando se esta en otro banco distinto al i
         
/*OPCION 2*/                      if (ValBank == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}//Enciende LEDs Banco en sumatoria
                                  if (ValBank == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}
                                  if (ValBank == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);}
                                  if (ValBank == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);}
                                }
                      }
              }
