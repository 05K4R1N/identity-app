#include <Arduino.h>
#include <U8glib.h>

//Initialize display.
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

int pulsePin = 0;                   // Sensor de Pulso conectado al puerto A0
// Estas variables son volatiles porque son usadas durante la rutina de interrupcion en la segunda Pestaña
volatile int BPM;                   // Pulsaciones por minuto
volatile int Signal;                // Entrada de datos del sensor de pulsos
volatile int IBI = 600;             // tiempo entre pulsaciones
volatile boolean Pulse = false;     // Verdadero cuando la onda de pulsos es alta, falso cuando es Baja
volatile boolean QS = false;        // Verdadero cuando el Arduino Busca un pulso del Corazon

void setup(void)
{
    u8g.setFont(u8g_font_unifont);
    Serial.begin(9600);                // Puerto serial configurado a 9600 Baudios
    interruptSetup();                  // Configura la interrucion para leer el sensor de pulsos cada 2mS  
}
void loop(void)
{
    int pulso = analogRead(A0);
    if(pulso < 480 || pulso > 680 ){
      BPM = 0;
    }
    //Serial.print("Pulsos por Minutos = ");  Serial.println(BPM);
    Serial.println(pulso);
    if (QS == true){                       // Bandera del Quantified Self es verdadera cuando el Arduino busca un pulso del corazon
      QS = false;                          // Reset a la bandera del Quantified Self 
    }
    u8g.firstPage();
    do {
        draw();
    } while (u8g.nextPage());
    delay(100);  
    
}
void draw(void)
{
    u8g.setPrintPos(2, 15);
    u8g.print("Vel=");
    u8g.setPrintPos(2, 30);
    u8g.print("Pulso=");
    
    //velocidad
    u8g.setPrintPos(60, 15);
    u8g.print(0);
    u8g.setPrintPos(86, 15);
    u8g.print("km/h");

    //pulso
    u8g.setPrintPos(60, 30);
    u8g.print(BPM);
    u8g.setPrintPos(86, 30);
    u8g.print("lat/m");
}
