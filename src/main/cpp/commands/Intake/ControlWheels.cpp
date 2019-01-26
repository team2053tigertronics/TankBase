/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/ControlWheels.h"
#include "Robot.h"

ControlWheels::ControlWheels(double speed) {
  Requires(Robot::intakeSubsystem.get());
  intakeSpeed = speed;
  isDone = false;
}

// Called just before this Command runs the first time
void ControlWheels::Initialize() {
  intakeSpeed = 0;
  isDone = false;
}

// Called repeatedly when this Command is scheduled to run
void ControlWheels::Execute() {
  if(intakeSpeed == 0) {
    Robot::intakeSubsystem->SetWheelSpeed(0);
    isDone = true;
  }
  else {
    Robot::intakeSubsystem->SetWheelSpeed(intakeSpeed);
    isDone = false;
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool ControlWheels::IsFinished() { return isDone; }

// Called once after isFinished returns true
void ControlWheels::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlWheels::Interrupted() {}
