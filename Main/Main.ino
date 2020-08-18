#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int pulsePin = 0;                   // Sensor de Pulso conectado al puerto A0
// Estas variables son volatiles porque son usadas durante la rutina de interrupcion en la segunda Pestaña
volatile int BPM;                   // Pulsaciones por minuto
volatile int Signal;                // Entrada de datos del sensor de pulsos
volatile int IBI = 600;             // tiempo entre pulsaciones
volatile boolean Pulse = false;     // Verdadero cuando la onda de pulsos es alta, falso cuando es Baja
volatile boolean QS = false;        // Verdadero cuando el Arduino Busca un pulso del Corazon

void setup() {
  Serial.begin(9600);
  interruptSetup();                  // Configura la interrucion para leer el sensor de pulsos cada 2mS  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  
}

void loop() {
  int pulso = analogRead(A0);
  if(pulso < 480 || pulso > 680 ){
    BPM = 0;
  }
  if (QS == true){                    // Bandera del Quantified Self es verdadera cuando el Arduino busca un pulso del corazon
    QS = false;                       // Reset a la bandera del Quantified Self 
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("V=");
  display.setCursor(40,10);
  display.println(0);
  display.setCursor(75,10);
  display.println("km/h");
  display.setCursor(0, 25);
  display.println("P= ");
  display.setCursor(30, 25);
  display.println(BPM);
  display.setCursor(68, 25);
  display.println("L/min");
  display.display(); 
  delay(2000);
}
