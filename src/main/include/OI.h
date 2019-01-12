#pragma once

#include "Utilities/TigerJoystick/TigerJoystick.h"

class OI {
public:
  OI();
  const std::unique_ptr<TigerJoystick>& GetDriverJoystick();
  const std::unique_ptr<TigerJoystick>& GetOperatorJoystick();
private:
  std::unique_ptr<TigerJoystick> operatorJoystick();
  std::unique_ptr<TigerJoystick> driverJoystick();
};
