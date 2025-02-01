int ledPins[] = {12, 11, 10, 9, 8};  //LED pins
int pwdLedPins[] = {11, 10, 9, 6, 5};  //PWM pins
int brightness = 0;
int maxBrightness = 255;  //max brightness for pwm 
int delayTime = 10;  //delay

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT); //setting pins as output
  }
}

void loop() {
  int i = 0;
  brightness = 0;

  //slowly turning on all LEDs
  while (i < 5) {
    while (brightness <= maxBrightness) {
      analogWrite(ledPins[i], brightness);  //increase brightness
      delay(delayTime);
      brightness++;
    }
    i++;
    brightness = 0;
  }

  delay(1000);  //keeping all LEDs on 

  i = 0;  // reset index for turning off LEDs
  brightness = maxBrightness;

  // slowly turning off all LEDs
  while (i < 5) {
    while (brightness >= 0) {
      analogWrite(ledPins[i], brightness);
      delay(delayTime);
      brightness--;
    }
    i++;
    brightness = maxBrightness;
  }

  delay(1000);
}