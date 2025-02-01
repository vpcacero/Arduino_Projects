#define PHOTORESISTOR_PIN A2
#define LED_PIN 12

const int BRIGHTNESS_THRESHOLD = 220;
bool blinking = false; 

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = readBrightness();

  Serial.print("Brightness: ");
  Serial.println(sensorValue);

  
  if (sensorValue > BRIGHTNESS_THRESHOLD && !blinking) {
    blinking = true;  
  }

  
  if (blinking) {
    indicateFire();
  } else {
    digitalWrite(LED_PIN, LOW); 
  }

  
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');  
    command.toLowerCase();  
    if (command == "stop") {
      blinking = false;  
      digitalWrite(LED_PIN, LOW);  
      Serial.println("Blinking stopped.");
    }
  }

  delay(1000); 
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
}
