# 🧰 ARDUINO_Examples

Repositorio con ejemplos prácticos de proyectos desarrollados con **Arduino**, orientados a control, sensado e interacción con el entorno físico.

---

## 🔧 Proyecto 1: Control de Motor de Corriente Continua con Potenciómetro

Proyecto para controlar el **sentido** y la **velocidad de giro** de un motor DC mediante un potenciómetro y dos pulsadores.

### 🧩 Componentes necesarios:
- `1x` Arduino UNO  
- `2x` Pulsadores  
- `1x` Potenciómetro  
- `2x` Resistencias de 10kΩ (pull-down para pulsadores)  
- `1x` L293D DIP-16 (Driver doble puente H)  
- `1x` Motor DC 5V

---

## 🌐 Proyecto 2: Sensor de Distancia, Luz, Servo y LCD

Sistema embebido con **Arduino UNO** que integra sensores de distancia e iluminación, un servomotor, indicadores LED y una pantalla LCD para mostrar datos en tiempo real.

### 📌 Funcionalidad:
- El sensor ultrasónico **HC-SR04** mide la distancia a un objeto.
- El **LDR** evalúa la luz ambiental.
- Un **servomotor** ajusta su posición según la distancia.
- Un conjunto de **LEDs** funciona como semáforo.
- Los valores se muestran en una **pantalla LCD I2C 16x2**.

### 🧩 Componentes necesarios:
- `1x` Arduino UNO  
- `1x` Sensor ultrasónico HC-SR04  
- `1x` Fotorresistencia (LDR)  
- `1x` Resistencia de 10kΩ (para divisor con LDR)  
- `1x` Pantalla LCD 16x2 con módulo I2C (dirección 0x27)  
- `1x` Servo motor (controlado por PWM)  
- `4x` LEDs:
  - LED rojo (pin 5)  
  - LED amarillo (pin 4)  
  - LED verde (pin 3)  
  - LED de oscuridad (pin 2)  
- Cables (`jumpers`) y protoboard

---

## 🌡️ Proyecto 3: Monitor de Luz, Temperatura y Humedad con LCD y Salida Serial

Sistema que mide y visualiza en tiempo real la **temperatura**, **humedad** y el **nivel de luz ambiental**, con salida en pantalla y opción de solicitud remota por puerto serie.

### 📌 Funcionalidad:
- Lectura de temperatura y humedad con sensor **DHT22**
- Lectura del nivel de luz mediante **LDR**
- Visualización de valores en una **pantalla LCD I2C**
- Activación de un **LED** si el nivel de luz es bajo
- Envío de datos en formato **JSON** por puerto serie al recibir el comando `getData`

### 🧩 Componentes necesarios:
- `1x` Arduino UNO (o compatible)  
- `1x` Sensor DHT22  
- `1x` Fotorresistencia (LDR) + resistencia  
- `1x` Pantalla LCD I2C 16x2  
- `1x` LED rojo  
- Cables de conexión  
- Protoboard

---

## 📁 Estructura del repositorio

Cada carpeta del repositorio contiene:
- Código fuente (`.ino`)
- Diagrama o esquema del circuito (si aplica)
- Descripción del proyecto en el archivo `README.md`


## 📌 Licencia

Este repositorio es de uso libre con fines **educativos y personales**. No se permite su uso comercial sin autorización expresa.





