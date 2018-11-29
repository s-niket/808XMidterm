#include "gmock/gmock.h"
#include "Controller.hpp"

class MockController : public Controller {
 public:
  MOCK_METHOD2(calculateSteeringAngle, double(double currentOrientation,
                                              double desiredOrientation));
  MOCK_METHOD2(calculateVehicleSpeed, double(double currentVelocity, double desiredVelocity);
  MOCK_METHOD0(calculateWheelSpeedRatio, double());
  MOCK_METHOD0(getVehicleSpeed, double());
  MOCK_METHOD0(getLeftWheelSpeed, double());
  MOCK_METHOD0(getRightWheelSpeed, double());
  MOCK_METHOD0(getTurningRadius, double());
  MOCK_METHOD0(getSteeringAngle, double());
  MOCK_METHOD4(compute,double(double currentOrientation, double desiredOrientation,
                 double currentVelocity, double desiredVelocity));
  MOCK_METHOD1(setPgain, void(double _kp));
  MOCK_METHOD1(getPgain, double());
};
