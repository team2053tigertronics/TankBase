/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"

class IntakeSubsystem : public frc::Subsystem {
 private:
  std::unique_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> intakeTalon;
  std::unique_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> wheelTalon;
  int ChangeAngleToTicks(double angle);
 public:
  IntakeSubsystem();
  void InitDefaultCommand() override;
  void SetAngle(double angle);
  void SetSpeed(double speed);
  void SetWheelSpeed(double speed);
};
