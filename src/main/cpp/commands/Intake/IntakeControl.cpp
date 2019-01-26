/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/IntakeControl.h"
#include "Robot.h"

IntakeControl::IntakeControl() {
  Requires(Robot::intakeSubsystem.get());
}

// Called just before this Command runs the first time
void IntakeControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeControl::Execute() {
  Robot::intakeSubsystem->SetSpeed(Robot::oi->GetOperatorJoystick()->GetLeftYAxis());
  if(Robot::oi->GetOperatorJoystick()->rightShoulderButton->Get()) {
    Robot::intakeSubsystem->SetWheelSpeed(1);
  }
  else if(Robot::oi->GetOperatorJoystick()->leftShoulderButton->Get()) {
    Robot::intakeSubsystem->SetWheelSpeed(-1);
  }
  else {
    Robot::intakeSubsystem->SetWheelSpeed(0);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeControl::IsFinished() { return false; }

// Called once after isFinished returns true
void IntakeControl::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeControl::Interrupted() {}
