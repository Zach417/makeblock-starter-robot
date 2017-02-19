#include "robot.h"

Robot::Robot(MeDCMotor _motor) {
  this -> moveSpeed = 190;
  this -> motor = _motor;
}

void Robot::forward(MeDCMotor& dc, int& moveSpeed) {
  Serial.print('f');
  dc.reset(M1);
  dc.run(moveSpeed);
  dc.reset(M2);
  dc.run(moveSpeed);
}

void Robot::forward() {
  int moveSpeed = this -> moveSpeed;
  this -> motor.reset(M1);
  this -> motor.run(moveSpeed);
  this -> motor.reset(M2);
  this -> motor.run(moveSpeed);
}

void Robot::backward() {
  this -> motor.reset(M1);
  this -> motor.run(-moveSpeed);
  this -> motor.reset(M2);
  this -> motor.run(-moveSpeed);
}

void Robot::backwardAndTurnLeft() {
  this -> motor.reset(M1);
  this -> motor.run(moveSpeed/2);
  this -> motor.reset(M2);
  this -> motor.run(-moveSpeed);
}

void Robot::backwardAndTurnRight() {
  this -> motor.reset(M1);
  this -> motor.run(moveSpeed);
  this -> motor.reset(M2);
  this -> motor.run(-moveSpeed/2);
}

void Robot::left() {
  this -> motor.reset(M1);
  this -> motor.run(-moveSpeed);
  this -> motor.reset(M2);
  this -> motor.run(moveSpeed);
}

void Robot::right() {
  this -> motor.reset(M1);
  this -> motor.run(moveSpeed);
  this -> motor.reset(M2);
  this -> motor.run(-moveSpeed);
}

void Robot::stop() {
  this -> motor.reset(M1);
  this -> motor.stop();
  this -> motor.reset(M2);
  this -> motor.stop();
}

void Robot::changeSpeed(int speed) {
  this -> moveSpeed = speed;
}

void Robot::setMotor(MeDCMotor _motor) {
  this -> motor = _motor;
}
