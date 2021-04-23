# RC-Surf-Rover
The Transformation of the UNF Surf Rover to a RC Car

## How To Get Started:
1. View the previous team's presentation in the main file directory
2. View the datasheets and schematics in the Previous team file folder

## Main Controls:
* Arduino Mega for the MCU
  * Handles Control over steering module
    * Sends PWM Signal to Linear Actuators through GPIO analog pins 9 and 11
  * Handles Control over Sabertooth Motor Speed through Serial
  * Handles all Logic Level shifting
  * Creates and maintains Zigbee radio mesh network
    * ### Make sure you switch the Xbee shield to "USB" for programming the Arduino and "Micro" for Radio Mode
    * ### Failure to do so will destroy the Arduino Mega and Xbee Radio
  * Processing all optional sensor data of the Surf Rover
  
* Sabertooth Dual Motor Driver
  * Handles Surf Rover Speed Control
  * Receives control data from the MCU
  
* Xbee Radio Module
  * Enables remote control of the Surf Rover from a specific controller
  * Module 1 is installed via a Arduino Shield on the MCU located on the surf rover
    - Creates the Zigbee Mesh Network
    - Processes serial data received from Radio and directly sends the data to the Mega's UART pins 
    _PAN ID: "3333"  DH: "0000" DL: "2345" CH: "C" MY: "1234" 
  * Module 2 is installed on the remote controller for the surf rover
    - Joins the Zigbee Mesh Network
    - Sends serial data received from a Module and sends the data over Radio
    _PAN ID: "3333"  DH: "0000" DL: "1234" CH: "C" MY: "2345"  
    
* Remote Controller
  * Wii Nunchuck remote w/ I2C attachment breakout board
  * Arduino with attached Xbee Radio
  * ### Make sure you switch the Xbee shield to "USB" for programming the Arduino and "Micro" for Radio Mode
  * ### Failure to do so will destroy the Arduino Uno and Xbee Radio
  
* Possible GPS configuration?????
    
# Power Distribution
![Power Distribution](https://github.com/UNF-IEEE-Student-Branch/RC-Surf-Rover/blob/main/media/images/Power_Distribution.jpg)

## An image of the current rover
![Surf Rover](https://github.com/UNF-IEEE-Student-Branch/RC-Surf-Rover/blob/main/media/images/Updated_Surf_Rover.jpg)
