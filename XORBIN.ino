#include <Servo.h>
#include <SoftwareSerial.h>

// Define pin numbers for ultrasonic sensors
#define METAL_TRIG 6
#define METAL_ECHO 5
#define PAPER_TRIG 4
#define PAPER_ECHO 3
#define PLASTIC_TRIG 7
#define PLASTIC_ECHO 2

// Define analog sensor pins
const int inductiveSensor = A0;
const int capacitiveSensor = A1;
const int IrSensor = A2;

// Create Servo objects
Servo Gate_Servo;
Servo Pipe_Servo;

// Servo signal pins
int servoPin1 = 10;
int servoPin2 = 9;

int angle = 0; // Variable to store servo position

// GSM module using SoftwareSerial
SoftwareSerial gsm(13, 12); // RX, TX for GSM module

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  gsm.begin(9600);    // Initialize GSM module communication

  // Initialize pin modes for ultrasonic sensors
  pinMode(METAL_TRIG, OUTPUT);
  pinMode(METAL_ECHO, INPUT);
  pinMode(PAPER_TRIG, OUTPUT);
  pinMode(PAPER_ECHO, INPUT);
  pinMode(PLASTIC_TRIG, OUTPUT);
  pinMode(PLASTIC_ECHO, INPUT);

  // Attach servo motors to respective pins
  Pipe_Servo.attach(servoPin2);
  Gate_Servo.attach(servoPin1);
}

void loop() {
  // Read analog sensor values
  int inductiveSensorValue = analogRead(inductiveSensor);
  delay(10);
  int capacitiveSensorValue = analogRead(capacitiveSensor);
  delay(500);
  int IrSensorValue = analogRead(IrSensor);

  // Determine type of waste detected
  if (inductiveSensorValue <= 130 && capacitiveSensorValue == 1023) {
    Serial.println("Metal Detected");
    MetalDetected();
  } else if (capacitiveSensorValue >= 1023 && IrSensorValue >= 1000) {
    Serial.println("Plastic Detected");
    PlasticDetected();
  } else if (inductiveSensorValue >= 1000 && capacitiveSensorValue >= 1000 && IrSensorValue < 50) {
    Serial.println("Paper Detected");
    PaperDetected();
  }

  // Check if bins are full using ultrasonic distance sensors
  if (isBinFull(METAL_TRIG, METAL_ECHO)) {
    Serial.println("Metal Bin is Full!");
    delay(5000);
    sendSMS("Metal bin is full!");
  }
  if (isBinFull(PAPER_TRIG, PAPER_ECHO)) {
    Serial.println("Paper Bin is Full!");
    delay(5000);
    sendSMS("Paper bin is full!");
  }
  if (isBinFull(PLASTIC_TRIG, PLASTIC_ECHO)) {
    Serial.println("Plastic Bin is Full!");
    delay(5000);
    sendSMS("Plastic bin is full!");
  }
}

// Function to open the gate using Gate_Servo
void OpenGate() {
  for (angle = 50; angle <= 180; angle += 1) {
    Gate_Servo.write(angle);
    delay(40);
  }
  for (angle = 180; angle >= 70; angle -= 1) {
    Gate_Servo.write(angle);
    delay(40);
  }
}

// Functions to handle different types of waste detected
void MetalDetected() {
  Pipe_Servo.write(0);
  delay(4000);
  OpenGate();
}

void PaperDetected() {
  Pipe_Servo.write(70);
  delay(4000);
  OpenGate();
}

void PlasticDetected() {
  Pipe_Servo.write(180);
  delay(4000);
  OpenGate();
}

// Function to reset Pipe_Servo to default position
void PipeDefault() {
  Pipe_Servo.write(70);
  delay(3000);
}

// Function to check if a bin is full using ultrasonic sensor
bool isBinFull(int trigPin, int echoPin) {
  long duration;
  int distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  return (distance < 6); // Adjust the threshold distance as needed
}

// Function to send SMS using GSM module
void sendSMS(String message) {
  gsm.println("AT+CMGF=1"); // Set SMS mode to text
  delay(100);
  gsm.println("AT+CMGS=\"+639493655314\""); // Replace with recipient's number
  delay(100);
  gsm.println(message); // Send the SMS message
  delay(100);
  gsm.println((char)26); // End AT command with Ctrl+Z
  delay(100);
}
