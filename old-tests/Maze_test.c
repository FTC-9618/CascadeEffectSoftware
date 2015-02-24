task main()
{
	motor[motorC]=50;
	motor[motorB]=50;
	wait1Msec(5000);
	motor[motorA]=30;
	motor[motorB]=0;
	motor[motorC]=0;
	wait1Msec(2000);
	motor[motorA]=0;
	motor[motorC]=-20;
	motor[motorB]=-20;
	wait1Msec(2000);
	motor[motorC]=-50;
	motor[motorB]=-50;
	wait1Msec(500);

}
