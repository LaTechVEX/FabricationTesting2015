#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           LRWheel,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           LFWheel,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           RRWheel,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           RFWheel,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           Intake,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LFlywheel1,    tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port8,           LFlywheel2,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           RFlywheel,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	// Set the motors initially
	int Presets[4] = {0, 55, 85, 127};
	int currentPreset = 0;
	motor[LFlywheel1] = Presets[currentPreset];
	motor[LFlywheel2] = motor[LFlywheel1];
	motor[RFlywheel] = motor[LFlywheel2];

	while(true)
	{
		// Flywheel Speed
	 if(vexRT(Btn8U))
		currentPreset = 0;
	 else if (vexRT(Btn8R))
	  currentPreset = 1;
	 else if (vexRT(Btn8D))
	   currentPreset = 2;
	 else if (vexRT(Btn8L))
	   currentPreset = 3;

	  motor[LFlywheel1] = Presets[currentPreset];
	  motor[LFlywheel2] = motor[LFlywheel1];
		motor[RFlywheel] = motor[LFlywheel2];

		//Fit the input to an exponential curve
		//Squares are always positive, so a ternary operator is needed for negative numbers
		//The abs is just in case we decide to go with odd exponents
		int verticalL = abs(pow(vexRT(Ch3)/127.0,2.0))*127.0 *((vexRT(Ch3)>0)?(1):(-1));
		int verticalR = abs(pow(vexRT(Ch2)/127.0,2.0))*127.0 *((vexRT(Ch2)>0)?(1):(-1));

		// Move Robot
	  motor[LRWheel] = verticalL;
	  motor[LFWheel] = motor[LRWheel];
    motor[RRWheel] = verticalR;
    motor[RFWheel] = motor[RRWheel];

	   if(vexRT(Btn6U))
	     motor[Intake] = 127;
	 	 else if (vexRT(Btn5U))
	 	   motor[Intake] = 0;

	}
}
