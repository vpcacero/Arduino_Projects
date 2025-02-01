This project establishes a serial communication interface between a FastAPI backend and an Arduino board to remotely control an LED via HTTP requests. The FastAPI server sends commands to the Arduino through a serial connection, allowing users to turn the LED on and off using API endpoints.

Objective: 
- Implement a FastAPI backend to communicate with an Arduino via serial communication.
- Control an LED on pin 11 of the Arduino by sending HTTP requests (/led/on and /led/off).
- Demonstrate real-time interaction between a web server and physical hardware.

Instructions: 
1. Hardware Setup:
- Connect an LED to pin 11 on the Arduino with a current-limiting resistor.
- Ensure the Arduino is connected to the computer via USB.

2. Software Setup:
- Install FastAPI and pyserial on your system using "pip install fastapi uvicorn pyserial"
- Ensure the Arduino board is correctly recognized by your system.
- Upload the arduino.ino sketch to the Arduino using the Arduino IDE.

How to Run: 
1. Start the FastAPI Server:
uvicorn connection:app --reload

2. Test LED Control:
Turn LED ON using: curl -X POST http://127.0.0.1:8000/led/on
Turn LED OFF using: curl -X POST http://127.0.0.1:8000/led/off
Alternatively, use Postman or a web browser to send POST requests.

3. Shutdown the Server:
- Stop the FastAPI server using Ctrl + C in the terminal.
- The Arduino LED should respond based on the last received command.
