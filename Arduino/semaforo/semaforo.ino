// Definición de pines
const int pinRojo = 2;
const int pinAmarillo = 3;
const int pinVerde = 4;

// Tiempos de encendido para cada luz (en milisegundos)
const long tiempoRojo = 5000;    // 5 segundos
const long tiempoAmarillo = 2000; // 2 segundos
const long tiempoVerde = 5000;   // 5 segundos

void setup() {
  // Inicializar los pines como salidas
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
}

void loop() {
  // Encender luz verde
  digitalWrite(pinVerde, HIGH);
  delay(tiempoVerde);

  // Apagar luz verde
  digitalWrite(pinVerde, LOW);

  // Encender luz amarilla
  digitalWrite(pinAmarillo, HIGH);
  delay(tiempoAmarillo);

  // Apagar luz amarilla
  digitalWrite(pinAmarillo, LOW);

  // Encender luz roja
  digitalWrite(pinRojo, HIGH);
  delay(tiempoRojo);

  // Apagar luz roja
  digitalWrite(pinRojo, LOW);
}
