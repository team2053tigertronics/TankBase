#pragma once

#include <frc/commands/Command.h>

class MoveServoCommand : public frc::Command {
public:
    MoveServoCommand();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void GetInputs();
    void SetAngleFromInput();
    void RotateCommand();
    void CheckRotationOverride();
private: 
    double targetAngle1;
    double targetAngle2;
    double setAngle;
    double finalRotVal;
    double currentRotVal;
    bool isAPressed;
    bool isBPressed;
    bool isXPressed;
    bool isRightShoulderPressed;
    bool isRotDone;
}