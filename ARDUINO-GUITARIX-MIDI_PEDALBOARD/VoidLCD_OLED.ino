//Imprime los Datos en el LCD o OLED.
//No debe colocarse "LCD_OLED();" en "void Loop", si se coloca ahí se imprimen los datos en el LCD en forma intermitente y no es lo correcto.
//"LCD_OLED()" se inserta en cada “void” de pulsador para que los cambios en el LCD solo se produzcan al pulsar el mismo.

#if USE_LCD
#include <LiquidCrystal.h> //https://www.arduino.cc/en/Reference/LiquidCrystal
LiquidCrystal lcd(31, 33, 35, 37, 39, 41); //Pines de conexión al LCD- Para Arduino Mega.

#elif USE_LCDI2C
#include <Wire.h> //I2C
#include <LiquidCrystal_I2C.h> //Conecte la pantalla a los pines SDA y SCL de su Placa. https://github.com/johnrickman/LiquidCrystal_I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); //(I2C-Dirección, columnas, líneas)- Si no inicia con la Dirección  0x27 pruebe con  0x3F o lea esto https://playground.arduino.cc/Main/I2cScanner/  https://forum.arduino.cc/t/solucionado-problema-con-lcd-16x2-con-i2c/380309

#elif USE_OLED //OLED SSD1306 I2C (128X64)- CONECTAR A PINES SDA Y SCL DE SU PLACA.
//#include <Arduino.h>
#include <U8g2lib.h> //https://github.com/olikraus/u8g2
#include <Wire.h>  //I2C
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE); //De no funcionar, cambiar esta línea por el modelo de su placa (ver más abajo)

#elif USE_7SEGMENTS_16bits
const int DATA = 16; // A2
const int CLOCK = 17;// A3
const int ENABLE = 18;//A4- STC para 74HC595

byte numRight[] = { B10110111, B00100100, B01110011, B01110110, B11100100, B11010110, B11010111, B10110100, B11110111, B11110110, B00000000};
//                 {....0....,.....1....,.....2....,.....3....,....4.....,....5.....,.....6....,.....7....,.....8....,.....9...., oFF}
//B-f-g-b-a-dp-c-d-e / Digit Right- 0 =LED Off

byte numLeft[] = { B11101101, B00100100, B11001110, B01101110, B00100111, B01101011, B11101011, B00101101, B11101111, B01101111, B00000000 };
//{....0....,.....1....,.....2....,.....3....,....4.....,....5.....,.....6....,.....7....,.....8....,.....9...., OFF}
//B-e-d-c-dp-a-b-g-f / Digit Left

void displayNum(int x, int i) {//displayNum(digitLeft, valBank-)

  digitalWrite(ENABLE, HIGH);
  shiftOut(DATA, CLOCK, LSBFIRST, numRight[i]);
  shiftOut(DATA, CLOCK, MSBFIRST, numLeft[x]);
  digitalWrite(ENABLE, LOW);
}

#endif


void LCD_OLED() {
  //LCD 16x2 sin I2C
#if USE_LCD || USE_LCDI2C
  if (tgSt[0] == 0) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("BANK");

    if (valBank >= 0 && valBank <= 9) {
      lcd.setCursor(4, 1);
    }
    if (valBank >= 10 && valBank <= 99) {
      lcd.setCursor(3, 1);
    }
    if (valBank >= 100 && valBank <= 999) {
      lcd.setCursor(2, 1);
    }
    lcd.print(valBank);

    lcd.setCursor(9, 0);
    lcd.print("PRESET");
    lcd.setCursor(11, 1);
    if (pc == 128) {
      lcd.print("?");
    }
    if (pc == 0) {
      lcd.print("A");
    }
    if (pc == 1) {
      lcd.print("B");
    }
    if (pc == 2) {
      lcd.print("C");
    }
    if (pc == 3) {
      lcd.print("D");
    }
    lcd.setCursor(6, 0);
    lcd.print("|");
    lcd.setCursor(6, 1);
    lcd.print("|");
    lcd.setCursor(7, 0);
    lcd.print("|");
    lcd.setCursor(7, 1);
    lcd.print("|");
  }
  if (tgSt[0] == 1) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("MIDI PEDAL");
    lcd.setCursor(0, 1);
    lcd.print("MODE: INDIVIDUAL");
  }

  if (tgSt[0] == 2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PATTERN");
    lcd.setCursor(3, 1);
    if (valPCLoopD >= 0 && valPCLoopD <= 9) {
      lcd.print(valPCLoopD);
    }
    if (valPCLoopD >= 10 && valPCLoopD <= 19) {
      lcd.print(valPCLoopD - 10);
    }
    if (valPCLoopD >= 20 && valPCLoopD <= 29) {
      lcd.print(valPCLoopD - 20);
    }
    if (valPCLoopD >= 30 && valPCLoopD <= 39) {
      lcd.print(valPCLoopD - 30);
    }
    if (valPCLoopD >= 40 && valPCLoopD <= 49) {
      lcd.print(valPCLoopD - 40);
    }
    if (valPCLoopD >= 50 && valPCLoopD <= 59) {
      lcd.print(valPCLoopD - 50);
    }
    if (valPCLoopD >= 60 && valPCLoopD <= 69) {
      lcd.print(valPCLoopD - 60);
    }
    if (valPCLoopD >= 70 && valPCLoopD <= 79) {
      lcd.print(valPCLoopD - 70);
    }
    if (valPCLoopD >= 80 && valPCLoopD <= 89) {
      lcd.print(valPCLoopD - 80);
    }
    if (valPCLoopD >= 90 && valPCLoopD <= 99) {
      lcd.print(valPCLoopD - 90);
    }


    lcd.setCursor(11, 0);
    lcd.print("Style");
    lcd.setCursor(13, 1);
    if (valPCLoopD >= 0 && valPCLoopD <= 9) {
      lcd.print("A");
    }
    if (valPCLoopD >= 10 && valPCLoopD <= 19) {
      lcd.print("B");
    }
    if (valPCLoopD >= 20 && valPCLoopD <= 29) {
      lcd.print("C");
    }
    if (valPCLoopD >= 30 && valPCLoopD <= 39) {
      lcd.print("D");
    }
    if (valPCLoopD >= 40 && valPCLoopD <= 49) {
      lcd.print("E");
    }
    if (valPCLoopD >= 50 && valPCLoopD <= 59) {
      lcd.print("F");
    }
    if (valPCLoopD >= 60 && valPCLoopD <= 69) {
      lcd.print("G");
    }
    if (valPCLoopD >= 70 && valPCLoopD <= 79) {
      lcd.print("H");
    }
    if (valPCLoopD >= 80 && valPCLoopD <= 89) {
      lcd.print("I");
    }
    if (valPCLoopD >= 90 && valPCLoopD <= 99) {
      lcd.print("J");
    }


    lcd.setCursor(8, 0);
    lcd.print("|");
    lcd.setCursor(8, 1);
    lcd.print("|");
    lcd.setCursor(9, 0);
    lcd.print("|");
    lcd.setCursor(9, 1);
    lcd.print("|");
  }

  //OLED 128x64 I2C
#elif USE_OLED
  if (tgSt[0] == 0) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(10, 15);
    u8g2.print("| B A N K  |");
    u8g2.sendBuffer();
    u8g2.setFont(u8g2_font_inr38_mr);
    if (valBank >= 0 && valBank <= 9) {
      u8g2.setCursor(25, 58);
    }
    if (valBank >= 10 && valBank <= 99) {
      u8g2.setCursor(10, 58);
    }
    if (valBank >= 100 && valBank <= 999) {
      u8g2.setCursor(0, 58);
    }
    u8g2.print(valBank);
    u8g2.sendBuffer();

    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(80, 15);
    u8g2.print("|Preset|");
    u8g2.sendBuffer();
    u8g2.setFont(u8g2_font_inr38_mr);
    u8g2.setCursor(90, 58);
    if (pc == 128) {
      u8g2.print("?");
    }
    if (pc == 0) {
      u8g2.print("A");
    }
    if (pc == 1) {
      u8g2.print("B");
    }
    if (pc == 2) {
      u8g2.print("C");
    }
    if (pc == 3) {
      u8g2.print("D");
    }
    u8g2.sendBuffer();
  }
  if (tgSt[0] == 1) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(22, 20);
    u8g2.print("| M O D E  |");
    u8g2.sendBuffer();
    u8g2.setFont(u8g2_font_profont22_tr);
    u8g2.setCursor(5, 50);
    u8g2.print("INDIVIDUAL");
    u8g2.sendBuffer();
  }

  if (tgSt[0] == 2) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(10, 15);
    u8g2.print("| PATTERN  |");
    u8g2.sendBuffer();
    u8g2.setFont(u8g2_font_inr38_mr);
    u8g2.setCursor(30, 58);
    if (valPCLoopD >= 0 && valPCLoopD <= 9) {
      u8g2.print(valPCLoopD);
    }
    if (valPCLoopD >= 10 && valPCLoopD <= 19) {
      u8g2.print(valPCLoopD - 10);
    }
    if (valPCLoopD >= 20 && valPCLoopD <= 29) {
      u8g2.print(valPCLoopD - 20);
    }
    if (valPCLoopD >= 30 && valPCLoopD <= 39) {
      u8g2.print(valPCLoopD - 30);
    }
    if (valPCLoopD >= 40 && valPCLoopD <= 49) {
      u8g2.print(valPCLoopD - 40);
    }
    if (valPCLoopD >= 50 && valPCLoopD <= 59) {
      u8g2.print(valPCLoopD - 50);
    }
    if (valPCLoopD >= 60 && valPCLoopD <= 69) {
      u8g2.print(valPCLoopD - 60);
    }
    if (valPCLoopD >= 70 && valPCLoopD <= 79) {
      u8g2.print(valPCLoopD - 70);
    }
    if (valPCLoopD >= 80 && valPCLoopD <= 89) {
      u8g2.print(valPCLoopD - 80);
    }
    if (valPCLoopD >= 90 && valPCLoopD <= 99) {
      u8g2.print(valPCLoopD - 90);
    }
    u8g2.sendBuffer();


    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(80, 15);
    u8g2.print("| Style|");
    u8g2.sendBuffer();
    u8g2.setFont(u8g2_font_inr38_mr);
    u8g2.setCursor(90, 58);
    if (valPCLoopD >= 0 && valPCLoopD <= 9) {
      u8g2.print("A");
    }
    if (valPCLoopD >= 10 && valPCLoopD <= 19) {
      u8g2.print("B");
    }
    if (valPCLoopD >= 20 && valPCLoopD <= 29) {
      u8g2.print("C");
    }
    if (valPCLoopD >= 30 && valPCLoopD <= 39) {
      u8g2.print("D");
    }
    if (valPCLoopD >= 40 && valPCLoopD <= 49) {
      u8g2.print("E");
    }
    if (valPCLoopD >= 50 && valPCLoopD <= 59) {
      u8g2.print("F");
    }
    if (valPCLoopD >= 60 && valPCLoopD <= 69) {
      u8g2.print("G");
    }
    if (valPCLoopD >= 70 && valPCLoopD <= 79) {
      u8g2.print("H");
    }
    if (valPCLoopD >= 80 && valPCLoopD <= 89) {
      u8g2.print("I");
    }
    if (valPCLoopD >= 90 && valPCLoopD <= 99) {
      u8g2.print("J");
    }
    u8g2.sendBuffer();
  }

#elif USE_7SEGMENTS_16bits
  if (tgSt[0] == 0) {
    //           Bedcpabgf; //Digit Left
    numLeft[0] = B11101101;
    numLeft[1] = B00100100;
    numLeft[2] = B11001110;
    numLeft[3] = B01101110;
    numLeft[4] = B00100111;
    numLeft[5] = B01101011;
    numLeft[6] = B11101011;
    numLeft[7] = B00101101;
    numLeft[8] = B11101111;
    numLeft[9] = B01101111;

    if (valBank >= 0 && valBank <= 9) {
      displayNum(0, valBank);//displayNum(digitLeft, digitRigth)
    }
    if (valBank >= 10 && valBank <= 19) {
      displayNum(1, valBank - 10);
    }
    if (valBank >= 20 && valBank <= 29) {
      displayNum(2, valBank - 20);
    }
    if (valBank >= 30 && valBank <= 39) {
      displayNum(3, valBank - 30);
    }
    if (valBank >= 40 && valBank <= 49) {
      displayNum(4, valBank - 40);
    }
    if (valBank >= 50 && valBank <= 59) {
      displayNum(5, valBank - 50);
    }
    if (valBank >= 60 && valBank <= 69) {
      displayNum(6, valBank - 60);
    }
    if (valBank >= 70 && valBank <= 79) {
      displayNum(7, valBank - 70);
    }
    if (valBank >= 80 && valBank <= 89) {
      displayNum(8, valBank - 80);
    }
    if (valBank >= 90 && valBank <= 99) {
      displayNum(9, valBank - 90);
    }
  }
  if (tgSt[0] == 1) {
    displayNum(10, 10);//displayNum(digitLeft, valBank-): 10 = OFF
  }
  if (tgSt[0] == 2) {
    //           Bedcpabgf; // Digit Left
    numLeft[0] = B10111111; // A
    numLeft[1] = B11111111; // B
    numLeft[2] = B11011001; // C
    numLeft[3] = B11111101; // D
    numLeft[4] = B11011011; // E
    numLeft[5] = B10011011; // F
    numLeft[6] = B11111011; // G
    numLeft[7] = B10110111; // H
    numLeft[8] = B00110100; // I
    numLeft[9] = B01110100; // J

    if (valPCLoopD >= 0 && valPCLoopD <= 9) {
      displayNum(0, valPCLoopD);//displayNum(digitLeft, digitRigth)
    }
    if (valPCLoopD >= 10 && valPCLoopD <= 19) {
      displayNum(1, valPCLoopD - 10);
    }
    if (valPCLoopD >= 20 && valPCLoopD <= 29) {
      displayNum(2, valPCLoopD - 20);
    }
    if (valPCLoopD >= 30 && valPCLoopD <= 39) {
      displayNum(3, valPCLoopD - 30);
    }
    if (valPCLoopD >= 40 && valPCLoopD <= 49) {
      displayNum(4, valPCLoopD - 40);
    }
    if (valPCLoopD >= 50 && valPCLoopD <= 59) {
      displayNum(5, valPCLoopD - 50);
    }
    if (valPCLoopD >= 60 && valPCLoopD <= 69) {
      displayNum(6, valPCLoopD - 60);
    }
    if (valPCLoopD >= 70 && valPCLoopD <= 79) {
      displayNum(7, valPCLoopD - 70);
    }
    if (valPCLoopD >= 80 && valPCLoopD <= 89) {
      displayNum(8, valPCLoopD - 80);
    }
    if (valPCLoopD >= 90 && valPCLoopD <= 99) {
      displayNum(9, valPCLoopD - 90);
    }
  }

#endif
}

//U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 12, /* dc=*/ 4, /* reset=*/ 6); // Arduboy (Production, Kickstarter Edition)
//U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_3W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_3W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_ALT0_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // same as the NONAME variant, but may solve the "every 2nd line skipped" problem
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 16, /* data=*/ 17, /* reset=*/ U8X8_PIN_NONE);   // ESP32 Thing, pure SW emulated I2C
//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 16, /* data=*/ 17);   // ESP32 Thing, HW I2C with pin remapping
//U8G2_SSD1306_128X64_NONAME_F_6800 u8g2(U8G2_R0, 13, 11, 2, 3, 4, 5, 6, A4, /*enable=*/ 7, /*cs=*/ 10, /*dc=*/ 9, /*reset=*/ 8);
//U8G2_SSD1306_128X64_NONAME_F_8080 u8g2(U8G2_R0, 13, 11, 2, 3, 4, 5, 6, A4, /*enable=*/ 7, /*cs=*/ 10, /*dc=*/ 9, /*reset=*/ 8);
//U8G2_SSD1306_128X64_VCOMH0_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8); // same as the NONAME variant, but maximizes setContrast() range
//U8G2_SSD1306_128X64_ALT0_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8); // same as the NONAME variant, but may solve the "every 2nd line skipped" problem
