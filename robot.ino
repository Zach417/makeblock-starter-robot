#include "robot.h"

Robot::Robot() {
  speed = 190;
  motorLeft.reset(M1);
  motorRight.reset(M2);
}

void Robot::forward() {
  motorLeft.run(speed);
  motorRight.run(speed);
}

void Robot::backward() {
  motorLeft.run(-speed);
  motorRight.run(-speed);
}

void Robot::left() {
  motorLeft.run(-speed);
  motorRight.run(speed);
}

void Robot::right() {
  motorLeft.run(speed);
  motorRight.run(-speed);
}

void Robot::stop() {
  motorLeft.stop();
  motorRight.stop();
}
