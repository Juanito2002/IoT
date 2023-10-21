#include <LiquidCrystal.h>

int led1 = 13; // Pin del LED rojito
int ventilador = 10; // Pin del ventilador (Motor de CC)
int sensorValue; // Almacena el valor de llegada del sensor
float temp = 0; // Almacena valor calculado de la temperatura
int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(ventilador, OUTPUT);
  Serial.begin(9600); // Baudios
  lcd_1.begin(16, 2); // Configura el número de columnas y filas en el LCD.
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  // Convertir el valor de entrada a grados centígrados
  temp = (sensorValue * (500.0 / 1024.0)) - 50.0; // Fórmula para el sensor de temperatura LMP36
  Serial.print("Temperatura en Grados Centígrados: ");
  Serial.println(temp);

  // Validación 1
  if (temp <= 10) {
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
    digitalWrite(ventilador, LOW);
  } 
  // Validación 2
  else if (temp > 10 && temp <= 25) {
    digitalWrite(led1, LOW);
    digitalWrite(ventilador, LOW);
  } 
  // Validación 3
  else if (temp >= 26) {
    digitalWrite(led1, HIGH);
    digitalWrite(ventilador, HIGH);
  }

  // aqui convierte el valor de la temperatura a una cadena de caracteres
  char tempStr[10]; // arreglo de caracteres para almacenar la temperatura como cadena
  dtostrf(temp, 4, 2, tempStr); // aqui convierto el valor flotante a cadena de caracteres con 2 decimales

  // Mostrar la temperatura en el LCD
  lcd_1.clear(); // Limpiar el LCD
  lcd_1.setCursor(0, 0); // Establecer el cursor en la primera fila
  lcd_1.print("Temp: "); // Mostrar etiqueta
  lcd_1.print(tempStr); // Mostrar la temperatura como cadena
  lcd_1.print(" C"); // Mostrar el símbolo de grados Celsius
  delay(1000);
  seconds += 1;
}

