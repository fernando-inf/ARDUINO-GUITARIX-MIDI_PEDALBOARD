#if NO_USE_MIDI_INPUT
#else
void Tuner (byte channel, byte note, byte velocity) { //MIDI.setHandleNoteOn() - ver void setup()
  if (tgSt[0] == 3) {
    //*************LEDs*********************
    if (velocity >= 0 && velocity <= 20) {
      BlinkLEDTuner(1);
    } else {
      digitalWrite(LED[1], LOW);
    }
    if (velocity >= 21 && velocity <= 40) {
      BlinkLEDTuner(2);
    } else {
      digitalWrite(LED[2], LOW);
    }
    if (velocity >= 41 && velocity <= 61) {
      BlinkLEDTuner(3);
    } else {
      digitalWrite(LED[3], LOW);
    }


    if (velocity >= 62 && velocity <= 64) { //Tuned String
      digitalWrite(LED[0], HIGH);
    } else {
      digitalWrite(LED[0], LOW);
    }


    if (velocity >= 65 && velocity <= 86) {
      BlinkLEDTuner(4);
    } else {
      digitalWrite(LED[4], LOW);
    }
    if (velocity >= 87 && velocity <= 106) {
      BlinkLEDTuner(5);
    } else {
      digitalWrite(LED[5], LOW);
    }
    if (velocity >= 107 && velocity <= 127) {
      BlinkLEDTuner(6);
    } else {
      digitalWrite(LED[6], LOW);
    }
    //*************Display******************
    for (byte i = 0; i <= 11; i++) {
      if ( //Note C = i = 0, C# = i = 1, D = i = 2...
        note == i + 12 * 0 ||
        note == i + 12 * 1 ||
        note == i + 12 * 2 ||
        note == i + 12 * 3 ||
        note == i + 12 * 4 ||
        note == i + 12 * 5 ||
        note == i + 12 * 6 ||
        note == i + 12 * 7 ||
        note == i + 12 * 8 ||
        note == i + 12 * 9 ||
        note == i + 12 * 10
      ) {
        tunerNote = i;
        LCD_OLED();  //Escribe en el LCD/OLED.
      }
    }
  }
}

/*void TunerCC (byte channel, byte number, byte value) { //Ver en v_MIDI_Input
  if (tgSt[0] == 3) {
    if (number == CCtuner[0] && value == 0) {
      tunerNote = 12;
      LCD_OLED();
      for (byte i = 0; i <= 6; i++) {
        digitalWrite(LED[i], LOW);
      }
    }
  }
}*/
#endif
