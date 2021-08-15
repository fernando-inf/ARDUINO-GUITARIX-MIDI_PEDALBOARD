void MIDI_Input_CC(byte channel, byte number, byte value) //Revisar Channel, podria traer problemas si se recibe mensajes MIDI de otro Canal distinto al Canal 1.

            //MODO INDIVIDUAL: Recibe mensajes MIDI ControlChange de la PC y enciende y apaga LED de los pedales 1 al 6
                { 
                  if (TgSt[0] == 0)
                            {for (int i = 0; i <=5; i++) {if (number == CC[i]){if(value == ValOn  && TgSt[i+1] == 1) {digitalWrite(LED[i+1], HIGH);TgSt[i+1] = 0;} 
                                                                               if(value == ValOff && TgSt[i+1] == 0) {digitalWrite(LED[i+1], LOW);TgSt[i+1] = 1;}
                                                                              }
                                                          }
                            }
            
                  for (int i = 0; i <=5; i++) {if (number == CC[i]) {if(value == ValOn) {TgStB[i] = 0;} if(value == ValOff) {TgStB[i] = 1;}}}//Cambia el estado de TgStB (TgSt solo para MODO Banco), su objetivo es encender o apagar los LED cuando se pasa del MODO BANCO al MODO INDIVIDUAL, mostrando asi el estado de los pedales en el MODO INDIVIDUAL provocado cuando se estaba en el MODO BANCO, para esto se usa otros TgSt denominados "TgStB"
                                                                                                                                             //Si usted esta usando una pedalera con 12 pedales, 6 para MODO BANCO y 6 para MODO INDIVIDUAL debe eliminar esta parte del codigo o comentarla (debera eliminar otras partes tambien).
            
                  if (TgSt[0] == 0 && number == 32 || number == 0) {for (int i = 0; i <=3; i++){if(value == i ) {BankMSB_LSB = i;}}}//Estando la pedalera en MODO INDIVIDUAL, obtiene el estado controlChange (CC32 o CC0) para cuando se pase al MODO BANCO se refleje en los led- VER VoidButton2
            
            
            
            //MODO BANCO: Recibe mensajes MIDI ControlChange de la PC y enciende y apaga LED de cada Banco segun se elija en el software
                 
/*OPCION 1*/    /*if (TgSt[0] == 1 && number == 32 || number == 0) {for (int i = 0; i <=3; i++) {if(value == i) {digitalWrite(LED[i+7], HIGH);}//Enciende LEDS Banco de a uno
                                                                                                 if(value != i) {digitalWrite(LED[i+7], LOW);}
                                                                                                }
                                                                   }*/
/*OPCION 2*/      if (TgSt[0] == 1 && number == 32 || number == 0) {if (value == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}//Enciende LEDs Banco en sumatoria
                                                                    if (value == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}
                                                                    if (value == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);}
                                                                    if (value == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);}
                                                                   }
                }

void MIDI_Input_ProgramChange(byte channel, byte number)
              {
                  
            //MODO BANCO: Recibe mensajes MIDI ProgramChange de la PC y enciende y apaga LED de cada Preset segun se elija en el software, a la vez cambia el estado de la variable "pc", este cambio sirve para el parpadeo de LED, si "pc" distinto de 128 no parpadean ya que se ha elejido un preset/programa.
                  
                  if (TgSt[0] == 1) {for (int i = 0; i <=3; i++){if (number == i)  {digitalWrite(LED[i+3], HIGH); pc=i;} else if (number != i) {digitalWrite(LED[i+3], LOW);}}}
                        
                  if (TgSt[0] == 0) {for (int i = 0; i <=3; i++){if (number == i){pc=i;}}}//Estando la pedalera en MODO INDIVIDUAL, obtiene el estado programChange (Variable "pc") para cuando se pase al MODO BANCO se refleje en los led- VER VoidButton2
            
              }
                
    
