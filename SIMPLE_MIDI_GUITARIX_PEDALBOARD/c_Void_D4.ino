//-----------------PIN D4----------------------------
Bounce2::Button buttonP2_pedal2 = Bounce2::Button();
Bounce2::Button buttonP2_upBank = Bounce2::Button();
void button3 () 
                {
                  //FUNCION PEDALES INDIVIDUALES
                  if (TgSt[0] == 0)  // SI EL ESTADO DE PIN D2 ES ENCENDIDO
                        { 
                           buttonP2_pedal2.update(); // Bounce- Lee el botón y actualiza su estado. Esta función update () debe ser llamado regularmente, por lo que la entrada en el pin se reconoce correctamente. La devolución es verdadera si la entrada cambia, o false de lo contrario. 
                           if (buttonP2_pedal2.fallingEdge())//Bounce- fallingEdge= Comprueba si hay una transición de alta a baja del pulsador.
                                { 
                                  if      (TgSt[2] == 1){MIDI.sendControlChange(CC[1], ValOn, Ch);   digitalWrite(LED[2], HIGH);TgSt[2] = 0;}
                                  else if (TgSt[2] == 0){MIDI.sendControlChange(CC[1], ValOff, Ch);  digitalWrite(LED[2], LOW); TgSt[2] = 1;}

                                  //if      (TgSt[1] == 0){MIDI.sendControlChange(CC[0], ValOff, Ch);  digitalWrite(LED[1], LOW); TgSt[1] = 1;}//Pedal 1 es OverDrive y Pedal 2 es Distorsion, no pueden encenderse los 2, esta linea mantiene encendido uno solo.
                                }                         
                       }
                
                
                  //FUNCION BANCO-UP
                  else { // SI EL ESTADO DE PIN D2 ES APAGADO
                          digitalWrite(LED[2], LOW); //APAGAR LED
                          
                          buttonP2_upBank.update(); // Bounce- Lee el botón y actualiza su estado. Esta función update () debe ser llamada regularmente, por lo que la entrada en el pin se reconoce correctamente. La devolución es verdadera si la entrada cambia, o falsa de lo contrario. 
                          if (buttonP2_upBank.fallingEdge()) //Bounce- fallingEdge= Comprueba si hay una transición de alta a baja del pulsador. 
                                {
                                  BankMSB_LSB++; // Incrementa el cambio de Banco
                                  if (BankMSB_LSB > BankMax) BankMSB_LSB = 0; // Si supera por encima de 3 pasa a 0
                                  LCD(); //Escribe en el LCD solo si se pulsa un pulsador.
                                  digitalWrite(LED[2], HIGH);
                                                        
                                  //LEDs indicadores de BANCO, son 4. LED 7 al 10
/*OPCION 1*/                    //for (int i = 0; i <= 3; i++) {if (BankMSB_LSB == i) {digitalWrite(LED[i+7], HIGH); pc=128;}  else {digitalWrite(LED[i+7], LOW);}} //Enciende LEDS Banco de a uno //Apagado y Encendido de LEDs BANCO. Al setear pc = 128 comienzan a parpadear los LED 3 a 6 a la espera de que se opte por un preset y se pase a pc = 0... y deje de parpadear los led.
                                  
/*OPCION 2*/                      if (BankMSB_LSB == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);pc=128;}//Enciende LEDs Banco en sumatoria
                                  if (BankMSB_LSB == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);pc=128;}
                                  if (BankMSB_LSB == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);pc=128;}
                                  if (BankMSB_LSB == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);pc=128;}                                
                                }
                      }
                }
