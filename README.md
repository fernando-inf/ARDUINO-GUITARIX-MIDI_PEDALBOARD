# FREE SOFTWARE - FREE WORLD - Try GNU / Linux is FREE.

https://www.gnu.org/

https://github.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD

# ARDUINO/GUITARIX- MIDI PEDALBOARD (MIDI Input - MIDI Output)
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/PedalBoardMIDI-6.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/PedalBoardMIDI-7.png" width="100%"></img>
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/PedalBoardMIDI-3.JPG" width="100%"></img> 

<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/PedalBoardMIDI-4.JPG" width="100%"></img>
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD//Arduino_Nano-LEDs/SIMULIDE-PedalBoardMIDI.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Arduino_MEGA-%20OLED/SIMULIDE-PedalBoardMIDI-MEGA.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Arduino_MEGA-%20LCD16x2/SIMULIDE-PedalBoardMIDI-MEGA.png" width="100%"></img> 
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Arduino_Nano-Display7Segment/SIMULIDE-PedalBoardMIDI.png" width="100%"></img> 
# INSTALACIÓN DEL FIRMWARE
- Abrir el archivo ARDUINO-GUITARIX-MIDI_PEDALBOARD.ino con Arduino IDE.

- Instále las dependencias:

  Previamente deberá tener instaladas estas librerías, para esto dirigirse a Arduino IDE "Herramientas ->   Administrar Bibliotecas..." y buscarlas:
  
  - Bounce2: https://github.com/thomasfredericks/Bounce2
  
  - MIDI Library: https://github.com/FortySevenEffects/arduino_midi_library
  
  - Si usa USB-MIDI: Arudino USB-MIDI https://github.com/lathoub/Arduino-USBMIDI
  
  - Si usa Bluetooth con ESP32: Arduino BLE MIDI https://github.com/lathoub/Arduino-BLE-MIDI
  
  - Si usa LCD 16x2: LiquidCrystal https://www.arduino.cc/en/Reference/LiquidCrystal
  
  - Si usa LCD 16x2 con I2C: LiquidCrystal_I2C https://github.com/johnrickman/LiquidCrystal_I2C
  
  - Si usa OLED 128x64 I2C: U8g2 https://github.com/olikraus/u8g2
  
- Habilíte su configuración con un valor = 1.

<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/Arduino_Code_Choice.png" width="100%"></img>

- Compilar y subir el código a su placa de desarrollo.

# SOPORTE DE PLACAS DE DESARROLLO
- Si para mostrar los datos de número de banco y preset usa:
  - LEDs: Arduino Mega, Uno, Nano, Leonardo.
  - Display 7 Segmentos 2 dígitos con chip- SIEMENS SDA2131 (16bits) o 74HC595 x 2 (8bits + 8bits): Arduino Mega, Uno, Nano, Leonardo.
  - LCD 16x2: Arduino Mega.
  - LCD 16x2 con I2C: Arduino Mega, Uno y Nano.
  - Display OLED: Arduino Mega.
- Si usa conexión nativa usb: Arduino Leonardo, Micro.
- Si usa Bluetooth: ESP32 (Por una cuestión de limitación de pines no puede mostrar los datos de número de banco y preset)
  
# FUNCIONAMIENTO
- El Pulsador que está en el sector medio superior del pedal y que a la misma vez contiene un LED azul cambia de MODO BANCO, INDIVIDUAL y LOOP/DRUM, también lo hace el Pedal 1 si lo mantiene presionado por más de medio segundo.
- MODO BANCO: El Pedal 1 Decrementa el Valor de Banco y el Pedal 2 lo Incrementa. Los Pedales del 3 al 6 representan a un Preset A-B-C-D.
- MODO INDIVIDUAL: Los Pedales 1 al 6 efectúan el encendido y apagado de efectos.
- MODO LOOP/DRUM: El Pedal 1 y 2 suben y bajan de Sample/Pattern Drum (usar Hydrogen), el Pedal 3 puede ser asignado para activar/desactivar el sample drum. El pedal 4 puede servir como TAP del programa de batería y loop, el pedal 5 para grabar el loop (usar Sooperlooper) y el Pedal 6 para Pause/Stop.
- La Pedalera inicia en MODO BANCO en el Banco 0 y Preset 0 (A), sin embargo queda a la espera (LEDs Parpadeando) de la confirmación de selección de preset. Usted debe confirmar el preset antes de pasar el MODO INDIVIDUAL ya que, los LEDs seguirán parpadeando impidiendo el correcto funcionamiento de este MODO. Además, con cada pulsación de los Pedales 1 y 2 los LEDs volverán a Parpadear y, usted deberá necesariamente confirmar el preset.

Simulación:
Descargue la ultima versión SimulIDE que incluye soporte para Arduino: https://www.simulide.com/p/downloads.html

Abrir el archivo SIMULIDE-PedalBoardMIDI.simu que se encuentra en la carpeta del proyecto. De no iniciar la simulación haga click derecho sobre la placa Arduino y LOAD FIRMWARE, luego seleccione alguno de los archivos con extensión HEX que están en la carpeta principal del proyecto.

La versión simple y económica de este proyecto esta limitada a 4 Bancos (con 4 preset cada uno, total: 16 presets), ya que son la cantidad de LEDs disponibles para mostrar el estado de los mismos en Arduino Nano. Para el uso de display se habilitan 99 bancos, con 4 presets cada uno llegando a un total de 396 presets, suficientes para un usuario común.

Esta Pedalera tiene la característica de recibir la señal MIDI del software y reflejarla en el pedal. Almacena las actualizaciones recibidas tanto en el MODO BANCO como en el MODO INIVIDUAL. Por ejemplo, si usted esta en el MODO BANCO y cambia de presets, la pedalera recibirá las actualizaciones de cada cambio de los pedales individuales (on/off) y los reflejará en los LEDs cuando usted cambie al MODO INDIVIDUAL. De esta forma sabrá el estado de los efectos sin tener que mirar la interfaz gráfica en su Monitor.

# MEDIDAS
Entrar a: https://app.sketchup.com

Abrir el archivo CON EXTENSIÓN ".skp" que se encuentra en la carpeta Miscellanea.

# MATERIALES
Este proyecto pretende usar materiales reciclados, quien escribe no responde por los daños económicos que puedan causar los detalles descriptos en este apartado:

1- Arduino Nano u otra placa programable con Arduino IDE y con disponibilidad de 17 pines digitales: la conexión a la PC se hace por USB, luego usar ttymidi (en GNU/Linux https://github.com/moddevices/mod-ttymidi es fácil de compilar) para simular un puerto MIDI (o Hairless MIDI to Serial).

2- Perfil de Chapa Galvanizada de 40,5 x 9,7 cm (Los suelen tirar en la obras de construcción): Si se lija se puede lograr hasta un brillo espejo, pero suele oxidarse fácilmente y requiere de constante mantenimiento.

3- Tubo PVC 110x2,5 mm (se corta y da la forma del pedal con calor, por ejemplo con una plancha para ropa)

4- Un retazo de madera para dar la forma interna del pedal (lijando), se usará para moldear el PVC.

5- Chapa fina (puede ser de lata de gaseosa o cerveza, lijar pintura para asegurarse de que conducirá energía) que se pegará (con Cianoacrilato – Gotita en algunos países) por encima del PVC y conducirá la señal Digital de los Pines. Esta chapa chocará con el perfil de metal (punto 2) que conducirá GND y así encenderá y apagará el Pedal. Si pinta el perfil de metal entonces tendrá que, colocar otra chapa fina por debajo del pedal de PVC que conducirá el GND para que puede tomar contacto con la señal digital.

6- 10 LEDs. (para los Pedales se usaron LEDs Blancos provenientes de una Luz de Emergencia en desuso, para el resto se usaron LEDs azules de mouse óptico y Joystick de PS2)

7- Resistencias 220ohms (o mayor valor si no tiene disponibles estas), puede colocar o no estas resistencias a los LEDS (entre la salida del PIN digital de Arduino y el LED), en general es recomendable colocarlas pero, si tiene muchos LEDs para reciclar puede probar esto: si los LEDs calientan coloque resistencias, de lo contrario no serían necesarias.

8- Un pulsador de CPU que se usara para el cambio entre MODO BANCO y MODO INDIVIDUAL.

9- 12 Tornillos (con tuercas) de 3 milímetros de diámetro por 8mm de largo aprox.: se usaran para ajustar los pedales al perfil de metal, tenían un costo de AR$2 en el primer trimestre del 2021.

10- Herramientas (caladora de mano o eléctrica, taladro, lijadora, limas, etc.), lijas distintos granos y mechas para taladro de distintas medidas.

-Otros- Alternativamente puede usar: 
Conector USB tipo B: reciclado de impresora o modem para no conectar directamente Arduino a la PC. 
Switch (on/off): reciclado de un Hub USB para encender y apagar la pedalera.
Porcelana fría: para dar forma al soporte de los LEDs en la parte interior del perfil de chapa galvanizada.
<img src="https://raw.githubusercontent.com/fernando-inf/ARDUINO-GUITARIX-MIDI_PEDALBOARD/main/ARDUINO-GUITARIX-MIDI_PEDALBOARD/Miscellanea/PedalBoardMIDI-5.png" width="100%"></img> 

# ADVERTENCIAS/ACLARACIONES
- Luego de hacer pruebas exhaustivas se puede decir que: Si usted en Guitarix añadió un efecto, luego le asigno un MIDI CC y luego quito este efecto: es recomendable eliminar el MIDI CC asignado en la pestaña Motor-> Controlador MIDI. Así, se determino que se evita un bucle infinito de entradas y salidas de señales MIDI (si usted no elimina el CC asignado, Guitarix continuará enviando la señal MIDI, repetidas veces) ya que el Código de este PedalBoard habilita MIDI THRU para la correcta actualización de los preset con cada cambio de los mismos. Si se envían señales repetidas de un mismo MIDI CC se produce el bucle infinito (ver: https://github.com/brummer10/guitarix/issues/80).

- La Chapa fina de lata de gaseosa mencionada en la sección  "Materiales", no ha sido probada en este proyecto (se uso otra placa antigua que se tenia disponible). Se puede notar que tiene mucha flexibilidad y se parte fácilmente al doblarla completamente, sin embargo es viable probarla ya que parece ser una buena alternativa de fácil disponibilidad.

- Considere usar Noise Repellent como Reductor de Ruido (No es puerta de Ruido): https://github.com/lucianodato/noise-repellent, si bien provoca latencia, vale la pena probarlo.

- MIDI DIN CONNECTOR: Si usted usará conexión MIDI mediante conector MIDI DIN a un Rack o pedalera, necesitará elaborar un circuito eléctrico adicional, especialmente para la recepción de mensajes MIDI por parte de Arduino. Existen diagramas de ejemplos en la web, búsquelos.

# OTRA INFORMACIÓN
Abra el archivo ARDUINO-GUITARIX-MIDI_PEDALBOARD.ino con Arduino IDE. En la primer pestaña encontrará los pines asignados a LEDs y Pedales. Todos los Pines y señales MIDI CC son modificables pero, no realice ningún cambio sin antes hacer una copia de los archivos. Puede usar simuladores (SimulIDE) y el Debug de Hairless MIDI to Serial para probar los cambios que realice.

Ver la simulación en SimulIDE para entender mejor la asignación de Pines:

`byte buttonPin[] = {2, 3, 4, 5, 6, 7, 8}; //{D2, D3,.........,D8}`

`const byte LED[] = {9, 10, 11, 12, 13, A0, A1,A2, A3, A4, A5}; //{D9, D10,.........,A5}`

`const byte CC[] = {51, 52, 53, 54, 55, 56}; // Numero de Control Change para cada pulsador/pedal D3, D4,..., D8.`
  
Si usa ttymidi en GNU/Linux ejecutelo así (de no funcionar o funcionar mal en primera instancia):

`$ ttymidi -s /dev/ttyUSB0 --baudrate=115200`

Recuerde que ttymidi solo se iniciará si conecto previamente Arduino al puerto usb. Así mismo verifique que previamente no ha quedado abierta otra instancia de ttymidi, de ser así, ciérrela en su Gestor/Administrador de tareas.

Si usa Hairless-Midiserial (en formato compilado solo está disponible para sistemas operativos de 32 bits en GNU/Linux, tendrá que instalar librerías adicionales para usarlo en sistemas de 64bits) habilite la linea `MIDI.turnThruOff()` en la pestaña SETUP;


Tenga la gentileza de informarme sobre los avances significativos que haga usted en el proyecto y de enviarme fotos de su versión de esta pedalera.

fernando-inf@hotmail.com

2021 @CopyLeft
