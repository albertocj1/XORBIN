<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Arduino Waste Management System</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      line-height: 1.6;
      max-width: 800px;
      margin: 0 auto;
      padding: 20px;
    }
    h1, h2 {
      color: #333;
    }
    pre {
      background-color: #f4f4f4;
      padding: 10px;
      border: 1px solid #ddd;
    }
  </style>
</head>
<body>
  <h1>Arduino Waste Management System</h1>

  <p>This Arduino project manages waste bins using ultrasonic sensors and controls servos to open/close gates for different types of waste (metal, paper, plastic). It also integrates a GSM module to send SMS alerts when bins are full.</p>

  <h2>Components Used</h2>
  <ul>
    <li>Arduino board (e.g., Arduino Uno)</li>
    <li>Ultrasonic sensors (3x)</li>
    <li>Servo motors (2x)</li>
    <li>GSM module (e.g., SIM800L)</li>
    <li>Various resistors and capacitors</li>
    <li>Breadboard and connecting wires</li>
  </ul>

  <h2>Libraries Required</h2>
  <ul>
    <li>Servo.h</li>
    <li>SoftwareSerial.h</li>
  </ul>

  <h2>Setup Instructions</h2>
  <ol>
    <li><strong>Hardware Setup:</strong>
      <ul>
        <li>Connect ultrasonic sensors to Arduino pins as defined in the code (<code>METAL_TRIG</code>, <code>METAL_ECHO</code>, <code>PAPER_TRIG</code>, <code>PAPER_ECHO</code>, <code>PLASTIC_TRIG</code>, <code>PLASTIC_ECHO</code>).</li>
        <li>Connect servos to Arduino pins (<code>servoPin1</code>, <code>servoPin2</code>).</li>
      </ul>
    </li>
    <li><strong>GSM Module Setup:</strong>
      <ul>
        <li>Connect GSM module to Arduino (<code>RX</code> to pin 13, <code>TX</code> to pin 12).</li>
      </ul>
    </li>
    <li><strong>Upload the Code:</strong>
      <ul>
        <li>Upload the provided Arduino sketch to your Arduino board using the Arduino IDE.</li>
      </ul>
    </li>
    <li><strong>Power On:</strong>
      <ul>
        <li>Power the Arduino and GSM module.</li>
      </ul>
    </li>
  </ol>

  <h2>Usage</h2>
  <ul>
    <li>The system monitors waste types using inductive, capacitive, and IR sensors.</li>
    <li>When a specific type of waste is detected:
      <ul>
        <li>The corresponding servo opens the gate to allow the waste into the bin.</li>
        <li>After a delay, the gate closes automatically.</li>
      </ul>
    </li>
    <li>If a bin reaches its capacity (detected by ultrasonic sensors):
      <ul>
        <li>An SMS alert is sent to a predefined number indicating the bin is full.</li>
      </ul>
    </li>
    <li>Monitor the Serial Monitor for debugging messages (<code>Serial.begin(9600)</code>).</li>
  </ul>

  <h2>Adjustments</h2>
  <ul>
    <li><strong>Sensor Thresholds:</strong> Adjust distance thresholds in <code>isBinFull()</code> function (<code>6</code> in <code>return (distance &lt; 6);</code>) to fine-tune bin full detection.</li>
    <li><strong>SMS Recipient:</strong> Change the recipient number in <code>sendSMS()</code> function (<code>gsm.println("AT+CMGS=\"+639493655314\"");</code>) to the desired SMS recipient.</li>
  </ul>

  <h2>Contributing</h2>
  <p>Feel free to contribute to the improvement of this project by submitting pull requests.</p>

  <h2>License</h2>
  <p>This project is licensed under the <a href="LICENSE">MIT License</a>.</p>
</body>
</html>

