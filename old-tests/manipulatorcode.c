#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"
#pragma DebuggerWindows("joystickSimple")

/*manipulator controls*/
task main()
{
	int manipServoSpeed = 10;
while (true) {
	getJoystickSettings(joystick);
	int manipServoRate = 0;
	manipServoRate = manipServoRate + (joystick.joy1_y2/manipServoSpeed);





/*
servoChangeRate[servo1] = delta*joystick.joy1_y2;
servoChangeRate[servo2] = delta*joystick.joy1_y2;

getJoystickSettings(joystick);
   		servo[servo1] = joystick.joy1_y2;
   		servo[servo2] = joystick.joy1_y2;
if (joystick.joy2_y1 < 10 && joystick.joy1_y2 > -10)
  servo[servo1] = 10;
	servo[servo2] = 10;
*/

}
}
