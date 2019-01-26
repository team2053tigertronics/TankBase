#include "OI.h"
#include "RobotMap.h"

#include "commands/Intake/ControlWheels.h"

OI::OI() {
    driverJoystick = std::make_unique<TigerJoystick>(JOYSTICK_DRIVER);
    operatorJoystick = std::make_unique<TigerJoystick>(JOYSTICK_OPERATOR);

    //operatorJoystick->rightShoulderButton->WhenActive(new ControlWheels(1));
    //operatorJoystick->rightShoulderButton->WhenInactive(new ControlWheels(0));

    //operatorJoystick->leftShoulderButton->WhenActive(new ControlWheels(-1));
    //operatorJoystick->leftShoulderButton->WhenInactive(new ControlWheels(0));
}

const std::unique_ptr<TigerJoystick>& OI::GetDriverJoystick() {
    return driverJoystick;
}

const std::unique_ptr<TigerJoystick>& OI::GetOperatorJoystick(){
    return operatorJoystick;
}