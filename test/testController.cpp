/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  GNU Public License
 * @brief      Defines test cases for class Controller's
 *             member functions.
 */
#include <gtest/gtest.h>
#include "Controller.hpp"

TEST(calcSteeringAngle, differenceOfTwoOrientations) {
  Controller pid(30, 4, 4, 4);

  ASSERT_DOUBLE_EQ(pid.calculateSteeringAngle(10, 50), 30);
  ASSERT_DOUBLE_EQ(pid.calculateSteeringAngle(45, 30), -15);
}

TEST(calcVehicleSpeed, differenceOfTwoSpeeds) {
  Controller pid(30, 4, 4, 4);
  ASSERT_DOUBLE_EQ(pid.calculateVehicleSpeed(15, 25), 16.1);
  ASSERT_DOUBLE_EQ(pid.calculateVehicleSpeed(25, 15), 23.9);
}

TEST(calcWheelSpeedRatio, getRadiusRatio) {
  Controller pid(30, 4, 4, 4);
  ASSERT_DOUBLE_EQ(pid.calculateWheelSpeedRatio(), 1);

}

TEST(getVehicleSpeed, retrieveVehicleSpeed) {
  Controller pid(30, 4, 4, 4);
  pid.calculateVehicleSpeed(15, 25);
  ASSERT_DOUBLE_EQ(pid.getVehicleSpeed(), 16.1);
}

TEST(getBothWheelSpeeds, retrieveLeftRightWheelSpeed) {
  Controller pid(30, 4, 4, 4);
  pid.calculateVehicleSpeed(15, 25);
  pid.calculateWheelSpeedRatio();
  ASSERT_DOUBLE_EQ(pid.getLeftWheelSpeed(), 4.025);
  ASSERT_DOUBLE_EQ(pid.getRightWheelSpeed(), 4.025);
  ASSERT_DOUBLE_EQ(pid.getTurningRadius(), 0);

}

TEST(compute, getSteeringAngleForGivenOrientations) {
  Controller pid(30, 4, 4, 4);
  ASSERT_DOUBLE_EQ(pid.calculateSteeringAngle(0, 90), 30);
  ASSERT_DOUBLE_EQ(pid.getSteeringAngle(), 30);


}

