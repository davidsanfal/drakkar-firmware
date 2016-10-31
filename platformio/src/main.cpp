#include <Arduino.h>
#include <drakkar.h>
#include <MsTimer2.h>

#define stepTime 100 //ms

// (potentiometer, currentSensor, endstop, up, down, speed, EMGFront, EMGBack)
Drakkar drakkar(14, 15, 16, 17, 18, 20, 19, 21);
bool debug=true;

void endstop() {drakkar.endstop();}

void drakkarControl() {
  if (debug) drakkar.debug();
  else drakkar.run();
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(drakkar.get_endstop_pin()), endstop, CHANGE);
  Serial.begin(9600);
  MsTimer2::set(stepTime, drakkarControl);
  MsTimer2::start();
}

void loop() {
  if (not debug) drakkar.writeMotor();
}
