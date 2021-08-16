//-----------------PIN D2----------------------------CAMBIA MODO DE INDIVIDUAL A BANCO
void button1 () 
      {
          buttonState1 = digitalRead(buttonPin[0]);
          
          //MODO INDIVIDUAL
          if (buttonState1 != lastButtonState1 && buttonState1 == 1 && TgSt[0] == 1) 
                       {
                          TgSt[0] = 0;
                          digitalWrite(LED[0], HIGH); //ENCENDER Primer LED = Indica encendido de MODO INDIVIDUAL  
                          lcd.clear(); lcd.setCursor(3, 0); lcd.print("MIDI PEDAL"); lcd.setCursor(0, 1); lcd.print("MODE: INDIVIDUAL");//En caso de usar LCD 16x2
                          
                          //Cambia el estado de TgStB (TgSt solo para MODO Banco), su objetivo es encender o apagar los LED cuando se pasa del MODO BANCO al MODO INDIVIDUAL, mostrando asi el estado de los pedales en el MODO INDIVIDUAL provocado cuando se estaba en el MODO BANCO, para esto se usa otros TgSt denominados "TgStB"
                          for (int i = 0; i <=5; i++){if (TgStB[i] == 0) {digitalWrite(LED[i+1], HIGH);TgSt[i+1] = 0;} else {digitalWrite(LED[i+1], LOW);TgSt[i+1] = 1;}}

/*PEDAL sin MIDIInput*/ //for (int i = 0; i <=5; i++){MIDI.sendControlChange(CC[i], ValOff, Ch);  digitalWrite(LED[i+1], LOW); TgSt[i+1] = 1;} //Habilite esta Linea si no usa MIDIInput/ Apaga todos los pedales al pasar al MODO INDIVIDUAL, esto evita confuciones al pasar de un banco a otro y volver al MODO INDIVIDUAL, indicando al usuario en forma directa que todos los pedales estan apagados. Asi queda en evidencia que el MODO BANCO y el INDIVIDUAL solo son totalmente compatibles/viables si se tiene MIDIInput y Output juntos.
                      }
          
        
          //MODO BANCO
          else if (buttonState1 != lastButtonState1 && buttonState1 == 1 && TgSt[0] == 0) 
                      {
                          TgSt[0] = 1;
                          digitalWrite(LED[0], LOW); //APAGAR Primer LED = Indica encendido de MODO BANCO
                          LCD(); //Escribe en el LCD solo si se pulsa un pulsador.
                          if                                    (pc == 128)  {}//ver VoidBlinkLED();
                          else {for (int i = 0; i <=3; i++) {if (pc == i)    {digitalWrite(LED[i+3], HIGH);} else {digitalWrite(LED[i+3], LOW);}}} //Enciende y Apaga los LED de los preset al pasar al MODO BANCO segun el estado de "pc"

/*OPCION 1*/            //for (int i = 0; i <=3; i++){if (BankMSB_LSB == i) {digitalWrite(LED[i+7], HIGH);} else {digitalWrite(LED[i+7], LOW);}} ////Enciende LEDS Banco de a uno //Prende o apaga los LED de los Bancos segun haya quedado el estado de BankMSB_LSB. Tanto MIDI OUT como MIDI IN cambian el estado de BankMSB_LSB.
                          
/*OPCION 2*/              if (BankMSB_LSB == 0) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], LOW);  digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}//Enciende LEDs Banco en sumatoria
                          if (BankMSB_LSB == 1) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], LOW);  digitalWrite(LED[10], LOW);}
                          if (BankMSB_LSB == 2) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], LOW);}
                          if (BankMSB_LSB == 3) {digitalWrite(LED[7], HIGH); digitalWrite(LED[8], HIGH); digitalWrite(LED[9], HIGH); digitalWrite(LED[10], HIGH);}
                          
                     }
          lastButtonState1 = buttonState1;
          delay(DelayPulsadores);
      }
