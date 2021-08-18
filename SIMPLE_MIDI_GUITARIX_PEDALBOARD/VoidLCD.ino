//Imprime los Datos en el LCD16x2.
//No debe colocarse "LCD()" en "void loop", si se coloca aqui se imprimen los datos en el LCD en forma intermitente y no es lo correcto.
//"LCD ()" se incerta en cada Void de pulsador para que los cambios en el LCD solo se produzcan al pulsar el mismo.

#include <LiquidCrystal.h> //https://www.arduino.cc/en/Reference/LiquidCrystal
LiquidCrystal lcd(31, 33, 35, 37, 39, 41);//Pines de conexion al LCD- Para Arduino Mega.

void LCD()
            {
              if(TgSt[0] == 0)
                      { lcd.clear(); lcd.setCursor(3, 0); lcd.print("MIDI PEDAL"); lcd.setCursor(0, 1); lcd.print("MODE: INDIVIDUAL");}
              
              if(TgSt[0] == 1)
                      {
                        lcd.clear();
                        lcd.setCursor(1,0);lcd.print("BANK");lcd.setCursor(3,1);lcd.print(ValBank);
                        lcd.setCursor(9,0);lcd.print("PRESET");lcd.setCursor(11,1); if (pc==128){lcd.print("?");}
                                                                                    if (pc==0)  {lcd.print("A");}
                                                                                    if (pc==1)  {lcd.print("B");}
                                                                                    if (pc==2)  {lcd.print("C");}
                                                                                    if (pc==3)  {lcd.print("D");}
                         lcd.setCursor(6,0);lcd.print("|");lcd.setCursor(6,1);lcd.print("|");
                         lcd.setCursor(7,0);lcd.print("|");lcd.setCursor(7,1);lcd.print("|");
                      } 
            }
