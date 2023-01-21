# MiniBot-Tiny-Remote-Controlled-Robot  

Collaborators: Daniel Shenkelman, Eli Levenshus, Joe Li  

## Introduction  
The goal of this project is to create a tiny, controllable robot with a custom RF remote control. It involves having two independent Arduinos talking to each other over radio frequencies. The remote control will have an Arduino Nano that takes input from two joystick modules and an Arduino nRF24L01 to transmit a signal to a robot. The robot then uses this corresponding signal to control two driver motors, which causes the robot to move.  

This project aims to make the robot as small as possible. A custom PCB was created and designed from scratch with as small of a form factor as possible to accomplish this. This PCB utilizes an ATMEGA328P-AU microcontroller, two DRV8833 DC motor drivers, and can control three tiny DC motors. This PCB design also includes an RF header, a SPI Programming Header, and is powered by a 3.7V LiPo battery. The tiny board size is 15.3 mm by 30 mm, which saves space in constrained applications.

## Project Stages  
1. Set up motors with motor driver breakout boards, ensuring they can carry adequate load  

2. Set up the transmitter and receiver modules on a breadboard to ensure data can send

3. Design, order, and assemble receiver PCB based on the breadboard design

4. Flash bootloader onto receiver PCB

5. Program the receiver PCB and ensure its functionality

6. Build a small chassis to attach the motors to the PCB, and add 3d-printed wheels.  

## Sensors (Transmitter-Receiver Devices and Joysticks)  
One of the sensors built and used in this project is a custom RF remote control that controls the movement of the MiniBot. The main components of the remote control are an Arduino Nano Every, an Arduino nRF24L01 (wireless RF Transceiver Module), two Analog Joysticks, and powered by a 9-volt battery. The remote control transmits motor values mapped from the joystick position. We created Arduino programs that use the nRF24L01 radio frequency transceiver and SPI for serial communication.  

The other sensors used are joysticks, which take data from two potentiometers ranging from -512 to 512 for a total analog range of 0-1023. The joystick's position is sampled by the Arduino on the transmission board, then scaled and sent to the Arduino on the Minibot.   
![image](https://user-images.githubusercontent.com/32372013/213830053-7d230dcd-a3c0-472b-ac52-5276d4f68880.png)
![image](https://user-images.githubusercontent.com/32372013/213830077-c1aeac20-96e0-4200-a4fd-5a1f96617549.png)  
![image](https://user-images.githubusercontent.com/32372013/213830098-1de929d7-2662-4c26-8248-7e03c2f44ea8.png)  

There is a corresponding RF Receiver on the MiniBot Control Board (custom PCB) with an RF Header and SPI Programming Header. The  RF Module is connected specifically to the ATMEGA328P-AU. The Arduino Receiver code was also created to receive transmitted data and control two motors.	

![image](https://user-images.githubusercontent.com/32372013/213830167-c1f62162-20de-4bf2-b314-0ce710cac786.png)  

## Actuators (Two Motor Actuators - Wheels)
This project utilized two Adafruit DRV8833 DC Motor Driver Breakout Boards. This controls/spins the two cordless micro DC motors connected to the wheels of the MiniBot. A chassis was designed and 3D-printed to connect the motor shafts to the wheels while keeping all wiring in place. The PCB was then placed on top of the chassis to ensure proper connections to the motor drivers. The custom PCB contains two motor drivers, one controlling the back left side motor and left wheel, and the other controlling the back right side motor and right wheel.  

![image](https://user-images.githubusercontent.com/32372013/213830249-5a0b9d7d-3d63-4e8d-b61e-19c9b939fcc2.png)  
![image](https://user-images.githubusercontent.com/32372013/213830304-16bd32af-e57e-41dc-a0e9-0af2565acd47.png)

## MiniBot Control Board Schematic:
created by Daniel Shenkelman  

![image](https://user-images.githubusercontent.com/32372013/213830440-1304f348-4b8e-4d67-b326-abff29b6ceed.png)  

![image](https://user-images.githubusercontent.com/32372013/213830463-2a477924-40cd-4291-9f40-eba2ae7a9012.png)

## Preliminary Assembly
![image](https://user-images.githubusercontent.com/32372013/213830500-991aaab6-7bac-49fe-9adc-99becbddcb4f.png)

## Custom-Sized PCB
![image](https://user-images.githubusercontent.com/32372013/213830526-b2e8ab37-b5da-4b4f-b384-83890d0b3927.png)

## Custom RF Remote Control  
![image](https://user-images.githubusercontent.com/32372013/213830679-0e9e06f3-3ad9-4938-927e-409a55bf70a7.png)  
![image](https://user-images.githubusercontent.com/32372013/213830691-2a0f5a07-fbb2-45f0-b256-62fe6961ef10.png)

## Final Car  
![image](https://user-images.githubusercontent.com/32372013/213830761-4e6d0a61-04bf-47cf-9177-c2d7102639e5.png)

