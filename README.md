# SIMPLE-MIDI-GUITARIX-PEDALBOARD
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-1.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-2.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-SimulIDE.png" width="100%"></img> 

#FUNCIONAMIENTO
Descargue SimulIDE: https://www.simulide.com/p/downloads.html

Abrir el archivo SIMULIDE-PedalBoardMIDI.simu que se encuentra en la carpeta del proyecto. De no iniciar la simulación haga click derecho sobre la placa Arduino y LOAD FIRMWARE, luego seleccione alguno de los archivos con extensión HEX que estan en la carpeta principal del proyecto.

#MEDIDAS
Entrar a: https://app.sketchup.com
Abrir el archivo SKETCHUP-SIMPLE-MIDI-GUITARIX-PEDALBOARD.skp que se encuentra en la carpeta del proyecto.

#MATERIALES
Este proyecto pretende usar materiales reciclados:
1- Arduino Nano (la conexión a la PC se hace por USB, luego usar ttymidi (en GNU/Linux) para simular un puerto MIDI)
1- Perfil de Hierro de 40,5 x 9,7 cm
2- Tuvo PVC 110x2,5 mm (se corta y da la forma del pedal con calor, por ejemplo con una plancha para ropa)
3- Un retazo de madera para dar la forma interna del pedal (lijando) donde se moldeara el PVC.
3- 10 LEDs. (para los Pedales se usaron LEDs Blancos provenientes de una Luz de Emergencia en desuso, para el resto se usaron LEDs azules de mouse optico y Joystick de PS2)
4- Resistencias 220ohms (o mayor valor si no tiene disponibles estas), puede colocar o no estas resistencias a los LEDS, entre la salida del PIN digital de Arduino y el LED, en general es recomendable colocarlas pero, si tiene muchos LEDs para reciclar puede probar esto: si los LEDs calientan coloque resistencias, de lo contrario no serían necesarias.
5- Un pulsador de CPU que se usara para el cambio entre MODO BANCO y MODO INDIVIDUAL.

Todos los Pines y señales MIDI CC son modificables pero, 
no realize ningun cambio sin antes hacer una copia de los archivos.
Puede usar simuladores (SimulIDE) y el Debug de Hairless MIDI to Serial 
para probar los cambios que realice. Tenga la gentileza de informarme sobre 
los avances significativos que haga usted en el proyecto.
Si usa ttymidi en LINUX ejecutelo asi de no funcionar en primera instancia: $ ttymidi -s /dev/ttyUSB0 --baudrate=115200
Si usa Hairless-Midiserial habilite la linea MIDI.turnThruOff() en la pestaña SETUP;

 ---------------Diseñado por:

---------------Fernando Omar Serrano (fernando-inf@hotmail.com)

---------------2021 @CopyLeft
