/* functions for driving mecanums, etc.
/
/
*/

// basic mecanum function
void mecanumDrive(int transX, int transY, int rot) {
	motor[frontRight] = transY - rot - transX;
	motor[backRight] = transY - rot + transX;
	motor[frontLeft] = transY + rot + transX;
	motor[backLeft] = transY + rot - transX;
}
