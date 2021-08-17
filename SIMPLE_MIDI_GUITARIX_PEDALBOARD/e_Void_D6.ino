//-----------------PIN D6----------------------------
Bounce2::Button buttonP4_pedal4 = Bounce2::Button();

void button5 () 
                {
                  //FUNCION PEDALES INDIVIDUALES
                  if (TgSt[0] == 0)  // SI EL ESTADO DE PIN D2 ES ENCENDIDO
                        { 
                           buttonP4_pedal4.update(); // Bounce- Lee el botón y actualiza su estado. Esta función update () debe ser llamado regularmente, por lo que la entrada en el pin se reconoce correctamente. La devolución es verdadera si la entrada cambia, o false de lo contrario. 
                           if (buttonP4_pedal4.fallingEdge())//Bounce- fallingEdge= Comprueba si hay una transición de alta a baja del pulsador.
                                { 
                                  if      (TgSt[4] == 1){MIDI.sendControlChange(CC[3], ValOn, Ch);   digitalWrite(LED[4], HIGH);TgSt[4] = 0;}
                                  else if (TgSt[4] == 0){MIDI.sendControlChange(CC[3], ValOff, Ch);  digitalWrite(LED[4], LOW); TgSt[4] = 1;}
                                }                         
                       }

                  //FUNCION PRESET/PROGRAMA
                  else { // SI EL ESTADO DE PIN D3 ES APAGADO
                           buttonP4_pedal4.update(); // Bounce- Lee el botón y actualiza su estado. Esta función update () debe ser llamado regularmente, por lo que la entrada en el pin se reconoce correctamente. La devolución es verdadera si la entrada cambia, o false de lo contrario. 
                           if (buttonP4_pedal4.fallingEdge())//Bounce- fallingEdge= Comprueba si hay una transición de alta a baja del pulsador.
                                {
                                  pc = 1;
                                  MIDI.sendControlChange(MSB_LSB, byte(BankMSB_LSB), Ch); //MIDI.sendControlChange(cc, valor, ch); CC=0 es MSB, CC=32 es LSB.
                                  MIDI.sendProgramChange(byte(pc), Ch);
                                  LCD(); //Escribe en el LCD solo si se pulsa un pulsador.
                                  digitalWrite(LED[4], HIGH);//ENCENDER LED
                                  digitalWrite(LED[3], LOW); //APAGAR LED DE LOS OTROS PEDALES
                                  digitalWrite(LED[5], LOW); //APAGAR LED DE LOS OTROS PEDALES
                                  digitalWrite(LED[6], LOW); //APAGAR LED DE LOS OTROS PEDALES
                            
                                  //LEDs indicadores de BANCO, son 4.
/*OPCION 1*/                    //for (int i = 0; i <= 3; i++) {if (BankMSB_LSB == i) {digitalWrite(LED[i+7], HIGH);}  else {digitalWrite(LED[i+7], LOW);}}//Enciende LEDS Banco de a uno //Apaga LED cuando se esta en otro banco distinto al i
         
/*OPCION 2*/                      if (BankMSB_LSB == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}//Enciende LEDs Banco en sumatoria
                                  if (BankMSB_LSB == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}
                                  if (BankMSB_LSB == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);}
                                  if (BankMSB_LSB == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);}
                                }
                      }
              }
