// Reciever Code:
//Code to receive transmitted data and control two motors
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Declare nRF pins
#define CE_PIN A3
#define CSN_PIN A2

//Declare address and radio
const byte thisSlaveAddress[5] = { 'R', 'x', 'A', 'A', 'A' };
RF24 radio(CE_PIN, CSN_PIN);

//Motor controller pins
int MC1_IN1 = 5;
int MC1_IN2 = 6;

int MC2_IN1 = 9;
int MC2_IN2 = 10;

//Declare data to receive
float dataReceived[2];  // this must match dataToSend in the TX
bool newData = false;

void setup() {
  //Initialize serial monitor
  Serial.begin(9600);
  Serial.println("SimpleRx Starting");

  //Initialize radio
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, thisSlaveAddress);
  radio.startListening();

  pinMode(MC1_IN1, OUTPUT);
  pinMode(MC1_IN2, OUTPUT);
  pinMode(MC2_IN1, OUTPUT);
  pinMode(MC2_IN2, OUTPUT);
}

//=============

void loop() {
  //Call helper functions for program simplicity 
  getData();
  showData();

  //Write to first MC
  if (dataReceived[0] < 0) {
    analogWrite(MC1_IN1, dataReceived[0]);
    digitalWrite(MC1_IN2, LOW);
  } else {
    analogWrite(MC1_IN2, dataReceived[0]);
    digitalWrite(MC1_IN1, LOW);
  }

  //Write to second MC
  if (dataReceived[1] < 0) {
    analogWrite(MC2_IN2, dataReceived[1]);
    digitalWrite(MC2_IN2, LOW);
  } else {
    analogWrite(MC2_IN2, dataReceived[1]);
    digitalWrite(MC2_IN1, LOW);
  }

}

//Helper function to read input data
void getData() {
  if (radio.available()) {
    radio.read(&dataReceived, sizeof(dataReceived));
    newData = true;
  }
}

//Print input data for debugging purposes
void showData() {
  if (newData == true) {
    Serial.print("Data received ");
    Serial.print(dataReceived[0]);
    Serial.print(" ");
    Serial.println(dataReceived[1]);
    newData = false;
  }
}
