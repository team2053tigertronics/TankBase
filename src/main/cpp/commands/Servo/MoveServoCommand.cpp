#include "commands/servo/MoveServoCommand.h"
#include "Robot.h"
#include "RobotMap.h"
#include "frc/smartdashboard/SmartDashboard.h"

MoveServoCommand::MoveServoCommand() {
    targetAngle1 = 0;
    targetAngle2 = 0;
    setAngle = 0;
    finalRotVal = 0;
    currentRotVal = 0;
    isAPressed = false; 
    isBPressed = false;
    isXPressed = false;
    isRightShoulderPressed = false;
    isRotDone = false;
}

void MoveServoCommand::Initialize()
{
    isAPressed = false; 
    isBPressed = false;
    isXPressed = false;
    isRightShoulderPressed = false;
    isRotDone = false;
}

void MoveServoCommand::Execute(){
    GetInputs();
//  currentRotVal = get it from the servo?????
    SmartDashboard::PutNumber("Servo angle", currentRotVal);
    SetAngleFromInput();
    RotateCommand();
    CheckRotationOverride();
}

bool MoveServoCommand::IsFinished(){
    return false;
}

/*
 * clean up
 */
void MoveServoCommand::End(){
    
}

void MoveServoCommand::GetInputs(){
    isAPressed = Robot::oi->GetOperatorJoystick()->aButton->Get();
    isBPressed = Robot::oi->GetOperatorJoystick()->bButton->Get();
    isXPressed = Robot::oi->GetOperatorJoystick()->xButton->Get();
    isRightShoulderPressed = Robot::oi->GetOperatorJoystick()->rightShoulderButton->Get();
}

void MoveServoCommand::SetAngleFromInput(){
    if(isAPressed) {
        setAngle = 0;
    }
    if(isBPressed) {
        setAngle = 90;
    }
    if(isXPressed) {
        setAngle = 180;
    }
    if(isRightShoulderPressed) {
        targetAngle1 = 45;
        targetAngle2 = 135; 
    }
}

void MoveServoCommand::RotateCommand(){
    //get the servo to move here
}

void MoveServoCommand::CheckRotationOverride(){
    //if a button is pressed
    finalRotVal = 0;
}