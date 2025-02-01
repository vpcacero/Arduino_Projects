const int buttonPin = 12; // Connect your button to pin 12
int buttonState = 0;

void setup() {
    pinMode(buttonPin, INPUT); // Configure pin as input
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    buttonState = digitalRead(buttonPin); // Read button state (HIGH/LOW)
    
    // Send "group2_on" or "group2_off" based on button state
    if (buttonState == HIGH) { // Button pressed (LOW due to pull-up resistor)
        Serial.println("group2_on"); // Send "group2_on" when pressed
    } else {
        Serial.println("group2_off"); // Send "group2_off" when not pressed
    }
    
    delay(1000); // Adjust as needed to avoid spamming data
}