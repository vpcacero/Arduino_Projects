This Arduino-based system uses a photoresistor to measure light intensity and activate different LEDs based on predefined thresholds. It can operate in manual mode, where users set their own thresholds, or in automatic mode, where thresholds adjust based on the detected light conditions.

Objective:
To create an adaptive lighting system that provides visual feedback using LEDs to indicate the current light intensity, with flexible configuration through serial commands.

How to Run:
1. The system reads the amount of light in the environment using a light sensor.
2. Based on the light level, it turns on one of three LEDs: green for low light, yellow for moderate light, and red for bright light.
3. You can switch between automatic mode, where the system adjusts the light thresholds itself, or manual mode, where you can set your own light levels.
4. The system shows the current light level, mode, and which LED is on in the Serial Monitor.
5. It listens for commands through a connected computer to change the settings.
