#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h> 

Servo finger1;
Servo finger2;
Servo finger3;
Servo finger4;
Servo finger5;

RF24 radio(7,8);
int pos[5];
const uint64_t rxAddr ='A';
int servoPin1 = 22;
int servoPin2 = 24;
int servoPin3 = 26;
int servoPin4 = 28;
int servoPin5 = 30;

void setup() {
  // put your setup code here, to run once:
  finger1.attach(servoPin1);
  finger2.attach(servoPin2);
  finger3.attach(servoPin3);
  finger4.attach(servoPin4);
  finger5.attach(servoPin5);

  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  pinMode(servoPin5, OUTPUT);

  finger1.write(30);
  finger2.write(30);
  finger3.write(30);
  finger4.write(30);
  finger5.write(30);
  
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openReadingPipe(1, rxAddr);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
 
  radio.read(&pos,sizeof(pos));
  Serial.println(pos[0]);
  Serial.println(pos[1]);
  Serial.println(pos[2]);
  Serial.println(pos[3]);
  Serial.println(pos[4]);

  if(pos[0] <= 180 && pos[0] > 0)
  {
    finger1.write(pos[0]);
    finger2.write(pos[1]);
    finger3.write(pos[2]);
    finger4.write(pos[3]);
    finger5.write(pos[4]);
   }
   else
   {
      finger1.write(30);
      finger2.write(30);
      finger3.write(30);
      finger4.write(30);
      finger5.write(30);
   }
   
  delay(1000);
}
