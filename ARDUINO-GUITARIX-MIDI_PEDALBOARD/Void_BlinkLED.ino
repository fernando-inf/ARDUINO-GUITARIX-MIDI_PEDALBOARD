unsigned long startTime = 0;
const int INTERVAL_PC = 500;       //ms
const int INTERVAL_LOOPD = 250;  //ms

void BlinkLEDPC() {
  if (pc == 128) { // si pc=128 parpadean led 3 a 6, de lo contrario no se activa esta funcion.
    if (millis() - startTime >= INTERVAL_PC) {
      digitalWrite(LED[3], !digitalRead(LED[3])); //Si el estado de los LEDs es APAGADO entonces se ENCIENDEN, si es ENCENDIDO entonces se apagan.
      digitalWrite(LED[4], !digitalRead(LED[4]));
      digitalWrite(LED[5], !digitalRead(LED[5]));
      digitalWrite(LED[6], !digitalRead(LED[6]));
      startTime = millis(); //Reinicia el conteo al tiempo_inicial que es = 0
    }
  }
}

void BlinkLEDLoopD() {
  if (tgSt[0] == 2) {
    if (millis() - startTime >= INTERVAL_LOOPD) {
      digitalWrite(LED[0], !digitalRead(LED[0]));
      startTime = millis();
    }
  }
}
