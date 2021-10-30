unsigned long startTime = 0;
const int INTERVAL_PC = 500;       //ms
const byte INTERVAL_TUNER = 250;  //ms
int INTERVAL_TAP = 600;  //ms = 100 BPM - https://guitargearfinder.com/guides/convert-ms-milliseconds-bpm-beats-per-minute-vice-versa/

void BlinkLEDPC() {
  if (tgSt[0] == 0 && pc == 128) { //Si pc=128 parpadean led 3 a 6, de lo contrario no se activa esta función.
    if (millis() - startTime >= INTERVAL_PC) {
      for (byte i = 3; i <= 6; i++) {
        digitalWrite(LED[i], !digitalRead(LED[i])); //Si el estado de los LEDs es apagado entonces se encienden, si es encendido entonces se apagan.
      }
      startTime = millis();
    }
  }
}

void BlinkLEDLoopD() {
  if (tgSt[0] == 2) {
    if (millis() - startTime >= INTERVAL_TAP) {
      digitalWrite(LED[0], !digitalRead(LED[0]));
      digitalWrite(LED[4], !digitalRead(LED[4]));
      startTime = millis();
    }
  }
}

void BlinkLEDTuner(byte i) {
  if (tgSt[0] == 3) {
    if (millis() - startTime >= INTERVAL_TUNER) {
      digitalWrite(LED[i], !digitalRead(LED[i]));
      startTime = millis();
    }
  }
}

void LED_Presets() {//Este void se inserta en el void de los pedales 3 a 6.
  for (byte i = 0; i <= 3; i++) { //Enciende el LED del preset seleccionado (Pedal pulsado) y apaga los demás.
    if (pc == i) {
      digitalWrite(LED[i + 3], HIGH);
      pc = i;
    } else if (pc != i) {
      digitalWrite(LED[i + 3], LOW);
    }
  }
}

void LEDs_Off() { //Apaga todos los LEDs al pasar de un MODO a otro. Se inserta en el void encargado del cambio de MODO "v_SwitchMode".
  for (byte i = 0; i <= 6; i++) {
    digitalWrite(LED[i], LOW);
  }
}
