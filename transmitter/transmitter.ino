//Transmitter Code:
//Code to transmit motor values mapped from joystick position
//Include libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Define radio pins, address, and size of data to send
#define CE_PIN   8
#define CSN_PIN 7
const byte slaveAddress[5] = {'R','x','A','A','A'};
float dataToSend[2];

//Create a radio
RF24 radio(CE_PIN, CSN_PIN);

//Creating time variables
unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 200; // send once per 200ms


void setup() {
    //Serial connector
    Serial.begin(9600);
    Serial.println("SimpleTx Starting");

    //Start radio
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openWritingPipe(slaveAddress);
}

void loop() {
    //Read values needed
    float y_val1 = analogRead(A0);
    float y_val = analogRead(A1);

    //Map read values to range(-150, 150)
    dataToSend[0] = map(y_val1, 0, 1023, -200, 200);
    dataToSend[1] = -1 * map(y_val, 0, 1023, -200, 200);

    //Send data read every 200ms
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        send();
        prevMillis = millis();
    }
}

//Function to send data via radio
void send() {
    //Boolean condition of receiver acknowledgment
    bool rslt;
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );

    //Print data to serial monitor for debugging purpose
    Serial.print("Data Sent ");
    Serial.print(dataToSend[0]);
    Serial.print(" ");
    Serial.print(dataToSend[1]);

    //Print receiver acknowledgment state 
    if (rslt) {
        Serial.println("  Acknowledge received");
    }
    else {
        Serial.println("  Tx failed");
    }
}
