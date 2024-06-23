#include <Servo.h>

//#define TRIG_PIN 8
//#define ECHO_PIN 7
#define METAL_TRIG 6
#define METAL_ECHO 5
#define PAPER_TRIG 4
#define PAPER_ECHO 3
#define PLASTIC_TRIG 7
#define PLASTIC_ECHO 2

Servo Gate_Servo;  // create servo object to control a servo
Servo Pipe_Servo;

int servoPin1 = 10;  // pin connected to the servo's signal line
int servoPin2 = 9;  
int angle = 0;     // variable to store the servo position

void setup() {
 Serial.begin(9600);

 
  pinMode(METAL_TRIG, OUTPUT);
  pinMode(METAL_ECHO, INPUT);
  pinMode(PAPER_TRIG, OUTPUT);
  pinMode(PAPER_ECHO, INPUT);
  pinMode(PLASTIC_TRIG, OUTPUT);
  pinMode(PLASTIC_ECHO, INPUT);

  Pipe_Servo.attach(servoPin2);  // Attach the first servo to the pin
  Gate_Servo.attach(servoPin1);
}

// 0, 70, 160
void loop() {
  MetalDetected();
  delay(2000);
  PaperDetected();
  delay(2000);
  PlasticDetected();
  delay(2000);
}
  // GATE SERVO
  void OpenGate() {
    // Sweep the servo from 0 to 180 degrees
  for (angle = 50; angle <= 180; angle += 1) { // in steps of 1 degree
    Gate_Servo.write(angle);              // tell servo to go to position in variable 'angle'
    delay(40);                         // waits 15ms for the servo to reach the position
  }
  
  // Sweep the servo from 180 to 0 degrees
  for (angle = 180; angle >= 70; angle -= 1) { 
    Gate_Servo.write(angle);              // tell servo to go to position in variable 'angle'
    delay(40);                         // waits 15ms for the servo to reach the position
  }

  }

  void MetalDetected() {
     // in steps of 1 degree
    Pipe_Servo.write(0);              // tell servo to go to position in variable 'angle'
    delay(4000);
    OpenGate();                         // waits 15ms for the servo to reach the position
    
  }

  void PaperDetected() {
      // in steps of 1 degree
    Pipe_Servo.write(70);              // tell servo to go to position in variable 'angle'
    delay(4000);
    OpenGate();                         // waits 15ms for the servo to reach the position
    

  }
  void PlasticDetected() {
      // in steps of 1 degree
    Pipe_Servo.write(180);              // tell servo to go to position in variable 'angle'
    delay(4000);
    OpenGate();                         // waits 15ms for the servo to reach the position
    
    
  }

  void PipeDefault(){
    Pipe_Servo.write(70);
    delay(3000);
    OpenGate();
  }



