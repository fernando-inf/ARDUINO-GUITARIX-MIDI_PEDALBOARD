/*
 *SIMPLE-MIDI-GUITARIX-PEDALBOARD

Si usa ttymidi en GNU/Linux ejecutelo asi (de no funcionar en primera instancia): ttymidi -s /dev/ttyUSB0 --baudrate=115200

Si usa Hairless-Midiserial habilite la linea MIDI.turnThruOff() en la pestaña SETUP;

--------------fernando-inf@hotmail.com--------------
------------------2021 @CopyLeft--------------------
*/

#include <MIDI.h>//https://github.com/FortySevenEffects/arduino_midi_library
#include <Bounce2.h>//https://github.com/thomasfredericks/Bounce2

MIDI_CREATE_DEFAULT_INSTANCE();                    

const int buttonPin[] = {2, 3, 4, 5, 6, 7, 8}; //{D2, D3,.........,D8}
const int LED[] = {9, 10, 11, 12, 13, A0, A1,A2, A3, A4, A5}; //{D9, D10,.........,A5} PIN DIGITAL LEDs

//MIDI.sendControlChange(CC, Valor, Ch)
  const int CC[] = {51, 52, 53, 54, 55, 56}; // Numero de Control Change para cada pulsador/pedal D3, D4,..., D8.
  const int ValOn = 127; //MIDI.sendControlChange(cc, valor=ValOn, ch)// Depende el programa se Enciende con 0 o con 127 
  const int ValOff = 0; //MIDI.sendControlChange(cc, valor=ValOff, ch)    // Depende el programa se Apaga con 0 o con 127
  const int Ch = 1; //Canal MIDI

  int CCBank = 0; //CC para cambio de Banco: CC0 = MSB, CC32 = LSB 
  int ValBank = 0; //Variable Para Cambio de Banco, Valor Inicial = 0
  const int ValBankMax = 3; // Valor Maximo del numero de Banco

//MIDI.sendProgramChange(pc, Ch);
  int pc = 128; //Variable para cambio de Programa (Preset) pc=ProgramChange. Valor inicial = 128 que no pertenece al intervalo MIDI (0 a 127) a los efectos de iniciar parpadeo de los LEDs (VoidBlinkLED) para cambio de programa en el primer inicio, ver Void de D2

int buttonState1 = 0;//D2
int lastButtonState1 = 0;//D2

int TgSt[] = {0, 0, 0, 0, 0, 0, 0};//{TgSt[0], TgSt[1],...,TgSt[6]}- TgSt= ToggleState -> Sirve para que, al pulsar una vez el pedal, se envie una señal y al pulsarlo otra vez se envie otra señal distinta de la primera dependiendo si el TgSt quedo en 0 o en 1 previamente.    
int TgStB[] = {1, 1, 1, 1, 1, 1}; // TgSt para MODO BANCO, mediante MIDI Input (recepción de señales MIDI) cambia su estado, sirve para: encender o apagar LEDs cuando se cambia al MODO INDIVIDUAL con el uso de D2

const int DelayPulsadores = 10; // Evita la Repetición de señal al apretar el pulsador, X ms de espera hasta enviar otra señal.
