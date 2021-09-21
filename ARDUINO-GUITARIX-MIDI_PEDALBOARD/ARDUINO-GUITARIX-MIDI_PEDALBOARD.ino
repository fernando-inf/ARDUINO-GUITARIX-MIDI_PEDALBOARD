/*
  ARDUINO-GUITARIX-MIDI_PEDALBOARD

  GITHUB:
  https://github.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD

  -----------GNU General Public License v3.0---------
  --------------fernando-inf@hotmail.com--------------
  ------------------2021 @CopyLeft--------------------

  ADVERTENCIA:
  Las opciones USE_LCD, USE_OLED y USE_7SEGMENTS_16bits (con Chip 74HC595) solo se han probado mediante simulador.
  Las opciones USE_LCDI2C, USE_USBMIDI y USE_ESP32BluetoothBLE no se han probado en simulador, ni en Hardware.
*/

//*****************************************
//SELECT DISPLAY, BOARD, OTHER SETTINGS WHIT 1.
#define USE_LEDs                          1  //Si Muestra la información con luces led = 1, de lo contrario 0. Solo Arduino Mega, Uno, Nano, Leonardo.
#define USE_7SEGMENTS_16bits              0  //Si Muestra la información con Display 7 Segmentos 2 Dígitos + SIEMENS SDA-2131 (16bits) o 2 x 74HC595 (8bits + 8bits)= 1, de lo contrario 0. Ver 74HC595 (8bits x 2): https://youtu.be/QI1IJLB42G8?t=593 . Solo Arduino Mega, Uno, Nano, Leonardo.
#define USE_LCD                           0  //Si Muestra la información con LCD = 1, de lo contrario 0. Solo Arduino Mega.
#define USE_LCDI2C                        0  //Si Muestra la información con LCD I2C = 1, de lo contrario 0. Solo Arduino Mega, Uno y Nano.
#define USE_OLED                          0  //Si Muestra la información con OLED = 1 (SSD1306 128x64 I2C), de lo contrario 0. Solo Arduino Mega.

#define USE_USBMIDI                       0  //Si usa conexión USB Nativa = 1. Solo Arduino Leonardo/Micro.
#define USE_ESP32BluetoothBLE             0  //Si usa Bluetooth con ESP32, está limitado en número de Pins, no puede mostrar el estado de los Bancos con luces LED ni LCD/OLED, a futuro se implementará uso de MUX. ¡ADVERTENCIA!: Los pulsadores no usan PULLUP interno.

#define USE_MIDI_DIN_CONNECTOR_OR_HIDUINO 0  //Si conecta Arduino mediante conector MIDI DIN a algún rack o pedal con Midi Input, o si usa Arduino con 16u2 y Firmware Hiduino o similar = 1, de lo contrario 0.
#define NO_USE_MIDI_INPUT                 0  //Si su PC o equipo (Rack, Pedal... ) no enviará señales MIDI a Arduino = 1, de lo contrario 0.
#define USE_MIDI_THRU                     1  //Si quiere que las señales MIDI Input vuelvan a salir por MIDI Output = 1, de lo contrario 0. En Guitarix es necesario MIDI Thru para resolver este conflicto: https://github.com/brummer10/guitarix/issues/80 . Advertencia: En ocasiones puede provocar un bucle infinito de entradas y salidas de señales MIDI.
//*****************************************

#include <Bounce2.h>  //https://github.com/thomasfredericks/Bounce2

#if USE_USBMIDI
#include <USB-MIDI.h>  //https://github.com/lathoub/Arduino-USBMIDI
USBMIDI_CREATE_DEFAULT_INSTANCE();

#elif USE_ESP32BluetoothBLE  //https://github.com/lathoub/Arduino-BLE-MIDI
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>  //Tambien puede probar usando NimBLE, en cuyo caso deshabilite esta línea y la próxima
BLEMIDI_CREATE_DEFAULT_INSTANCE()
//#include <hardware/BLEMIDI_ESP32_NimBLE.h>//Habilite esta línea si usa NimBLE.
//BLEMIDI_CREATE_INSTANCE("CustomName", MIDI)//Habilite esta línea si usa NimBLE.
void OnConnected() {  //Enciende LED cuando el Dispositivo se ha conectado por Bluetooth.
  digitalWrite(27, HIGH);
}
void OnDisconnected() { //Apaga LED cuando el Dispositivo se ha desconectado.
  digitalWrite(27, LOW);
}

#else
#include <MIDI.h> //https://github.com/FortySevenEffects/arduino_midi_library
MIDI_CREATE_DEFAULT_INSTANCE();
#endif


#if USE_ESP32BluetoothBLE
byte buttonPin[] = { 32, 33, 34, 35, 36, 39 }; //Pines Digitales ¡SIN PULLUP INTERNO! en ES32 para: Pedal0, Pedal1, Pedal2,... , Pedal6
#else
byte buttonPin[] = { 2, 3, 4, 5, 6, 7, 8 }; //Pines Digitales para: SwitchButton/Pedal0, Pedal1, Pedal2,... , Pedal6
#endif

#if USE_LEDs
#if USE_ESP32BluetoothBLE //Pines ADC2 NO PUEDEN USARSE AL HABILITAR BLUETOOTH: 25, 26, 27, 14, 12, 13, 15, 2, 4, 0 - https://github.com/espressif/esp-idf/issues/461 - https://ESP32.com/viewtopic.php?t=20057
const byte LED[] = { 16, 17, 18, 19, 23, 22, 21 }; //{D9, D10,.........,19} PIN DIGITAL LEDs// Pines si no usa Bluetooth {13, 14, 16, 17, 18, 19, 23, 25, 26, 22, 21};
#else
const byte LED[] = { 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5 }; //{D9, D10,.........,A5} PIN DIGITAL LEDs
#endif
#elif USE_7SEGMENTS_16bits
const byte LED[] = { 9, 10, 11, 12, 13, A0, A1, A2, A3, A4};
#else
#if USE_ESP32BluetoothBLE
const byte LED[] = { 16, 17, 18, 19, 23, 22, 21 }; //PIN DIGITAL LEDs ESP32
#else
const byte LED[] = { 9, 10, 11, 12, 13, A0, A1 }; //{D9, D10,.........,A1} PIN DIGITAL LEDs
#endif
#endif

//MIDI.sendControlChange(CC, Valor, Ch)
const byte CC[] = { 51, 52, 53, 54, 55, 56 }; // Numero de Control Change para cada Pedal: Pedal1, Pedal2,... , Pedal6.
byte valOn = 127; //MIDI.sendControlChange(cc, valor=valOn, ch) - Depende el programa se Enciende con 0 o con 127
byte valOff = 0; //MIDI.sendControlChange(cc, valor=valOff, ch) - Depende el programa se Apaga con 0 o con 127
byte Ch = 1; //Canal MIDI

byte CCBank = 0; //CC para cambio de Banco: CC0 = MSB, CC32 = LSB
int valBank = 0; //Variable Para Cambio de Banco, Valor Inicial = 0
#if USE_LEDs
byte valBankMax = 3; // Valor Máximo del número de Banco
#else
int valBankMax = 99; // Valor Máximo del número de Banco
#endif

//MIDI.sendProgramChange(pc, Ch);
byte pc = 128; //Variable para cambio de Programa/Preset (pc=ProgramChange). Valor inicial = 128 a los efectos de iniciar parpadeo de los LEDs (VoidBlinkLEDPC) para cambio de Banco.
int valPCLoopD = 0;
int valPCLoopDMax = 99;
byte ChLoopD = 2;

byte tgSt[] = { 0, 0, 0, 0, 0, 0, 0 }; //tgSt= ToggleState - {tgSt[0], tgSt[1],...,tgSt[6]}

#if NO_USE_MIDI_INPUT
#else
byte tgStB[] = { 1, 1, 1, 1, 1, 1 }; //tgSt para MODO BANCO, mediante MIDI Input (recepción de señales MIDI) cambia su estado, sirve para: encender o apagar LEDs cuando se cambia al MODO INDIVIDUAL.
#endif

byte tgStLoopD[] = { 0, 0, 0, 0 }; //tgStLoopD= ToggleState for MODE LOOP/DRUM (LOOPD)
byte tgSt_0_Max = 2; //Máximo de Funciones para tgSt[0]. tgSt[0]=0 es MODO BANCO, tgSt[0]=1 es MODO INDIVIDUAL, tgSt[0]=2 es MODO LOOP/DRUM (LOOPD).
