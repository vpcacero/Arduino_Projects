This Arduino program monitors temperature and ambient light levels using a temperature sensor and a photoresistor. If the temperature exceeds a defined threshold and the brightness level is high, the system triggers a fire indication by blinking an LED rapidly. The program continuously reads sensor values, prints them to the serial monitor, and evaluates conditions to determine whether to activate the LED warning system.  

Objective:    
- Detect temperature and brightness changes using sensors.  
- Implement a fire detection system based on predefined thresholds.  
- Utilize serial communication to display real-time sensor readings.  
- Control an LED as a visual indicator for potential fire hazards.  

Instructions: 
1. Connect a temperature sensor to A0 and a photoresistor to A2 on the Arduino board.  
2. Attach an LED to pin 12 with a suitable resistor.  
3. Upload the code to the Arduino board using the Arduino IDE.  

How to Run: 
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) if not already installed.  
2. Connect the Arduino board to your computer via USB.  
3. Open the .ino file in the Arduino IDE.  
4. Select the correct "board and port" under Tools > Board and Tools > Port.  
5. Click "Upload" to compile and upload the code.  
6. Open the "Serial Monitor (Ctrl + Shift + M)" to observe temperature and brightness readings.  
7. If both temperature and brightness exceed the defined thresholds, the LED will blink rapidly to indicate potential fire detection.
