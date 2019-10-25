#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int CE = 7 ;
int CSN = 8;

int MSG1 = 111; //forward
int MSG2 = 000; //backward
int MSG3 = 999;
int MSG4 = 100; //left
int MSG5 = 101; //Right

int Forward = A0;
int  Backward = A1;
int Right = A2;
int Left = A3;

RF24 radio(CE, CSN);


const uint64_t rxAddr = 1;

void setup()
{
  //pinMode(6,OUTPUT);
  //digitalWrite(6,HIGH);
  pinMode(Forward,INPUT);
  pinMode(Backward,INPUT);
  pinMode(Right,INPUT);
  pinMode(Left,INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(1);
  radio.stopListening();
}

void loop()
{
  if ( (analogRead(Forward) >= 800) && (analogRead(Forward) <= 900)){
    radio.write(&MSG1, sizeof(MSG1));
    Serial.println(MSG1);
    delay(500);
  }
  else if ((analogRead(Backward) >= 800) && (analogRead(Backward) <= 900)){
    radio.write(&MSG2, sizeof(MSG2));
    Serial.println(MSG2);
    delay(500);
  }
  else if ( (analogRead(Right) >= 800) && (analogRead(Right) <= 900)){
    radio.write(&MSG4, sizeof(MSG4));
    Serial.println(MSG4);
    delay(500);
  }
  else if ((analogRead(Left) >= 800) && (analogRead(Left) <= 900)){
    radio.write(&MSG5, sizeof(MSG5));
    Serial.println(MSG5);
    delay(500);
  }
  else{
    radio.write(&MSG3, sizeof(MSG3));
    Serial.println(MSG3);
    delay(500);
  }
}
