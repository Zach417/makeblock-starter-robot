#ifndef ROBOT_H
#define ROBOT_H

class Robot {
  private:
    int moveSpeed;
    MeDCMotor motor;
    
  public:
    void forward(MeDCMotor&, int&);
    void forward();
    void backward();
    void left();
    void right();
    void backwardAndTurnLeft();
    void backwardAndTurnRight();
    void stop();
    void changeSpeed(int speed);
    void setMotor(MeDCMotor);
    Robot(MeDCMotor);
};

#endif
