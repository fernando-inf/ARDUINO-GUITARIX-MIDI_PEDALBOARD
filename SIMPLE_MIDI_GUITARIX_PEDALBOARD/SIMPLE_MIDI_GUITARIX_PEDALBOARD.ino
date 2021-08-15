/*
 *MIDI PEDALBOARD DIY FREE.

ADVERTENCIA: Todos los Pines y señales CC son modificables pero, 
no realize ningun cambio sin antes hacer una copia de los archivos.
Puede usar simuladores (SimulIDE) y el Debug de Hairless MIDI to Serial 
para probar los cambios que realice. Tenga la gentileza de informarme sobre 
los avances significativos que haga usted en el proyecto.

Si usa ttymidi en LINUX ejecutelo asi de no funcionar en primera instancia: ttymidi -s /dev/ttyUSB0 --baudrate=115200

Si usa Hairless-Midiserial habilite la linea MIDI.turnThruOff() en la pestaña SETUP;

 ------------------Diseñado por:--------------------
---------------Fernando Omar Serrano----------------
--------------fernando-inf@hotmail.com--------------
------------------2021 @CopyLeft--------------------
*/

#include <MIDI.h>
#include <Bounce.h>   //https://github.com/mpflaga/Arduino-Bounce

MIDI_CREATE_DEFAULT_INSTANCE();                    
                      
const int buttonPin[] = {2, 3, 4, 5, 6, 7, 8}; //{D2, D3,.........,D8}- Pines digitales asignados a cada pulsador, inicia con el pulsador de Cambio de MODO BANCO A INDIVIDUAL D2 = 2
const int CC[] = {51, 52, 53, 54, 55, 56}; // Numero de Control Change (similar a NOTAS) para PIN DIGITAL apartir del D3, D4,..., D8.
const int LED[] = {9, 10, 11, 12, 13, A0, A1,A2, A3, A4, A5}; //PIN DIGITAL ENCENDER LED

const int Ch = 1; //Canal MIDI

const int ValOn = 127; //MIDI.sendControlChange(cc, valor=ValOn, ch)// Depende el programa se Enciende con 0 o con 127 // BLUE CAT'S AXIOM=0, GUITARIX=127 (GuitarIX puede prender y apagar con 127: hay que seleccionar la opción "on/off states transition toggle"
const int ValOff = 0; //MIDI.sendControlChange(cc, valor=ValOff, ch)    // Depende el programa se Apaga con 0 o con 127 // BLUE CAT'S AXIOM=0, GUITARIX=127 (GuitarIX puede prender y apagar con 127: hay que seleccionar la opción "on/off states transition toggle"

int BankMSB_LSB = 0; //Variable Para Cambio de Banco, inicia en Banco = 0 y su valor maximo es BankMax
const int BankMax = 3; // Valor Maximo del numero de Banco
int MSB_LSB = 0; // CC0 = MSB (Blue Catś AXIOM o GuitarIX), CC32 = LSB (GUITARIX)
int pc = 128; //Variable para cambio de Programa (Preset) pc=ProgramChange. Valor por defecto = 128 que no pertenece al intervalo MIDI (0 a 127) a los efectos de iniciar parpadeo de los LEDs (VoidBlinkLED) para cambio de programa en el primer inicio, ver Void de D2

int buttonState1 = 0;
int lastButtonState1 = 0;

int TgSt[] = {0, 0, 0, 0, 0, 0, 0};//{TgSt[0], TgSt[1],...,TgSt[6]}- TgSt= ToggleState -> Sirve para que, al pulsar una vez el pedal, se envie una señal y al pulsarlo otra vez se envie otra señal distinta de la primera dependiendo si el TgSt quedo en 0 o en 1 previamente.    
int TgStB[] = {1, 1, 1, 1, 1, 1}; // TgSt para MODO BANCO, mediante MIDI Input (recepción de señales MIDI) cambia su estado, sirve para: encender o apagar LEDs cuando se cambia al MODO INDIVIDUAL con el uso de D2

const int DelayPulsadores = 10; // Evita la Repetición de señal al apretar el pulsador, X ms de espera hasta enviar otra señal.
