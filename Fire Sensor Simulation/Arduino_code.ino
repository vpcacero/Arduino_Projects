#define TEMP_SENSOR_PIN A0
#define PHOTORESISTOR_PIN A2
#define LED_PIN 12

const int TEMP_THRESHOLD = 50;
const int BRIGHTNESS_THRESHOLD = 220;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float analogValue = readTemperature(); 
  int sensorValue = readBrightness(); 

  Serial.print("Temperature: ");
  Serial.print(analogValue);
  Serial.print(" °C, Brightness: ");
  Serial.println(sensorValue);

  if (analogValue > TEMP_THRESHOLD && sensorValue > BRIGHTNESS_THRESHOLD) {
    indicateFire();
  } else {
    digitalWrite(LED_PIN, LOW);  
  }

  delay(1000); 
}

float readTemperature() {
  int temperature = analogRead(TEMP_SENSOR_PIN);
  float tempC = (temperature * 5.0 / 1024.0 - 0.5) * 100.0;
  return tempC;
}

int readBrightness() {
  return analogRead(PHOTORESISTOR_PIN); 
}

void indicateFire() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH); 
    delay(100);
    digitalWrite(LED_PIN, LOW); 
    delay(100); 
  }
  digitalWrite(LED_PIN, LOW); 
}
