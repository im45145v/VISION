# VISION -THE GUIDE

Vision impaired people face a lot of difficulty when they need to go somewhere or do some work.They need a guide every time with them to take care of them hence making a device which will help the vision impaired people to guide them.The Device will use GPS to help the family members to keep track of him.The directions to the man can be given to him using speaker.So, overall it will help the blind people to go wherever they want without anyone’s help. Mobility for blind people is a problem as they have to face many difficulties in their day to day life. Most commonly, stick is used by blind and elderly people as a support for their body to stand and walk. The most common disadvantage of walking stick is user should have to be in close proximity of obstacle so that he can sense the location of obstacle to avoid bumping while waggling. So, this inspired to think of the problem.

## Components used

Hardware Components:
ESP-32 Cam
ESP-32 (ESP32-WROOM-32)
Ultrasonic Sensor
GPS Sensor(NEO-6M)
WTV020SD-16P Module
Speaker
Breadboard
Jumper wire

Software Components :
ARDUINO IDE
OpenCV
Blynk

## Working of the project

First the esp32cam will capture the images to the particular server. so it process the image using haarcascade algorithm. so here are our laptop is to be connected to a esp 32 cam server and our laptop access the photos it processes and get the output and then the laptop will pass the output to the esp32 . Then esp32 will access the output then after accessing the output it will start looking for obstacles using HCSR04 and it compares the output and gives the particular audio output. And here GPS is used to send the location of particular person to their family members using blynk app.

##  Result
VISION Our bot helps the vision impaired people in guiding them to avoid obstackes while waking on roads and ubics areas.It also as gps which will 
upload the location to the blynk app which will update the location to the blynk app which can be accessed by their family members to keep track of 
them.

## Future Enhancement
In future using Artificial Intelligence we can help the blind person even for reading books and and in doing any external activities.




