#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     leftside,       sensorI2CMuxController)
#pragma config(Sensor, S2,     rightside,      sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontRight,    tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backRight,     tmotorMatrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     frontLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     backLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     manipRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     manipLeft,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    mainmanip1,           tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    mainmanip2,           tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**!!Code automatically generated by 'ROBOTC' configuration wizard               !!*/

#include "JoystickDriver.c"
//#pragma DebuggerWindows("joystickSimple")
#include "motorFunctions.h"

#include "initialize.h"

task main() {

	initialize();

	waitForStart();

	// declaring global control variables
	int transX, transY, rot;

	//config stuff
	int deadzone = 15;

	// main tele-op loop
	while(true) {

		// get joystick values

		// hogCPU(); and releaseCPU(); may or may not be necessary! ??? inserted for testing, may be removed later!
		hogCPU();
		getJoystickSettings(joystick);
		releaseCPU();

		// process values etc
		transX = joystick.joy1_x1;
		transY = joystick.joy1_y1;
		rot = joystick.joy1_x2;


		if(abs(transX) < deadzone) {
			transX = 0;
		}

		if(abs(transY) < deadzone) {
			transY = 0;
		}

		if(abs(rot) < deadzone) {
			rot = 0;
		}

		mecanumDrive(transX, transY, rot);

		// athena's arm up and down code
		if(abs(joystick.joy1_y2) > deadzone){
      motor[manipRight] = joystick.joy1_y2;
      motor[manipLeft] = joystick.joy1_y2;
    }
    else{
    	motor[manipRight] = 0;
    	motor[manipLeft] = 0;
  	}

  	//manip movement code
  	if (joy1Btn(1) == true){
  		servo[armmanip1] = 25;
  		servo[armmanip2] = 25;
  	}
  	else{
  		servo[armmanip1] = 0;
  		servo[armmanip2] = 0;
  	}

  //goal code
  	if(joy1Btn(3) == true) {
  		servo[gatemanip] = 50;
  	}
  	if(joy1Btn(2) == true) {
  		servo[gatemanip] = -50;
		}
	}
}