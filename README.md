# ARDUINO_Examples
Repositorio con ejemplos de proyectos con arduino

## Control_Motor_CC_con_Potenciometro
Proyecto para controlar el sentido y velocidad de giro con Arduino.
### Componentes necesarios:
- `1x` Arduino Uno.
- `2x` pulsadores.
- `1x` Potenciómetro
- `2x` resistencias 10k para los pull-down de los pulsadores.
- `1x`L293D DIP-16, Driver doble puente H.  
- `1x` Montor CC 5VDC.

## SensorDistancia_Luz_Servo_LCD
Diseñar un sistema embebido con **Arduino Uno** que integre:
- Un sensor **ultrasónico HC-SR04** para medir distancias.
- Un **LDR** para evaluar la iluminación ambiente.
- Un **servomotor** cuya posición varía en función de la distancia medida.
- Un conjunto de **LEDs** indicadores que actúan como semáforo.
- Una **pantalla LCD 16x2 I2C** para visualizar información en tiempo real.

### Componentes necesarios
- `1x` Arduino Uno  
- `1x` Sensor ultrasónico HC-SR04  
- `1x` LDR (fotorresistencia)  
- `1x` Resistencia de 10kΩ (para divisor con LDR)  
- `1x` Pantalla LCD 16x2 con módulo I2C (dirección 0x27)  
- `1x` Servo motor (PWM control)  
- `4x` LEDs:
  - LED Rojo (pin 5)  
  - LED Amarillo (pin 4)  
  - LED Verde (pin 3)  
  - LED para oscuridad (pin 2)  
- `Jumpers` y `Protoboard`

## Sensor_luz_tem_hum_con_LDC_Serial
Este proyecto permite medir y visualizar en tiempo real la **temperatura**, **humedad** y el **nivel de luz ambiental** utilizando un sensor **DHT22** y una **fotorresistencia (LDR)**, mostrando la información en una pantalla **LCD I2C**. Además, los datos se pueden solicitar vía puerto **serie** mediante un comando y se devuelven en formato **JSON**.


### 📦 Componentes necesarios
- Arduino UNO (o compatible)
- Sensor DHT22
- Fotorresistencia (LDR) + resistencia
- Pantalla LCD I2C 16x2
- LED rojo
- Cables de conexión
- Protoboard

### ⚙️ Funcionalidades
- Lectura de temperatura y humedad (sensor DHT22)
- Lectura del nivel de luz (entrada analógica con LDR)
- Visualización de los valores en pantalla LCD
- Activación del LED si hay baja iluminación
- Envío de datos por puerto serie en formato JSON cuando se recibe el comando `getData`



