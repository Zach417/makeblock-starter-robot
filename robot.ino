#include "robot.h"

Robot::Robot() {
  speed = 190;
  sensorForward = MeUltrasonicSensor(PORT_3);
  motorLeft.reset(M1);
  motorRight.reset(M2);
}

void Robot::forward() {
  float distance = sensorForward.distanceCm();
  if (distance > 10) {
    motorLeft.run(speed);
    motorRight.run(speed);
  }
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

void Robot::drive() {
  float distance = sensorForward.distanceCm();
  if (distance > 25) {
    forward();
  } else {
    float distanceStart = distance;
    float distances[30];

    // get distances to right
    for (int i = 0; i < 15; i++) {
      right();
      delay(100);

      distances[i] = sensorForward.distanceCm();
      if (distances[i] == (float)400) {
        return;
      }
    }

    // go back to starting angle
    left();
    delay(1000);
    
    // get distances to left
    for (int i = 0; i < 15; i++) {
      left();
      delay(100);
      
      distances[i + 15] = sensorForward.distanceCm();
      if (distances[i + 15] == (float)400) {
        return;
      }
    }
    
    // go back to starting angle
    right();
    delay(1000);

    // get most optimal travel path
    int bestIdx = 0;
    for (int i = 0; i < 30; i++) {
      if (distances[i] > distances[bestIdx]) {
        bestIdx = i;
      }
    }

    // travel most optimal travel path
    if (bestIdx >= 15) {
      int steps = bestIdx - 15;
      for (int i = 0; i < steps; i++) {
        left();
        delay(100);
      }
    } else {
      int steps = bestIdx;
      for (int i = 0; i < steps; i++) {
        right();
        delay(100);
      }
    }
  }
}

