This project involves creating a system that detects button presses through an Arduino, sending the button's state to a Python script. The script then triggers an API call based on the button's state, with the other device connected via Wi-Fi or Hotspot controlling an LED on a breadboard.

Objective:
The goal of this project is to design a system where button presses on an Arduino are detected and communicated to a Python script, which calls an API to control an LED. The connection to the external device is made using either Wi-Fi or Hotspot, with both devices running specific Arduino code.

How to Run:
1. Connect the button to the designated pin on the Arduino.
2. Upload the provided Arduino code to your board.
3. Run the Python script on your computer.
4. Press the button to send its state to the script, triggering the API call to control the LED.
