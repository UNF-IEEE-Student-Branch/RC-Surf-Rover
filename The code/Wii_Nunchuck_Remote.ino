#include <Wire.h>
#include <ArduinoNunchuk.h>

ArduinoNunchuk nunchuck = ArduinoNunchuk();

int xval = 0;
int yval = 64;
//char Speed[2] = {'S', yval};  // Speed array byte to distinguish speed from steering
//char Steer[2] = {'M', xval};  // Steering array byte to distinguish steering from speed

void setup() {
  Serial.begin(9600);
  nunchuck.init();
}

void loop() {
nunchuck.update();    // Read inputs and update maps

//Serial.println("X" + String((uint8_t) nunchuck.analogX));
//Serial.println("Y" + String((uint8_t) nunchuck.analogY));
yval = nunchuck.analogY;
xval = nunchuck.analogX;

char Speed[3];  // Speed array byte to distinguish speed from steering
char Steer[3];  // Steering array byte to distinguish steering from speed
itoa(yval, Speed, 10);
itoa(xval, Steer, 10);

Serial.write('S');
Serial.write(Speed);
delay(1);
Serial.write('M');
Serial.write(Steer);
delay(1);
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
