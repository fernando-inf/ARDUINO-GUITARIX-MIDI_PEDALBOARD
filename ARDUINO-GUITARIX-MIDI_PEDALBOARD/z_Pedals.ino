const int INTERVAL_CHANGE = 700; //ms

Bounce2::Button pedal_1 = Bounce2::Button(); //pedal_1 = Pedal 1
void Pedal1() {
  pedal_1.update();
  if (pedal_1.changed()) {
    if ( pedal_1.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_1.previousDuration() > INTERVAL_CHANGE) {
        tgSt[0] = 0; //MODO BANCO
        switchMode();
      }

      //NORMAL MODE
      else {
        voidPedal1();
      }
    }
  }
}

Bounce2::Button pedal_2 = Bounce2::Button();
void Pedal2() {
  pedal_2.update();
  if (pedal_2.changed()) {
    if ( pedal_2.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_2.previousDuration() > INTERVAL_CHANGE ) {
        tgSt[0] = 1; //MODO INDIVIDUAL
        switchMode();
      }

      //NORMAL MODE
      else {
        voidPedal2();
      }
    }
  }
}

Bounce2::Button pedal_3 = Bounce2::Button();
void Pedal3() {
  pedal_3.update();
  if (pedal_3.changed()) {
    if ( pedal_3.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_3.previousDuration() > INTERVAL_CHANGE ) {
        tgSt[0] = 2; //MODO LOOP/DRUM
        switchMode();
      }

      //NORMAL MODE
      else {
        voidPedal3();
      }
    }
  }
}

Bounce2::Button pedal_4 = Bounce2::Button();
void Pedal4() {
  pedal_4.update();
  if (pedal_4.changed()) {
    if ( pedal_4.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_4.previousDuration() > INTERVAL_CHANGE ) {
        tgSt[0] = 3; //MODO TUNER
        switchMode();
      }

      //NORMAL MODE
      else {
        voidPedal4();
      }
    }
  }
}

Bounce2::Button pedal_5 = Bounce2::Button();
void Pedal5() {
  pedal_5.update();
  if (pedal_5.changed()) {
    if ( pedal_5.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_5.previousDuration() > INTERVAL_CHANGE ) {
        voidPedal5();
      }

      //NORMAL MODE
      else {
        voidPedal5();
      }
    }
  }
}

Bounce2::Button pedal_6 = Bounce2::Button();
void Pedal6() {
  pedal_6.update();
  if (pedal_6.changed()) {
    if ( pedal_6.read() == HIGH ) {

      //SWITCH MODE- Para comentarios adicionales ver pestaña “v_SwitchMode”
      if ( pedal_6.previousDuration() > INTERVAL_CHANGE ) {
        voidPedal6();
      }

      //NORMAL MODE
      else {
        voidPedal6();
      }
    }
  }
}
