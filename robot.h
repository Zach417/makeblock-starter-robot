#ifndef ROBOT_H
#define ROBOT_H

class Robot {
  private:
    MeUltrasonicSensor sensorForward;
    MeDCMotor motorLeft;
    MeDCMotor motorRight;
    
  public:
    int speed;
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    void drive();
    Robot();
};

#endif
