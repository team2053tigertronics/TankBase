/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSubsystem.h"
#include "commands/Intake/IntakeControl.h"
#include "RobotMap.h"
IntakeSubsystem::IntakeSubsystem() : Subsystem("IntakeSubsystem") {
  intakeTalon = std::make_unique<ctre::phoenix::motorcontrol::can::TalonSRX>(INTAKE_TALON_ID);
  wheelTalon = std::make_unique<ctre::phoenix::motorcontrol::can::TalonSRX>(WHEEL_INTAKE_TALON_ID);

  intakeTalon->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative);
}

void IntakeSubsystem::InitDefaultCommand() {
  SetDefaultCommand(new IntakeControl());
}

void IntakeSubsystem::SetAngle(double angle) {
  int ticks = ChangeAngleToTicks(angle);
  intakeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::Position, ticks);
}

int IntakeSubsystem::ChangeAngleToTicks(double angle) {
  int ticks = angle / 360.0 * 4096;;
  return ticks;
}

void IntakeSubsystem::SetSpeed(double speed) {
  intakeTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::SetWheelSpeed(double speed) {
  wheelTalon->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed);
}
