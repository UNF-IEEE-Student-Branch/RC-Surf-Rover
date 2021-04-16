# Collection of datasheets for the Linear Actuators and the Motors

The Actuators are L12-100-100-12-P
* 100mm Length
* 100 Gear Reduction Ratio
* 12VDC
* Potentiometer Position Feedback
  * Orange – Feedback Potentiometer negative reference rail
  * Purple – Feedback Potentiometer wiper
  * Red – Motor V+ (6V or 12V)
  * Black – Motor V- (Ground)
  * Yellow – Feedback Potentiometer positive reference rail
* For the Linear Actuator Controller Board
  * Negative terminal is GND
  * Positive terminal is 12V
  * Other Wire(VC terminal) is PWM Position Control
    * Pins 4 and 13 of Mega produce 980Hz PWM pulse needed, all other analog pins are 490Hz

The GearMotor is an AME-206-1004
* 6Nm Stall Torque/ 1.6Nm Nominal
* 119rpm
* 19.8W
* 6A continuous
* CW Rotation (12V Logic) (Pin 1 HIGH, Pin 2 LOW)
* CCW Rotation (Pin 1 LOW, Pin 2 HIGH)
