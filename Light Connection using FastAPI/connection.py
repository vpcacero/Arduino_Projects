from fastapi import FastAPI

import serial, time, threading

app = FastAPI()

arduino = None

@app.on_event("startup")
def startup_event():
    global arduino
    try:
        arduino = serial.Serial("COM3", 9600, timeout=1)
        time.sleep(2)
        print("Serial connection established")
    except serial.SerialException as e:
        print(f"Error establishing serial connection", {e})

@app.on_event("shutdown")
def shutdown_event():
    global arduino
    if arduino and arduino.is_open:
        arduino.close()
        print("Serial connection closed.")

@app.post("/led/on")
def turn_led_on():
    global arduino
    if arduino and arduino.is_open:
        arduino.write(b"1")
        return {"status": "success", "message": "LED turned ON"}
    else:
        return {"status": "error", "message": "Serial connection is not open"}
    
@app.post("/led/off")
def turn_led_off():
    global arduino
    if arduino and arduino.is_open:
        arduino.write(b"0")
        return {"status": "success", "message": "LED turned off"}
    else:
        return {"status": "error", "message": "Serial connection is not open"}