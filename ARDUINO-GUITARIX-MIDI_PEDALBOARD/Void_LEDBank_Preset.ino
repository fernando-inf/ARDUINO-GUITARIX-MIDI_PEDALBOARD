//Este void se inserta en el void de cada pulsador.
void LEDBank_Preset() {
#if USE_LEDs
  /*BANK OPCIÓN 1*/
  /*for (byte i = 0; i <= 3; i++) { //Enciende LEDS Banco de a uno. Prende o apaga los LED de los Bancos según haya quedado el estado de valBank. Tanto MIDI OUT como MIDI IN cambian el estado de valBank.
    if (valBank == i) {
      digitalWrite(LED[i + 7], HIGH);
    } else {
      digitalWrite(LED[i + 7], LOW);
    }
    }*/
  /*BANK OPCIÓN 2*/
  if (valBank == 0) { //Enciende LEDs Banco en sumatoria
    digitalWrite(LED[7], HIGH);
    digitalWrite(LED[8], LOW);
    digitalWrite(LED[9], LOW);
    digitalWrite(LED[10], LOW);
  }
  if (valBank == 1) {
    digitalWrite(LED[7], HIGH);
    digitalWrite(LED[8], HIGH);
    digitalWrite(LED[9], LOW);
    digitalWrite(LED[10], LOW);
  }
  if (valBank == 2) {
    digitalWrite(LED[7], HIGH);
    digitalWrite(LED[8], HIGH);
    digitalWrite(LED[9], HIGH);
    digitalWrite(LED[10], LOW);
  }
  if (valBank == 3) {
    digitalWrite(LED[7], HIGH);
    digitalWrite(LED[8], HIGH);
    digitalWrite(LED[9], HIGH);
    digitalWrite(LED[10], HIGH);
  }
#endif

  /*PRESET*/
  for (byte i = 0; i <= 3; i++) { //Enciende el LED del preset seleccionado (Pedal pulsado) y apaga los demás.
    if (pc == i) {
      digitalWrite(LED[i + 3], HIGH);
      pc = i;
    } else if (pc != i) {
      digitalWrite(LED[i + 3], LOW);
    }
  }
}
