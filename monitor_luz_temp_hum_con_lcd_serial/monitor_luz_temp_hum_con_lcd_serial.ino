#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT22.h> //Modulo DHT22 de dvrrel

// Definición de pines
#define PIN_LED_ROJO 6
#define PIN_LDR A0
#define PIN_DHT 7
#define TIPO_DHT DHT22
#define DIRECCION_LCD 0x27

// Inicialización de objetos
LiquidCrystal_I2C PantallaLCD(DIRECCION_LCD, 16, 2);
DHT22 SensorDHT(PIN_DHT);

// Variables de medición
int valorAnalogico;

float nivelLuzVoltios;
float temperatura;
float humedad;

void setup() {
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LDR, INPUT);

  PantallaLCD.init();
  PantallaLCD.backlight();

  Serial.begin(115200);

  valorAnalogico = 0;
  nivelLuzVoltios = 0;
  temperatura = 0;
  humedad = 0;
}

void loop() {
  // DHT22 necesita al memos dos segundos entre lecturas
  delay(200);
  leerDatosSensores();
  avisarSiPocaLuz();

  // Mostrar datos y enviar si corresponde
  mostrarEnPantalla(nivelLuzVoltios, temperatura, humedad);
  enviarDatos(nivelLuzVoltios, temperatura, humedad);
}

void leerDatosSensores(){
  // Lectura de sensores
  valorAnalogico = analogRead(PIN_LDR);
  nivelLuzVoltios = map(valorAnalogico, 0, 1023, 0, 255) / 51.0;
  float temp = SensorDHT.getTemperature();
  //temperatura = 23.5;
  float hum = SensorDHT.getHumidity();

   if (!isnan(temp)) {
    temperatura = temp;
  } 

  if (!isnan(hum)) {
    humedad = hum;
  } 

}

void avisarSiPocaLuz(){
  // Control de LED según el nivel de luz
  if (nivelLuzVoltios < 1.2)
    digitalWrite(PIN_LED_ROJO, HIGH);
  else
    digitalWrite(PIN_LED_ROJO, LOW);
}

void mostrarEnPantalla(float luz, float temp, float hum) {
 
  PantallaLCD.setCursor(0, 0);
  PantallaLCD.print("Luz:");
  PantallaLCD.setCursor(5, 0);
  PantallaLCD.print(luz, 1);

  PantallaLCD.setCursor(0, 1);
  PantallaLCD.print("T:");
  PantallaLCD.setCursor(2, 1);
  PantallaLCD.print(temp, 1);

  PantallaLCD.setCursor(8, 1);
  PantallaLCD.print("H:");
  PantallaLCD.setCursor(10, 1);
  PantallaLCD.print(hum, 1);
}

void enviarDatos(float luz, float temp, float hum) {
  char luzStr[10], tempStr[10], humStr[10];
  char datosJSON[100];

  dtostrf(luz, 1, 2, luzStr);
  dtostrf(temp, 1, 2, tempStr);
  dtostrf(hum, 1, 2, humStr);

  snprintf(datosJSON, sizeof(datosJSON),
           "{\"Nivel_Luz\":%s,\"Temperatura\":%s,\"Humedad\":%s}",
           luzStr, tempStr, humStr);

  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "getData")
      Serial.print(datosJSON);
  }
}