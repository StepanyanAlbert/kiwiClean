

// Motor A

int enA =   10;
int in1 = 8;
int in2 = 6;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

#define trigPin 12 // define the pins of your sensor
#define echoPin 13


#include <NewPing.h>        //for the Ultrasonic sensor function library.



boolean goesForward = false;
int distance = 100;

NewPing sonar(trigPin, echoPin);




int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}



void moveForward() {

  if (!goesForward) {

    goesForward = true;

    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);

    digitalWrite(in1, LOW);
    digitalWrite(in4, LOW);
  }
}

void moveBackward() {

  goesForward = false;

  digitalWrite(in1, HIGH);
  digitalWrite(in4, HIGH);

  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);

}


void setup()

{
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  Serial.begin(9600); // begin serial communitication

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //analogWrite(enA, 60);
  //analogWrite(enB, 65);
   analogWrite(enA, 83);
  analogWrite(enB, 80);


}



void turnLeft() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopTheCar()

{

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}


void loop()
{


  moveBackward();
  delay(3500);
  stopTheCar();
  delay(500);
  turnRight();
  delay(500);
  stopTheCar();
    delay(500);
  turnLeft();
    delay(500);
    stopTheCar();
    delay(500);
     moveForward();
     delay(3500);
      stopTheCar();
//  int distance = readPing();
//
//  delay(80);
//
//  if (distance <= 20) {
//    stopTheCar();
//    delay(300);
//    moveBackward();
//    delay(400);
//    stopTheCar();
//    delay(300);
//    distance = readPing();
//    delay(300);
//
//    if (random(1, 6) % 2 == 0) {
//      turnRight();
//      delay(500);
//      stopTheCar();
//    }
//    else {
//      turnLeft();
//      delay(500);
//      stopTheCar();
//    }
//  }
//  else {
//    moveForward();
//  }



}
