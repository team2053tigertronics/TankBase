#include "Commands/Drive/DriveCommand.h"
#include "Robot.h"
#include "RobotMap.h"
#include "frc/smartdashboard/SmartDashboard.h"

/**
 * Constructor for DriveCommand
 * We set up our button states here
 * And make sure we Require() our subsystem so we can take authority
 * over other commands that may run on the drivebase
 */
DriveCommand::DriveCommand() {
	Requires(Robot::drivebaseSubsystem.get());

	throttleAxis = 0;
	turnAxis = 0;
	currentYaw = 0;
	finalRotVal = 0;
	setAngle = 0;
	isAPressed = false;
	isBPressed = false;
	isXPressed = false;
	isYPressed = false;
	isRightShoulderPressed = false;
	isRotDone = false;
}

/**
 * Runs when we first start a command
 * We reset our states here just to be safe
 */
void DriveCommand::Initialize() {
	throttleAxis = 0;
	turnAxis = 0;
	isAPressed = false;
	isBPressed = false;
	isXPressed = false;
	isYPressed = false;
	isRightShoulderPressed = false;
}

/**
 * Executes once every .2 seconds. We do all our calculations here
 * to tell the robot how to drive
 */
void DriveCommand::Execute() {
	GetInputs();
	currentYaw = Robot::drivebaseSubsystem->GetTigerDrive()->GetAdjYaw();
	isRotDone = Robot::drivebaseSubsystem->GetTigerDrive()->GetIsRotDone();
	SmartDashboard::PutNumber("Joystick Throttle", throttleAxis);
	SmartDashboard::PutNumber("Joystick Turn", turnAxis);
	SmartDashboard::PutBoolean("Quickturn", isRightShoulderPressed);
	SetAngleFromInput();
	RotateCommand();
	CheckRotateOverride();
	CallToTankDrive();
}

/**
 * We are never done with driving!
 * @return false
 */
bool DriveCommand::IsFinished() {
	return false;
}

/**
 * We dont need to clean up
 */
void DriveCommand::End() {

}

/**
 * Not useful
 */
void DriveCommand::Interrupted() {

}

/**
 * Grabs joystick state
 */
void DriveCommand::GetInputs() {
	throttleAxis = Robot::oi->GetDriverJoystick()->GetLeftYAxis();
	turnAxis = Robot::oi->GetDriverJoystick()->GetRightXAxis();

	isAPressed = Robot::oi->GetDriverJoystick()->aButton->Get();
	isBPressed = Robot::oi->GetDriverJoystick()->bButton->Get();
	isXPressed = Robot::oi->GetDriverJoystick()->xButton->Get();
	isYPressed = Robot::oi->GetDriverJoystick()->yButton->Get();
	isRightShoulderPressed = Robot::oi->GetDriverJoystick()->rightShoulderButton->Get();
}

/**
 * Based on the input, give us a target angle and set the PID target
 */
void DriveCommand::SetAngleFromInput() {
	if(isAPressed) {
		setAngle = 180;
	}
	if(isBPressed) {
		setAngle = 90;
	}
	if(isXPressed) {
		setAngle = -90;
	}
	if(isYPressed) {
		setAngle = 0;
	}
	Robot::drivebaseSubsystem->GetTigerDrive()->SetAngleTarget(setAngle);
}

/**
 * make sure we actually want to rotate and we dont get into weird
 * states where we double rotate
 */
void DriveCommand::RotateCommand()
{
	if(((isYPressed == true|| isXPressed == true || isAPressed == true || isBPressed == true) && isRotDone == true) || (isRotDone == false))
	{
		finalRotVal = Robot::drivebaseSubsystem->GetTigerDrive()->CalculateRotationValue(setAngle, .5);
	}
}

/**
 * make sure we are checking if we want to cancel rotating
 */
void DriveCommand::CheckRotateOverride() {
	if(Robot::drivebaseSubsystem->GetTigerDrive()->GetIsRotDoneOverride())
	{
		finalRotVal = 0;
	}
}

/**
 * This calls all the tank drive stuff so we actually move
 */
void DriveCommand::CallToTankDrive() {
	if(turnAxis == 0)
	{
		Robot::drivebaseSubsystem->GetTigerDrive()->SetIsRotDoneOverride(false);
		Robot::drivebaseSubsystem->TankDrive(throttleAxis, finalRotVal, isRightShoulderPressed);
	}
	else
	{
		Robot::drivebaseSubsystem->GetTigerDrive()->SetIsRotDoneOverride(true);
		Robot::drivebaseSubsystem->GetTigerDrive()->SetIsRotDone(true);
		Robot::drivebaseSubsystem->TankDrive(throttleAxis, turnAxis, isRightShoulderPressed);
	}
}
