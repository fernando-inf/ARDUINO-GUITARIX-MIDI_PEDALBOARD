# FREE SOFTWARE - FREE WORLD - Try GNU / Linux is FREE.
https://www.gnu.org/

# SIMPLE-MIDI-GUITARIX-PEDALBOARD (MIDI Input - MIDI Output)
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-1.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-2.png" width="100%"></img>
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-SimulIDE.png" width="100%"></img> 

<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-3.JPG" width="100%"></img>
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-4.JPG" width="100%"></img> 
# INSTALACIÓN DEL FIRMWARE
- Abrir el archivo SIMPLE_MIDI_GUITARIX_PEDALBOARD.ino con Arduino IDE y cargarglo en su placa de desarrollo.
- Previamente debera tener instaladas las bibliotecas Bounce2, LiquidCrystal y MIDI Library (by Francois Best), para esto dirijirse a Arduino IDE "Herramientas -> Administrar Bibliotecas..." y buscarla.
# FUNCIONAMIENTO
- El Pulsador que esta en el sector medio superior del pedal y que a la misma vez contiene un LED azul cambia de MODO BANCO a MODO INDIVIDUAL.
- MODO BANCO: El Pedal 1 Decrementa el Valor de Banco y el Pedal 2 lo Incrementa. Los Pedales del 3 al 6 representan a un Preset A-B-C-D.
- MODO INDIVIDUAL: Los Pedales 1 al 6 efectuan el enciendido y apagado de efectos.
- La Pedalera inicia en MODO BANCO en el Banco 0 y Preset 0 (A), sin embargo queda a la espera (LEDs Parpadeando) de la confirmación de selección de preset. Usted debe confirmar el preset antes de pasar el MODO INDIVIDUAL ya que, los LEDs seguirán parpadeando impidiendo el correcto funcionamiento de este MODO. Además, con cada pulsación de los Pedales 1 y 2 los LEDs volverán a Parpadear y, usted debera necesariamente confirmar el preset.

Simulación:
Descargue la ultima versión SimulIDE que incluye soporte para Arduino: https://www.simulide.com/p/downloads.html

Abrir el archivo SIMULIDE-PedalBoardMIDI.simu que se encuentra en la carpeta del proyecto. De no iniciar la simulación haga click derecho sobre la placa Arduino y LOAD FIRMWARE, luego seleccione alguno de los archivos con extensión HEX que están en la carpeta principal del proyecto.

La versión simple y económica de este proyecto esta limitada a 4 Bancos (con 4 preset cada uno, total: 16 presets), ya que son la cantidad de LEDs disponibles para mostrar el estado de los mismos en Arduino Nano. Se esta trabajando en otra versión con display de 7 segmentos que incrementará el costo. A futuro se espera diseñar una pedalera mas grande con pantalla LCD GRAFICA. Igualmente en el código se ofrece la posibilidad de usar un LCD 16x2 a quienes tengan un Arduinoo Mega, en cuyo caso en la primer pestaña del còdigo reemplazar:

`const int ValBankMax = 3;`

por

`const int ValBankMax = 127;`

<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/Arduino_MEGA-%20LCD16x2/SIMULIDE-PedalBoardMIDI-MEGA.png" width="100%"></img> 

Esta Pedalera tiene la característica de recibir la señal MIDI del software y reflejarla en el pedal. Almacena las actualizaciones recibidas tanto en el MODO BANCO como en el MODO INIVIDUAL. Por ejemplo, si usted esta en el MODO BANCO y cambia de presets, la pedalera recibirá las actualizaciones de cada cambio de los pedales individuales (on/off) y los reflejara en los LEDs cuando usted cambie al MODO INDIVIDUAL. De esta forma sabrá el estado de los efectos sin tener que mirar la interfaz gráfica en su Monitor.

# MEDIDAS
Entrar a: https://app.sketchup.com

Abrir el archivo SKETCHUP-SIMPLE-MIDI-GUITARIX-PEDALBOARD.skp que se encuentra en la carpeta del proyecto.

# MATERIALES
Este proyecto pretende usar materiales reciclados, quien escribe no responde por lo daños económicos que puedan causar los detalles descriptos en este apartado:

1- Arduino Nano u otra placa programable con Arduino IDE y con disponibilidad de 17 pines digitales: la conexión a la PC se hace por USB, luego usar ttymidi (en GNU/Linux https://github.com/moddevices/mod-ttymidi es fácil de compilar) para simular un puerto MIDI (o Hairless MIDI to Serial).

2- Perfil de Chapa Galvanizada de 40,5 x 9,7 cm (Los suelen tirar en la obras de construcción): Si se lija se puede lograr hasta un brillo espejo, pero suele oxidarse facilmente y requiere de constante mantenimiento.

3- Tuvo PVC 110x2,5 mm (se corta y da la forma del pedal con calor, por ejemplo con una plancha para ropa)

4- Un retazo de madera para dar la forma interna del pedal (lijando), se usará para moldear el PVC.

5- Chapa fina (puede ser de lata de gaseosa o cerveza, lijar pintura para asegurarse de que conducirá energía) que se pegara (con Cianoacrilato – Gotita en algunos países) por encima del PVC y conducirá la señal Digital de los Pines. Esta chapa chocara con el perfil de metal (punto 2) que conducirá GND y así encenderá y apagará el Pedal. Si pinta el perfil de metal entonces tendrá que, colocar otra chapa fina por debajo del pedal de PVC que conducirá el GND para que puede tomar contacto con la señal digital.

6- 10 LEDs. (para los Pedales se usaron LEDs Blancos provenientes de una Luz de Emergencia en desuso, para el resto se usaron LEDs azules de mouse óptico y Joystick de PS2)

7- Resistencias 220ohms (o mayor valor si no tiene disponibles estas), puede colocar o no estas resistencias a los LEDS (entre la salida del PIN digital de Arduino y el LED), en general es recomendable colocarlas pero, si tiene muchos LEDs para reciclar puede probar esto: si los LEDs calientan coloque resistencias, de lo contrario no serían necesarias.

8- Un pulsador de CPU que se usara para el cambio entre MODO BANCO y MODO INDIVIDUAL.

9- 12 Tornillos (con tuercas) de 3 milimetros de diametro por 8mm de largo aprox.: se usaran para ajustar los pedales al perfil de metal, tenian un costo de AR$2 en el primer trimestre del 2021.

10- Herramientas (caladora de mano o eléctrica, taladro, lijadora, limas, etc.), lijas distintos granos y mechas para taladro de distintas medidas.

-Otros- Alternativamente puede usar: 
Conector USB tipo B: reciclado de impresora o modem para no conectar directamente Arduino a la PC. 
Switch (on/off): reciclado de un Hub USB para encender y apagar la pedalera.
Porcelana fría: para dar forma al soporte de los LEDs en la parte interior del perfil de chapa galvanizada.
Gomitas de Jeringa: que servirán para soporte y no desplazamiento del pedal en el suelo.
<img src="https://raw.githubusercontent.com/fernando-inf/SIMPLE-MIDI-GUITARIX-PEDALBOARD/main/SIMPLE_MIDI_GUITARIX_PEDALBOARD/PedalBoardMIDI-5.png" width="100%"></img> 

# ADVERTENCIAS/ACLARACIONES
- Por simplicidad en SimulIDE no se usan resistencias para los LEDs, pero usted debería colocarlas para evitar daños en los mismos, tal cual se a descripto en la sección "MATERIALES".

- Luego de hacer pruebas exhaustivas se puede decir que: Si usted en Guitarix añadió un efecto, luego le asigno un MIDI CC y luego quito este efecto: es recomendable eliminar el MIDI CC asignado en la pestaña Motor-> Controlador MIDI. Así, se determino que se evita un bucle infinito de entradas y salidas de señales MIDI (si usted no elimina el CC asignado, Guitarix continuará enviando la señal MIDI, repetidas veces) ya que el Código de este PedalBoard habilita MIDI THRU para la correcta actualización de los preset con cada cambio de los mismos. Si se envían señales repetidas de un mismo MIDI CC se produce el bucle infinito (ver: https://github.com/brummer10/guitarix/issues/80).
- La Chapa fina de lata de gaseosa mencionada en la sección  "Materiales", no ha sido probada en este proyecto (se uso otra placa antigua que se tenia disponible). Se puede notar que tiene mucha flexibilidad y se parte facilmente al doblarla completamente, sin embargo es viable probarla ya que parece ser una buena alternativa de facil disponibilidad.
- Considere usar Noise Repellent como Reductor de Ruido (No es puerta de Ruido): https://github.com/lucianodato/noise-repellent, si bien provoca latencia, vale la pena probarlo.

# OTRA INFORMACIÓN
Abra el archivo SIMPLE_MIDI_GUITARIX_PEDALBOARD.ino con Arduino IDE. En la primer pestaña encontrará los pines asignados a LEDs y Pedales. Todos los Pines y señales MIDI CC son modificables pero, no realice ningún cambio sin antes hacer una copia de los archivos. Puede usar simuladores (SimulIDE) y el Debug de Hairless MIDI to Serial para probar los cambios que realice.

Ver la simulación en SimulIDE para entender mejor la asignación de Pines:

`const int buttonPin[] = {2, 3, 4, 5, 6, 7, 8}; //{D2, D3,.........,D8}`

`const int LED[] = {9, 10, 11, 12, 13, A0, A1,A2, A3, A4, A5}; //{D9, D10,.........,A5}`

`const int CC[] = {51, 52, 53, 54, 55, 56}; // Numero de Control Change para cada pulsador/pedal D3, D4,..., D8.`
  
Si usa ttymidi en GNU/Linux ejecutelo así (de no funcionar o funcionar mal en primera instancia):

`$ ttymidi -s /dev/ttyUSB0 --baudrate=115200`

Recuerde que ttymidi solo se iniciará si conecto previamente Arduino al puerto usb. Asi mismo verifique que previamente no ha quedado abierta otra instancia de ttymidi, de ser así, cierrela en su Gestor/Administrador de tareas.

Si usa Hairless-Midiserial (en formato compilado solo esta disponible para sistemas operativos de 32 bits en GNU/Linux) habilite la linea ´MIDI.turnThruOff() en la pestaña SETUP;


Tenga la gentileza de informarme sobre los avances significativos que haga usted en el proyecto y de enviarme fotos de su versión de esta pedalera.

fernando-inf@hotmail.com

2021 @CopyLeft
