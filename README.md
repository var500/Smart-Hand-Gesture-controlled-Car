# Smart-Hand-Gesture-controlled-Car
A smart Iot Based car which can be controlled through hand gesture commands fetched from the Laptops webcam

## Description
Traditionally objects were moved using the human external forces but now the scenario has been changed by the automation revolution which has reduced human efforts.

The automatic movement of objects began gradually step by step as first there were hand gears used to move the objects.
Currently there are ongoing similar projects are using Bluetooth technology for the specifies processes.
In this project I have using WIFI technology which would increase the range of the car and controller and also reduced hardware dependencies i.e., hand gears.
With the help of OpenCV I have made use of deep learning and computer vision rather than using old traditional methods.




## Techiniques
---
* Deep Learning
* Multithreading
* Wireless Connection using ESP8266
* Multicontroller Programming

## Hardware Used
---
* NodeMCU ESP8266
* L298N Servo Sheild
* DC Motors
* Jumper Wires
* Breadnboard
* 3pc 18650 Batteries (preffered) else can be used with 4 AA battries

## Software Used
---
* Open CV
* Python IDE
* Arduino IDE

## Project Flow
---
1. In the first step ,the gestures are presented in front of the camera and then they are sent to the recognition module.
2. The module reads the gestures and verify and processes them for further objectives. 
3. The module sends the commands to the NodeMCU which has ESP2866 wifi chip and further transmits it to the MCU board for the movement of object. 
4. The NodeMCU board processes the commands and provides us the right combination of DC motors and tyres for the desired movement of car.
