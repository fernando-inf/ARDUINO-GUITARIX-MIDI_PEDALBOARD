
void setup() 
              {
                MIDI.begin(MIDI_CHANNEL_OMNI);//MIDI_CHANNEL_OMNI= Lee los mensajes de todos los Canales, si esta vacio solo lee el Canal 1 en MIDI IN.
                Serial.begin(115200); // Si conecta directo a MIDI sin serial: 31250
                //MIDI.turnThruOff(); //Evita que la señales que entran vuelvan a salir.
                MIDI.setHandleControlChange(MIDI_Input_CC); //Trabaja en la recepciòn de mensajes MIDI ControlChange junto con el Void MIDI_Input
                MIDI.setHandleProgramChange(MIDI_Input_ProgramChange);//Trabaja en la recepciòn de mensajes MIDI ProgramChange junto con el Void MIDI_Input
                for (int x = 0; x < 7; x++) //Para 7 Pines Digitales, subir valor si se colocan mas pines en "const int buttonPin[]" lo mismo para los LED "const int LED[]"
                    {pinMode(buttonPin[x], INPUT_PULLUP);}// X numero de PINES DIGITALES para los Pulsadores
              
                for (int i = 0; i < 11; i++) 
                    {pinMode(LED[i],OUTPUT);}//i = numero de PINES DIGITALES para los LED
              
                //SI USA LCD 16x2 CON ARDUINO MEGA
                lcd.begin(16, 2);
                lcd.setCursor(0,0);
                
                //Mensajes MIDI enviados al inicio
                delay(500);
                MIDI.sendControlChange(MSB_LSB, 0, Ch); //MIDI.sendControlChange(cc, NumBank, ch); CC=0 es MSB, CC=32 es LSB.
                MIDI.sendProgramChange(0, Ch); //Inicia en el Banco 0 y Preset 0.
                //delay(100);
                //MIDI.sendControlChange(1, ValOn, Ch); //Trabaja con Noise Repellent con Noise_Learn- Al iniciarse la pedalera envia un CC1 con Valor ON para iniciar la lectura de ruido por 100ms (delay). Se coloca esta linea aqui para que se ejecute solo una vez al inicio.
                //delay(100);
                //MIDI.sendControlChange(1, ValOff, Ch); // Luego de 100ms se apaga la toma de muestra de Ruido con un Valor OFF.
                
              }

void loop() 
              {
                MIDI.read(); //Lee todo el tiempo los valores MIDI que el Software esta enviando a Arduino- Lee los mensajes de todos los Canales, si quiere leer solo el Canal 1 = MIDI.read(1)
                button1 ();//LLama a la funciones "void buttonX" para ejecutarse en este Loop- un button por cada pulsador conectado
                button2 ();
                button3 ();
                button4 ();
                button5 ();
                button6 ();
                button7 ();
                BlinkLED();
                //PoteButton(); //Futura Expansión
              }
