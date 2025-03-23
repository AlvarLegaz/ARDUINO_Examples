#define pulsador_derecha 2
#define pulsador_izquierda 4
#define entrada_potenciometro A0

#define giro_derecha 7
#define giro_izquierda 8
#define velocidad_giro_pwm 10

int Estado_PulsadorIzquierda = 0;
int Estado_PulsadorDerecha = 0;
int Valor_Potenciometro = 0;
int Velocidad_Giro_PWM = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pulsador_izquierda, INPUT);
  pinMode(pulsador_derecha, INPUT);
  pinMode(entrada_potenciometro, INPUT);

  pinMode(giro_izquierda, OUTPUT);
  pinMode(giro_derecha, OUTPUT);
  pinMode(enable_velocidad_giro, OUTPUT);
}

void loop() {
  Estado_PulsadorIzquierda = digitalRead(pulsador_izquierda);
  Estado_PulsadorDerecha = digitalRead(pulsador_derecha);
  Valor_Potenciometro = analogRead(entrada_potenciometro);

  Velocidad_Giro_PWM = map(Valor_Potenciometro, 0, 1023, 0, 255); // Mapear a un rango PWM
  
  if(Estado_PulsadorIzquierda == HIGH && Estado_PulsadorDerecha == LOW){
    analogWrite(enable_velocidad_giro, Velocidad_Giro_PWM);
    digitalWrite(giro_izquierda, HIGH);
    digitalWrite(giro_derecha, LOW);
  }
  else if (Estado_PulsadorIzquierda == LOW && Estado_PulsadorDerecha == HIGH){
    analogWrite(enable_velocidad_giro, Velocidad_Giro_PWM);
    digitalWrite(giro_izquierda, LOW);
    digitalWrite(giro_derecha, HIGH);
  }
  else{
    digitalWrite(enable_velocidad_giro, LOW);
    digitalWrite(giro_izquierda, LOW);
    digitalWrite(giro_derecha, LOW);
  }
}
