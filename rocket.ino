/*
 * Nathan Hinton
 * This is for the rocket that I am 3d printing. I am planning on putting the MPU9250 inside with a nano and using it to measure the stuff.
 * I am strting with on the ground testing
 */

#include <MPU9250.h>

MPU9250 IMU(Wire, 0x68);
int status;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  IMU.readSensor();//Read the data from the senor.
}
