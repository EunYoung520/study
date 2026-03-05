#include <Servo.h>
Servo servoLeft; 
Servo servoRight;

void setup(){
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(600);

  for(int i=0; i<10;i++){
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    delay(600);
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1700);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(600);
  }
  servoLeft.writeMicroseconds(1300); // Left wheel clockwise
  servoRight.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(300); 
  
  servoLeft.detach();
  servoRight.detach();

}

void loop(){
}