#include <Wire.h>
#include <ArduinoNunchuk.h>

ArduinoNunchuk nunchuck = ArduinoNunchuk();

int xval = 0;
int yval = 64;
char Speed[2] = {'S', yval};  // Speed array byte to distinguish speed from steering
char Steer[2] = {'M', xval};  // Steering array byte to distinguish steering from speed

void setup() {
  Serial.begin(9600);
  nunchuck.init();
}

void loop() {
nunchuck.update();    // Read inputs and update maps

//Serial.println("X" + String((uint8_t) nunchuck.analogX));
//Serial.println("Y" + String((uint8_t) nunchuck.analogY));
yval = map(nunchuck.analogY,0,255,0,127);
xval = nunchuck.analogX;
Serial.write(Speed,2);
Serial.write(Steer,2);
if ((uint8_t) nunchuck.zButton){
  delay(5);
  if ((uint8_t) nunchuck.zButton){
  Serial.write('H');
  }
}
if ((uint8_t) nunchuck.cButton){
  delay(5);
  if ((uint8_t) nunchuck.cButton){
  Serial.write('L');
  }
}
  delay(100);
}
