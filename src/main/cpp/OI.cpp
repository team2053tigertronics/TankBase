#include "OI.h"
#include "RobotMap.h"

OI::OI() {
    driverJoystick() = std::make_unique<TigerJoystick>(JOYSTICK_DRIVER);
    operatorJoystick() = std::make_unique<TigerJoystick>(JOYSTICK_OPERATOR);
}

const std::unique_ptr<TigerJoystick>& OI::GetDriverJoystick() {
    return driverJoystick();
}

const std::unique_ptr<TigerJoystick>& OI::GetOperatorJoystick(){
    return operatorJoystick();
}