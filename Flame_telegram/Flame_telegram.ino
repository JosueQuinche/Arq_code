const int smokepin = 4;
const int threshold = 500; // Ajusta este umbral según la sensibilidad del sensor
bool isDetectingSmoke = false;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analogValue = analogRead(smokepin);

  if (analogValue > threshold) {
    if (!isDetectingSmoke) {
      Serial.println("¡Detectado humo!");
      isDetectingSmoke = true;
    }
  } else {
    if (isDetectingSmoke) {
      Serial.println("No hay humo.");
      isDetectingSmoke = false;
    }
  }

  delay(1000); // Espera 1 segundo antes de la próxima lectura
}