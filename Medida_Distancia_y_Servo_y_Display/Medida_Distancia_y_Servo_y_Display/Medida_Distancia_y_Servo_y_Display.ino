#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_SERVO 10
#define PIN_ECHO 12
#define PIN_TRIGGER 13
#define PIN_LED_ROJO 5
#define PIN_LED_AMARILLO 4
#define PIN_LED_VERDE 3
#define PIN_LED_OSCURIDAD 2
#define PIN_RLD A0

Servo MiServo;
LiquidCrystal_I2C MiLCD(0x27,16,2);

int intensidadLuz;
int anguloServo;
float tiempo;
float distancia;

void setup() {
  // put your setup code here, to run once:
  MiServo.attach(PIN_SERVO);
  Serial.begin(115200);
  MiLCD.init();
  MiLCD.backlight();

  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LED_AMARILLO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_OSCURIDAD, OUTPUT);
  
  pinMode(PIN_RLD, INPUT);

  MiLCD.clear();
}

void loop() {
  
  //Medida valor RLD
  
  intensidadLuz = analogRead(PIN_RLD);
  if(intensidadLuz < 750)
    digitalWrite(PIN_LED_OSCURIDAD, HIGH);
  else
    digitalWrite(PIN_LED_OSCURIDAD, LOW);
  
  Serial.print("Intensidad Luz:");
  Serial.println(intensidadLuz);
  delay(500);
  
  //Medida distancia
  digitalWrite(PIN_TRIGGER,LOW);
  delay(100);

  digitalWrite(PIN_TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER,LOW);

  tiempo = pulseIn(PIN_ECHO,HIGH);
  distancia = (tiempo * 0.0343)/2;

  // Mostrar distancia
  MiLCD.setCursor(0, 0);
  MiLCD.println("Distancia medida");
  MiLCD.setCursor(0, 1);
  MiLCD.print(distancia);
  MiLCD.print(" cm");
  
  // ALGORITMO
  
  if(distancia < 50){
    digitalWrite(PIN_LED_ROJO, HIGH);
    digitalWrite(PIN_LED_AMARILLO, HIGH);
    digitalWrite(PIN_LED_VERDE, HIGH);
  }
  else if(distancia < 100){
  	digitalWrite(PIN_LED_ROJO, LOW);
    digitalWrite(PIN_LED_AMARILLO, HIGH);
    digitalWrite(PIN_LED_VERDE, HIGH);
  }
  else if(distancia < 200){
  	digitalWrite(PIN_LED_ROJO, LOW);
    digitalWrite(PIN_LED_AMARILLO, LOW);
    digitalWrite(PIN_LED_VERDE, HIGH);
  }
  else{
    digitalWrite(PIN_LED_ROJO, LOW);
    digitalWrite(PIN_LED_AMARILLO, LOW);
    digitalWrite(PIN_LED_VERDE, LOW);
  }
  
  
  // Mapear servo en funcion de distancia
  anguloServo = map(distancia, 30, 300, 0, 179);
  MiServo.write(anguloServo);
}
