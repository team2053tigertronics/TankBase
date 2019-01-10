#pragma once

#include <frc/TimedRobot.h>
#include "OI.h"
#include "subsystems/DrivebaseSubsystem.h"
#include <rev/CANSparkMax.h>

class Robot : public frc::TimedRobot {
  public:
    static std::unique_ptr<DrivebaseSubsystem> drivebaseSubsystem;
    static std::unique_ptr<OI> oi;
    static std::unique_ptr<rev::CANSparkMax> test;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
  private:
};
