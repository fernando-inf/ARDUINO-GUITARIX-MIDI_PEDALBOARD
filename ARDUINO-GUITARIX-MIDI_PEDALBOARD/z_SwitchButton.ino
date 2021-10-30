Bounce2::Button switchButton_0 = Bounce2::Button();  //switchButton_0 = Pulsador 0

void switchButton() {
  switchButton_0.update(); //Bounce2- Lee el pulsador y actualiza su estado.
  if (switchButton_0.pressed()) {  //Bounce2- pressed= Devuelve True si el botón fue presionado físicamente
    tgSt[0]++;
    if (tgSt[0] > tgSt_0_Max) tgSt[0] = 0;  //Incrementa Valor de tgSt[0] de 0 a TgSt_0_Max. Si supera a TgSt_0_Max vuelve a 0
    switchMode();
  }
}
