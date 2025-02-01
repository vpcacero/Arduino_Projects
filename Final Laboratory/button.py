import serial
import time
import requests

import aiohttp

# Replace with your Arduino's port
arduino_port = "COM4"  # Example: "/dev/ttyUSB0" for Linux/Mac
baud_rate = 9600  # Match the baud rate in Arduino code

# API Endpoint
api_url = "http://172.20.10.2:8000/final_lab"  # Replace with your API endpoint

# Establish serial connection
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Wait for the connection to initialize
print("Connection established. Waiting for button clicks...")

try:
    while True:
        if ser.in_waiting > 0:  # Check if data is available
            data = ser.readline().decode('utf-8').strip()  # Read and decode data

            if data == "group2_on":  # LED ON
                print("LED ON Command Received")
                # Call the API with the "group2_on" state
                params = {"groupName": "group2_on"}
                response = requests.get(api_url, params=params, json={"status": "success", "message": "group2_on"})
                print(response)
                if response.status_code == 200:
                    print("API called successfully for LED ON!")
                else:
                    print(f"API call failed with status code: {response.status_code}")

            elif data == "group2_off":  # LED OFF
                print("LED OFF Command Received")
                # Call the API with the "group2_off" state
                params = {"groupName": "group2_off"}
                response = requests.get(api_url, params=params, json={"status": "success", "message": "group2_off"})
                print(response)
                if response.status_code == 200:
                    print("API called successfully for LED OFF!")
                else:
                    print(f"API call failed with status code: {response.status_code}")

except KeyboardInterrupt:
    print("\nExiting...")

finally:
    ser.close()  # Close the serial connection