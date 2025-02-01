void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(11, HIGH);
    } else if (command == '0') {
      digitalWrite(11, LOW);
    }
  }
}