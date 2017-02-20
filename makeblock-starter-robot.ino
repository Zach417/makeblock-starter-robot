#include <SoftwareSerial.h>
#include <MeOrion.h>
#include "robot.h"

int type = 0;
MeInfraredReceiver receiver(PORT_6);
Robot robot;

int getSpeedFromKey(int i) {
  int minSpeed = 45;
  int factor = 23;
  return factor * i + minSpeed;
}

void stepManual(uint8_t code) {
  type = 0;
  switch(code)
  {
    case IR_BUTTON_PLUS:      robot.forward();                  break;
    case IR_BUTTON_MINUS:     robot.backward();                 break;
    case IR_BUTTON_NEXT:      robot.right();                    break;
    case IR_BUTTON_PREVIOUS:  robot.left();                     break;
    case IR_BUTTON_9:         robot.speed = getSpeedFromKey(9); break;
    case IR_BUTTON_8:         robot.speed = getSpeedFromKey(8); break;
    case IR_BUTTON_7:         robot.speed = getSpeedFromKey(7); break;
    case IR_BUTTON_6:         robot.speed = getSpeedFromKey(6); break;
    case IR_BUTTON_5:         robot.speed = getSpeedFromKey(5); break;
    case IR_BUTTON_4:         robot.speed = getSpeedFromKey(4); break;
    case IR_BUTTON_3:         robot.speed = getSpeedFromKey(3); break;
    case IR_BUTTON_2:         robot.speed = getSpeedFromKey(2); break;
    case IR_BUTTON_1:         robot.speed = getSpeedFromKey(1); break;
    default:                  robot.stop();                     break;
  }
}

double lastTimeChanged = millis();
void listenTypeChange(uint8_t code) {
  double currentTime = millis();
  double difference = currentTime - lastTimeChanged;
  if (code == IR_BUTTON_D  && difference > 500) {
    Serial.println("Change type");
    if (type == 0) type = 1;
    else type = 0;
    lastTimeChanged = millis();
  }
}

void stepProgram(uint8_t code) {
  switch (type) {
    case 0:
      stepManual(code);
      break;
    case 1:
      robot.drive();
      break;
  }
}

void setup() {
  Serial.begin(115200);
  robot.stop();
  receiver.begin();
  Serial.println("Ready!");
}

void loop() {
  receiver.loop();
  uint8_t code = receiver.getCode();
  listenTypeChange(code);
  stepProgram(code);
}
