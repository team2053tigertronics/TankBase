#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/CANSparkMax.h>
#include <rev/CANSparkMaxLowLevel.h>

std::unique_ptr<DrivebaseSubsystem> Robot::drivebaseSubsystem;
std::unique_ptr<OI> Robot::oi;

std::unique_ptr<rev::CANSparkMax> Robot::test;

void Robot::RobotInit() {
  drivebaseSubsystem = std::make_unique<DrivebaseSubsystem>();
  oi = std::make_unique<OI>();
  test = std::make_unique<rev::CANSparkMax>(4, rev::CANSparkMaxLowLevel::MotorType::kBrushless);
}

void Robot::RobotPeriodic() {

}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::AutonomousInit() {
  test->Set(.5);
}

void Robot::AutonomousPeriodic() { 
  frc::Scheduler::GetInstance()->Run();
  SmartDashboard::PutNumber("ENCODER BRUSHLESS POS", test->GetEncoder().GetPosition());
  SmartDashboard::PutNumber("ENCODER BRUSHLESS VEL", test->GetEncoder().GetVelocity());
 }

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
}

void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() { 
  return frc::StartRobot<Robot>(); 
}
#endif
