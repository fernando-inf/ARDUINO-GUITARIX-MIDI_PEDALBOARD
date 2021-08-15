//Futura Expansión
//https://www.programmingelectronics.com/make-one-button-functionality-two-arduino/
//Potenciometro en Pulsador Digital= Al apretar y soltar rápido el Valor de la Variable (Velocity) se incrementa.
                                   //Al apretar 500ms (o mas tiempo) y soltar, el Valor de la Variable decrece.
/*
float tiempo_inicial = 0;
int intervalo1 = 5;
int intervalo2 = 500;        
int Velocity; //El valor inicial se obtiene mediante MIDI Input (señal recibida del Software) al seleccionar un preset.
const int VelocityMax = 127

void PoteButton() 
        {for (int i = 7; i <=12; i++){ //para 6 Pulsadores
                                      while (digitalRead(buttonPin[i]) == LOW ){ delay(50); tiempo_inicial = tiempo_inicial + 50;}
                                    
                                      if (tiempo_inicial >= intervalo2)
                                                {
                                                  Velocity--; if (Velocity < 0) Velocity = 0;//Velocity-=2 para decrementar de a 2 valores // Velocity = 0 cuando llega a 0 el valor se mantiene en 0, no decrece mas.
                                                  MIDI.sendControlChange(CC[i-1], Velocity, Ch);
                                                } 
                                      else if(tiempo_inicial >= intervalo1)
                                                {
                                                  Velocity++; if (Velocity > VelocityMax) Velocity = VelocityMax; //Velocity+=2 para incrementar de a 2 valores //Velocity = VelocityMax cuando llega al maximo el valor se mantiene en ese maximo, no se incrementa mas.
                                                  MIDI.sendControlChange(CC[i-1], Velocity, Ch);
                                                }
                                    tiempo_inicial = 0;
                                   }
        }

*/
