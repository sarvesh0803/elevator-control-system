# Elevator Control System

A general elevator runs on button controlled and pre-programmed control, which remains proprietary to each company. In this project we implemented an control system which uses IR based sensor for floor detection and sends feedback to central processing unit which also takes input from buttons across floors to navigate the lift in given direction. 

We also constructed a working lift model to implement and demonstrate the control system. To implement lift model, we used a DC motor whose speed and direction of rotation can be easily changed. Interfacing of DC motor and microcontroller was done using a motor driver. 

## Components

  - DC Motor
    - Input Voltage: 6V - 12V
    - Output speed: 10 rpm
  - L298N Motor Driver
    - Input Voltage Range: 5V & 12V
    - Output: 5V - 35V DC motor control
  - Arduino Uno Development Board
    - Microcontroller: ATmega328P
  - IR Sensor
  - IC LM 324N (OpAmp)
  - 7 segment displays
  - Resistors
  - Push buttons
  - Wires

## Code

The arduino code is the brain of the project. It interfaces arduino with all the components and is responsible for the smooth functioning of the system. 



![alt text](https://github.com/sarvesh0803/elevator-control-system/blob/master/arduino%20block%20diagram.jpg "Schematic Diagram of Elevator Control System")

## Circuit diagrams


#### Circuit diagram of Arduino and motor section:
![alt text](https://github.com/sarvesh0803/elevator-control-system/blob/master/motor%20circuit.png "Circuit diagram of Arduino and motor section")



#### Circuit diagram of Arduino and IR sensor section:
![alt text](https://github.com/sarvesh0803/elevator-control-system/blob/master/IR%20sensor%20circuit.png "Circuit diagram of Arduino and IR sensor section")


## Full report
The full report of the project can be found [here](https://docs.google.com/document/d/1aA0ZLCcFmAyb32sND_6Gx3rNGVcZOni7nwd56n91Dns/edit?usp=sharing)

Some images of the working prototype are also present in the report.
