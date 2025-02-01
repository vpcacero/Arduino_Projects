const int photoresistor = A0; 
const int greenLED = 11;      
const int yellowLED = 12;     
const int redLED = 13;       

int low_threshold = 40;         
int high_threshold = 70;        

String cur_mode = "MANUAL";  
String cur_env = "Clear"; 
int intensity = 0;         

void setup() {
    Serial.begin(9600);
    
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
}

void loop() {
    intensity = analogRead(photoresistor);
    int light_percentage = map(intensity, 0, 1023, 0, 100);

    if (cur_mode == "AUTOMATIC") {
        if (light_percentage < 40) {
            cur_env = "Cloudy";
            low_threshold = 0;
            high_threshold = 40;
        } else if (light_percentage < 70) {
            cur_env = "Normal";
            low_threshold = 41;
            high_threshold = 70;
        } else {
            cur_env = "Bright Sunlight";
            low_threshold = 71;
            high_threshold = 100;
        }
    }
  
  
    if (light_percentage < low_threshold) {
        activateLED(greenLED);
    } else if (light_percentage < high_threshold) {
        activateLED(yellowLED);
    } else {
        activateLED(redLED);
    }
  
  
    Serial.print("Light Intensity: ");
    Serial.print(light_percentage);
    Serial.print("%\tCurrent Mode: ");
    Serial.print(cur_mode);
    Serial.print("\tActive LED: ");

    if (light_percentage < low_threshold) {
        Serial.print("Green");
    }
    else if (light_percentage < high_threshold) {
        Serial.print("Yellow");
    }
    else {
        Serial.print("Red");
    }

    Serial.print("\tEnvironment: ");
    Serial.println(cur_env);

    processUserInput();

    delay(1000); 
}

void activateLED(int active_pin) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    
    digitalWrite(active_pin, HIGH);
}

void processUserInput() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        input.trim(); 
    
        if (input.startsWith("MODE")) {
            if (input.equals("MODE AUTO")) {
                cur_mode = "AUTOMATIC";
            } else if (input.equals("MODE MANUAL")) {
                cur_mode = "MANUAL";
            } else {
                Serial.println("Error: Wrong command");
            }
        } else if (input.startsWith("SET LOW") && cur_mode == "MANUAL") {
            low_threshold = input.substring(😎.toInt();
        } else if (input.startsWith("SET HIGH") && cur_mode == "MANUAL") {
            high_threshold = input.substring(9).toInt();
        } else {
            Serial.println("Error: Wrong command");
        }
    }
}