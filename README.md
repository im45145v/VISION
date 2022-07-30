# VISION -THE GUIDE

Making a Device which will help the vision impaired people to guide them.The Device will use GPS to help the family members to keep track of him.The directions to the man can be given to him using speaker.
So, overall it will help the blind people to go wherever they want without anyone’s help.

## Description

Abstract Mobility for blind people is a problem as they have to face many difficulties in their day to day life. Most commonly, stick is used by blind and elderly people as a support for their body to stand and walk. The most common disadvantage of walking stick is user should have to be in close proximity of obstacle so that he can sense the location of obstacle to avoid bumping while waggling. So, this inspired to think of the problem.

## Getting Started

Hardware Components used such as:
ESP-32 Cam,ESP-32 (ESP32-WROOM-32),Ultrasonic Sensor,GPS Sensor(NEO-6M),WTV020SD-16P Module,Speaker,Breadboard,Jumper wire.
Software Components used such as:
ARDUINO IDE,OpenCV,Blynk.

## Working of the project

First the esp32cam will capture the images to the particular server. so it process the image using haarcascade algorithm. so here are our laptop is to be connected to a esp 32 cam server and our laptop access the photos it processes and get the output and then the laptop will pass the output to the esp32 . Then esp32 will access the output then after accessing the output it will start looking for obstacles using HCSR04 and it compares the output and gives the particular audio output. And here GPS is used to send the location of particular person to their family members using blynk app.




