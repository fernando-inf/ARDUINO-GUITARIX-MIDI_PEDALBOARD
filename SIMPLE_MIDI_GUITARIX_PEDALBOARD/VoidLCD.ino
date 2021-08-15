//Imprime los Datos en el LCD16x2. 
//No debe colocarse "LCD()" en "void loop", si se coloca aqui se imprimen los datos en el LCD en forma intermitente y no es lo correcto.
//"LCD ()" se incerta en cada Void de pulsador para que los cambios en el LCD solo se produzcan al pulsar el mismo.

#include <LiquidCrystal.h> //LCD 16x2- SOLO ARDUINO MEGA
LiquidCrystal lcd(31, 33, 35, 37, 39, 41);//Pines de conexion al LCD- SOLO ARDUINO MEGA

void LCD()
            {
              lcd.clear();
              lcd.setCursor(1,0);lcd.print("BANK");lcd.setCursor(3,1);lcd.print(BankMSB_LSB);
              lcd.setCursor(9,0);lcd.print("PRESET");lcd.setCursor(11,1); if (pc==128){lcd.print("?");}
                                                                          if (pc==0)  {lcd.print("A");}
                                                                          if (pc==1)  {lcd.print("B");}
                                                                          if (pc==2)  {lcd.print("C");}
                                                                          if (pc==3)  {lcd.print("D");}
               lcd.setCursor(6,0);lcd.print("|");lcd.setCursor(6,1);lcd.print("|");
               lcd.setCursor(7,0);lcd.print("|");lcd.setCursor(7,1);lcd.print("|"); 
            }
