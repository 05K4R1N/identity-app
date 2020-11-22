volatile int rate[10];     // usado para mantener los últimos diez valores IBI
volatile unsigned long sampleCounter = 0;// usado para determinar el tiempo de pulso
volatile unsigned long lastBeatTime = 0;// usado para encontrar el intervalo entre latidos
volatile int P =512;      // usado para encontrar el pico en la onda del pulso
volatile int T = 512;          // se usa para encontrar el canal en la onda de pulso
volatile int thresh = 512;             // usado para encontrar momentos instantáneos de latidos del corazón
volatile int amp = 100;                  // usado para mantener la amplitud de la forma de onda del pulso
volatile boolean firstBeat = true;        /// se utiliza para inicializar la matriz de velocidad, así que iniciamos con BPM razonables
volatile boolean secondBeat = true;       // se utiliza para inicializar la matriz de velocidad, así que iniciamos con BPM razonables


void interruptSetup(){     
  // Inicializa Timer2 para lanzar una interrupción cada 2 ms.
  TCCR2A = 0x02;     // DESACTIVAR PWM EN LOS PINS DIGITALES 3 Y 11, Y ENTRAR EN EL MODO CTC
  TCCR2B = 0x06;     // NO FUERCE COMPARAR, 256 PRESCALER
  OCR2A = 0X7C;      // ESTABLECE EL TOPE DE LA CUENTA A 124 PARA 500Hz TASA DE MUESTRA
  TIMSK2 = 0x02;    // HABILITAR LA INTERRUPCIÓN EN EL MATCH ENTRE TIMER2 Y OCR2A
  sei();            // ASEGÚRESE DE QUE LOS INTERRUPTOS GLOBALES ESTÁN HABILITADOS
} 


// ESTE ES LA RUTINA DEL SERVICIO DE INTERRUPCIÓN TIMER 2.
// Timer 2 se asegura de que tomemos una lectura cada 2 milisegundos
ISR(TIMER2_COMPA_vect){                        // se dispara cuando el Timer2 cuenta hasta 124
    cli();                                    // inhabilitar interrupciones mientras hacemos esto
    Signal = analogRead(pulsePin);             // lee el sensor de pulso
    sampleCounter += 2;                       // hacer un seguimiento del tiempo en mS con esta variable
    int N = sampleCounter - lastBeatTime;       // monitorea el tiempo desde el último tiempo para evitar el ruido

// encuentra el pico y el canal de la onda del pulso
    if(Signal < thresh && N > (IBI/5)*3){       // Evita los ruidos dicróticos esperando 3/5 del último IBI
        if (Signal < T){                      // T es el canal
            T = Signal;                        // mantener un registro del punto más bajo en la onda de pulso
         }
       }
      
    if(Signal > thresh && Signal > P){          // condición de thresh ayuda a evitar el ruido
        P = Signal;                            // P es el pico
       }                                       // mantener un registro del punto más alto en la onda de pulso
    
// AHORA ES HORA DE BUSCAR EL LATIDO DEL CORAZON
// la señal aumenta de valor cada vez que hay un pulso
if (N > 250){                                  // evitar el ruido de alta frecuencia
  if ( (Signal > thresh) && (Pulse == false) && (N > (IBI/5)*3) ){        
    Pulse = true;                               // establece la bandera de Pulso cuando creemos que hay un pulso

    IBI = sampleCounter - lastBeatTime;        // medir el tiempo entre tiempos en mS
    lastBeatTime = sampleCounter;              // mantener un registro del tiempo para el siguiente pulso
         
         if(firstBeat){                       // si es la primera vez que encontramos un tiempo, si firstBeat == TRUE
             firstBeat = false;                // borrar la bandera de FirstBeat
             return;                          // El valor de IBI no es confiable, por lo que descartarlo
            }   
         if(secondBeat){                       // si este es el segundo tiempo, si secondBeat == TRUE
            secondBeat = false;                 // borrar la bandera de secondBeat
               for(int i=0; i<=9; i++){        // siembra el total acumulado para obtener un BPM realista en el inicio
                    rate[i] = IBI;                      
                    }
            }
          
    // mantener un total acumulado de los últimos 10 valores IBI
    word runningTotal = 0;                   // borrar la variable runningTotal

    for(int i=0; i<=8; i++){                // cambiar datos en la matriz 
          rate[i] = rate[i+1];             // y soltar el valor IBI más antiguo
          runningTotal += rate[i];        // sumar los 9 valores más antiguos de IBI
        }
        
    rate[9] = IBI;                          // agregar el último IBI a la matriz
    runningTotal += rate[9];              // agregar el último IBI a runningTotal
    runningTotal /= 10;                    // promediar los últimos 10 valores IBI
    BPM = 60000/runningTotal;               // ¿Cuántos latidos pueden caber en un minuto? eso es BPM!
    QS = true;                              // establecer la bandera de Quantified Self 
  // LA BANDERA QS NO ESTÁ BORRADA DENTRO DE ESTE ISR
    }                       
}

  if (Signal < thresh && Pulse == true){     // cuando los valores bajan, el tiempo termina
     
      Pulse = false;                         // restablecer la bandera de pulso para que podamos hacerlo de nuevo
      amp = P - T;                           // obtener amplitud de la onda de pulso
      thresh = amp/2 + T;                   // ajustar el tresh al 50% de la amplitud
      P = thresh;                            // restablecer estos para la próxima vez
      T = thresh;
     }
  
  if (N > 2500){                           // si pasan 2.5 segundos sin un tiempo
      thresh = 512;                         // establecer el valor predeterminado de tresh
      P = 512;                              // establecer P predeterminado
      T = 512;                               // establecer T predeterminado
      lastBeatTime = sampleCounter;         // actualizar lastBeatTime
      firstBeat = true;                      // configúralos para evitar el ruido
      secondBeat = true;                    // cuando recuperemos el latido del corazón
     }
  
  sei();                                    // ¡Habilita las interrupciones cuando hayas terminado!
}// end isr
