# Smart-city-project
## Table of contents
* [introduction](#introduction)
* [Technologies](#technologies)
* [Setup](#setup)

## introduction 
This project presents a design and a prototype implementation of smart city system using Proteus simulation tool to represent the hardware in addition to assembly Language as its controlling software. Our purpose of this project is to have a clear understanding of how to use Microprocessor in mini project ,how all the components combine and how it's controlled the software to perform its special task that was designed to do.
#### the project is divided into three part:
- Smart traffic system 
- Street light system 
- Parking system 

## Technologies
Project is created with:
* c language
* pic microcontroller
* arduino ide  
* protos for simulation 

## Setup
### Function of project:
#### Smart traffic system 
* As usual traffic light is working like the way we know but we made it more smarter as we used sensors for detecting motion in all streets, then controlling it based on motion 
* Dealing with emergency cases like ambulances, police car or also if there is a rubbery so we can control the system in tow ways, manually or using SMS messages from any place 
* The traffic system will be off when there is no one so the power saved
* The last feature is traffic violations .

#### Street light system 
* Controlling the light of city manually (on-off) or using SMS messages from any place
* Automatic street light based on motion (using Delay)
* Automatic street light based on motion (using PWM)

#### Parking system 
* Using LCD to show the number of free places in the parking lot
* Controlling the gate of the parking lot automatically , it will be opened in case a free place is available else it won’t
* Opening and closing the parking lot using SMS message from any place
* Inquiring for a free place in the parking lot using SMS message .

## circuit diagram 
![image](https://user-images.githubusercontent.com/40560478/171231866-4382ecf3-63be-464c-85ea-ed1b332b8bab.png)

## code
* https://github.com/AltwilMohammed/Automatic-Street-light-using-8051-microcontroller/blob/main/atstreet.c
