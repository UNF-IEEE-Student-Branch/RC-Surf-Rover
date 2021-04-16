/* UNF Surf Rover
 * Main MCU Board for the UNF Surf Rover
 * Created by: Joshua Harrell
 * Created on: 4/15/2021
 */

const int Lact = 4;  //Left Actuator Control 980Hz PWM pin
const int Ract = 13;  //Right Actuator Control 980Hz PWM pin
int Speed1;  //Global Variable to save the speed value for Sabertooth Motor1
int Speed2;  //Global Variable to save the speed value for Sabertooth Motor2
int Turn;    //Global Variable to save the steering Joystick position

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Lact, OUTPUT); 
  pinMode(Ract, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(38400);    // Enable Right Side Sabertooth Serial controller rear Gear Motors
  Serial2.begin(38400);    // Enable Left Side Sabertooth Serial controller front Gear Motor
}
void Get_Inputs(){
  if (Serial.available()){   //Checks if any input is provided by the Wii Nunchuck controller
    switch(Serial.read()){   // Reads the first Character of the Serial Transfer. As of now (Horn, Lights, Speed, Steering)
      case 'H':
//        digitalWrite(Horn, HIGH);    Not Implemented Yet
//        delay(50);
//        digitalWrite(Horn, LOW);
        break;
      case 'L':
//        if (Lights == HIGH){
//          digitalWrite(Lights, LOW);  Not Implemented Yet
//        }
//        if (Lights == LOW){
//        digitalWrite(Lights, HIGH);
//        }
        break;
      case 'S':
        Speed1 = Serial.read();    //Reading Speed, as of now either full throttle or off
        Speed2 = Speed1 + 128;
        break;
      case 'M':
        Turn = Serial.read();     //Reading Steering, as of now the steering is analog controlled
        break;
      default:
        Speed1 = 64;
        Speed2 = Speed1 + 128;   // Default value is both motors off and straighten rover
        Turn = 127;
        break;
    }
  }
}

void Do_Controls(){
  /*  Control Motors   */
  Serial1.write(Speed1);   //Write Speed value to Left Sabertooth Motor 1
  Serial1.write(Speed2);   //Write Speed Value to Left Sabertooth Motor 2
  Serial2.write(Speed1);   //Write Speed Value to Right Sabertooth Motor 1

  /*  Control Actuators   */
  if ((Turn < 115) || (Turn > 140)){
    analogWrite(Lact,Turn);          //Turn Rover Left or Right
    analogWrite(Ract,255-Turn);
  }
  else{
    analogWrite(Lact, 0);  //Straighten Rover
    analogWrite(Ract, 0);
  }
}

// the loop function runs over and over again forever
void loop() {
  Get_Inputs();
  Do_Controls();
  delay(50);    
}
