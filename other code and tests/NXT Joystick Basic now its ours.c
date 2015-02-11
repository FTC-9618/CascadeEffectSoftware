#include "JoystickDriver.c"
#pragma DebuggerWindows("joystickSimple")

task main()
{
  while(1 == 1)
  {
    getJoystickSettings(joystick);
    motor[motorC] = joystick.joy1_y1;
    motor[motorB] = joystick.joy1_y1;
  }
  if(joystick.joy1_y1 <10 && joystick.joy1_y1> -10)
	{
		/*move forward*/
		motor[motorC] = -10;
		/*motor[LeftMotor2] = 0;*/
	}
	else
	{
		motor[motorC] = 0;
		/*motor[LeftMotor2] = joystick.joy1_y1/2;*/

	}
	if (joystick.joy1_y1 <10 && joystick.joy1_y1> -10)
	{
	motor[motorB] = 10;
	}
	else
	{
		motor[motorB] = 0;
	}
}
