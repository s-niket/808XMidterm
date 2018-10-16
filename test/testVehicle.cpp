/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  GNU Public License
 * @brief      Defines test cases for class Vehicle's
 *             member functions.
 */
#include <gtest/gtest.h>
#include "Vehicle.hpp"

TEST(setOrientation, setDesiredOrientation) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.setOrientation(10), 10);
  EXPECT_EQ(tricycle.setOrientation(-10), -10);
}

TEST(setVelocity, setDesiredVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.setVelocity(20), 20);
  EXPECT_EQ(tricycle.setVelocity(-20), -20);

}

TEST(updateOrientation, updateCurrentOrientation) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_NEAR(tricycle.updateOrientation(), 0, 0.01);
  EXPECT_NEAR(tricycle.updateOrientation(), 0, 0.01);
}

TEST(updateVelocity, retrieveUpdatedVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.updateVelocity(), 0);
}

TEST(getVelocity, retriveVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  tricycle.updateVelocity();
  EXPECT_EQ(tricycle.getVelocity(), 0);
}
