//-----------------PIN D3----------------------------
Bounce2::Button buttonP1_pedal1 = Bounce2::Button();
Bounce2::Button buttonP1_downBank = Bounce2::Button();
void button2 () 
                {
                  //FUNCION PEDALES INDIVIDUALES
                  if (TgSt[0] == 0)  // SI EL ESTADO DE PIN D2 ES ENCENDIDO
                        { 
                           buttonP1_pedal1.update();// Bounce2- Lee el pulsador y actualiza su estado.
                           if (buttonP1_pedal1.pressed())//Bounce2- pressed= Comprueba si hay una transición de alta a baja del pulsador.
                                { 
                                  if      (TgSt[1] == 1){MIDI.sendControlChange(CC[0], ValOn, Ch);   digitalWrite(LED[1], HIGH);TgSt[1] = 0;}
                                  else if (TgSt[1] == 0){MIDI.sendControlChange(CC[0], ValOff, Ch);  digitalWrite(LED[1], LOW); TgSt[1] = 1;}

                                  //if      (TgSt[2] == 0){MIDI.sendControlChange(CC[1], ValOff, Ch);  digitalWrite(LED[2], LOW); TgSt[2] = 1;}//Pedal 1 es OverDrive y Pedal 2 es Distorsion, no pueden encenderse los 2, esta linea mantiene encendido uno solo.
                                }                         
                       }
                
                
                  //FUNCION BANCO-DOWN
                  else { // SI EL ESTADO DE PIN D2 ES APAGADO
                          digitalWrite(LED[1], LOW); //APAGAR LED
                          
                          buttonP1_downBank.update(); 
                          if (buttonP1_downBank.pressed())
                                {
                                  ValBank--; // Decrementa el Valor de Banco
                                  if (ValBank < 0) ValBank = ValBankMax; // Si disminuye por debajo de 0 pasa a 3
                                  LCD(); //Escribe en el LCD solo si se pulsa un pulsador.
                                  digitalWrite(LED[1], HIGH);
                                                        
                                  //LEDs indicadores de BANCO, son 4.
/*OPCION 1*/                    //for (int i = 0; i <= 3; i++) {if (ValBank == i) {digitalWrite(LED[i+7], HIGH); pc=128;}  else {digitalWrite(LED[i+7], LOW);}}//Enciende LEDS Banco de a uno //Apagado y Encendido de LEDs BANCO. Al setear pc = 128 comienzan a parpadear los LED 3 a 6 a la espera de que se opte por un preset y se pase a pc = 0... y deje de parpadear los led.
                                  
/*OPCION 2*/                      if (ValBank == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);pc=128;}//Enciende LEDs Banco en sumatoria
                                  if (ValBank == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);pc=128;}
                                  if (ValBank == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);pc=128;}
                                  if (ValBank == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);pc=128;} 
                                }
                      }
                }
