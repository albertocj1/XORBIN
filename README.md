# XORBIN

This Arduino project manages waste bins using ultrasonic sensors and controls servos to open/close gates for different types of waste (metal, paper, plastic). It also integrates a GSM module to send SMS alerts when bins are full.

## Components Used

- Arduino board (e.g., Arduino Uno)
- Ultrasonic sensors (3x)
- Servo motors (2x)
- GSM module (e.g., SIM800L)
- Breadboard and connecting wires
- Capacitive Sensor
- Inductive Sensor
- IR Sensor

## Libraries Required

- Servo.h
- SoftwareSerial.h

## Setup Instructions

1. **Hardware Setup:**
   - Connect ultrasonic sensors to Arduino pins as defined in the code (`METAL_TRIG`, `METAL_ECHO`, `PAPER_TRIG`, `PAPER_ECHO`, `PLASTIC_TRIG`, `PLASTIC_ECHO`).
   - Connect servos to Arduino pins (`servoPin1`, `servoPin2`).

2. **GSM Module Setup:**
   - Connect GSM module to Arduino (`RX` to pin 13, `TX` to pin 12).

3. **Upload the Code:**
   - Upload the provided Arduino sketch to your Arduino board using the Arduino IDE.

4. **Power On:**
   - Power the Arduino and GSM module.

## Usage

- The system monitors waste types using inductive, capacitive, and IR sensors.
- When a specific type of waste is detected:
  - The corresponding servo opens the gate to allow the waste into the bin.
  - After a delay, the gate closes automatically.
- If a bin reaches its capacity (detected by ultrasonic sensors):
  - An SMS alert is sent to a predefined number indicating the bin is full.
- Monitor the Serial Monitor for debugging messages (`Serial.begin(9600)`).

## Adjustments

- **Sensor Thresholds:** Adjust distance thresholds in `isBinFull()` function (`6` in `return (distance < 6);`) to fine-tune bin full detection.
- **SMS Recipient:** Change the recipient number in `sendSMS()` function (`gsm.println("AT+CMGS=\"+PhoneNumber\"");`) to the desired SMS recipient.

## License

This project is licensed under the [MIT License](LICENSE).
