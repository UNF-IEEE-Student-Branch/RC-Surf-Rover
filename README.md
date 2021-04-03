# RC-Surf-Rover
The Transformation of the UNF Surf Rover to a RC Car

## How To Get Started:
1. View the previous team's presentation in the main file directory
2. View the datasheets and schematics in the Previous team file folder

## Main Controls:
* Arduino Mega for the MCU
  * Handles Control over steering module
  * Handles all Logic Level shifting
  * Creates and maintains Zigbee radio mesh network
  * Processing all optional sensor data of the Surf Rover
  
* Sabertooth Dual Motor Driver
  * Handles Surf Rover Steering
  * Receives control data from the MCU
  
* Xbee Radio Module
  * Enables remote control of the Surf Rover from a specific controller
  * Module 1 is installed via a Arduino Shield on the MCU located on the surf rover
    - Creates the Zigbee Mesh Network
    - Processes serial data received from Radio and directly sends the data to the Mega's UART pins 
  * Module 2 is installed on the remote controller for the surf rover
    - Joins the Zigbee Mesh Network
    - Sends serial data received from a Module and sends the data over Radio
    
* Remote Controller
  * Wii Nunchuck remote w/ I2C attachment breakout board
  * Arduino with attached Xbee Radio
  
* Possible GPS configuration?????
    
# Power Distribution
* 12VDC Li-Po Battery
  * 24VDC Required for driving the actuating valves
     * Needs to be stepped up using an amplifier
  * Needs to be regulated to an unrippled 12V for MCU
  
* ~~We need to design a Solid state relay On-Off switch board for the actuator~~
  * ~~Requires input from MCU and turns on the valves~~

## An image of the current rover
![Surf Rover](https://github.com/UNF-IEEE-Student-Branch/RC-Surf-Rover/blob/main/media/images/IMG_3117.jpg)
