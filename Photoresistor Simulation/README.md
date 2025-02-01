This Arduino program uses a photoresistor to detect ambient light levels and triggers an LED blinking sequence if the brightness exceeds a set threshold. The system continuously monitors brightness, prints real-time readings to the serial monitor, and allows the user to stop the blinking via serial input.  

Objective:   
- Detect changes in ambient light using a photoresistor.  
- Implement a blinking LED alert when brightness surpasses a threshold.  
- Provide serial communication feedback for monitoring sensor values.  
- Allow manual control to stop the blinking sequence via serial input.  

Instructions: 
1. Connect a photoresistor to A2 and an LED to pin 12 on the Arduino board.  
2. Upload the code to the Arduino board using the Arduino IDE.  
3. Open the Serial Monitor to view brightness readings and control the LED.  

How to Run: 
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) if not already installed.  
2. Connect the Arduino board to your computer via USB.  
3. Open the .ino file in the Arduino IDE.  
4. Select the correct board and port under Tools > Board and Tools > Port.  
5. Click Upload to compile and upload the code.  
6. Open the Serial Monitor (Ctrl + Shift + M) to observe brightness readings.  
7. If brightness exceeds the threshold, the LED will blink rapidly.  
8. To stop the blinking, type "stop" in the Serial Monitor and press Enter.
