/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  GNU Public License
 * @brief      Defines test cases for class Controller's
 *             member functions.
 */
#include <gtest/gtest.h>
#include "Controller.hpp"

TEST(calcError, errorBetweenTwoTerms) {
  Controller pid(0.1, 0.1, 0.1, 45, 4, 4, 4);
  ASSERT_DOUBLE_EQ(10, pid.calculateError(20, 10));
  ASSERT_DOUBLE_EQ(5.2, pid.calculateError(7.5, 12.7));

}
TEST(implementPID, ) {

}

TEST(calcSteeringAngle, differenceOfTwoOrientations) {
  Controller pid(0.1, 0.1, 0.1, 30, 4, 4, 4);
  ASSERT_DOUBLE_EQ(pid.calculateSteeringAngle(10, 50), 30);
  ASSERT_DOUBLE_EQ(pid.calculateSteeringAngle(45, 30), -15);
}

TEST(calcVehicleSpeed, differenceOfTwoSpeeds) {
  Controller pid(0.1, 0.1, 0.1, 30, 4, 4, 4);
  ASSERT_DOUBLE_EQ(pid.calculateVehicleSpeed(15, 25), 25);
}

TEST(calcWheelSpeedRatio, ) {

}

TEST(getVehicleSpeed, retrieveVehicleSpeed) {

}

TEST(getLeftWheelSpeed, retrieveLeftWheelSpeed) {

}

TEST(getRightWheelSpeed, retrieveRightWheelSpeed) {

}

TEST(getTurningRadius, retrieveTurningRadius) {

}

TEST(getSteeringAngle, retrieveSteeringAngle) {

}

TEST(compute, getSteeringAngleForGivenOrientations) {

}
