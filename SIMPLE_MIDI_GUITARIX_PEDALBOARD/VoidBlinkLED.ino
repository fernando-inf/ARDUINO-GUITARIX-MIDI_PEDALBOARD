unsigned long tiempo_inicial = 0;
const long intervalo = 500; //ms
int estado=LOW;

void BlinkLED()
      {
        if (pc == 128)  // si 128 parpadean led 3 a 6, de lo contrario no se activa esta funcion.
              {
                unsigned long tiempo_transcurrido = millis();
                
                if(tiempo_transcurrido - tiempo_inicial >= intervalo)
                    {
                      tiempo_inicial = tiempo_transcurrido; //Reinicia el conteo al tiempo_inicial que es = 0
                      if(estado==LOW){estado=HIGH;} 
                      else           {estado=LOW;}
                    
                      digitalWrite(LED[3], estado);
                      digitalWrite(LED[4], estado);
                      digitalWrite(LED[5], estado);
                      digitalWrite(LED[6], estado);
                    }
              }
      }
