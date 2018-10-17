/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  2018 GNU Public License
 * @brief      Defines test cases for class Vehicle's
 *             member functions.
 */
#include <gtest/gtest.h>
#include "Vehicle.hpp"
/*
 * @brief Test for setOrientation()
 */
TEST(setOrientation, setDesiredOrientation) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.setOrientation(10), 10);
  EXPECT_EQ(tricycle.setOrientation(270), 270);
}
/*
 * @brief Test for setDesiredVelocity()
 */
TEST(setVelocity, setDesiredVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.setVelocity(20), 20);
  EXPECT_EQ(tricycle.setVelocity(-20), -20);

}
/*
 * @brief Test for updateOrientation()
 */
TEST(updateOrientation, updateCurrentOrientation) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_NEAR(tricycle.updateOrientation(), 0, 0.01);
  tricycle.setOrientation(10);
  tricycle.update();
  EXPECT_NEAR(tricycle.updateOrientation(), 1.01, 0.01);
  tricycle.setOrientation(-40);
  tricycle.update();
  EXPECT_NEAR(tricycle.updateOrientation(), 357.7, 0.01);
  tricycle.setOrientation(400);
  tricycle.update();
  EXPECT_NEAR(tricycle.updateOrientation(), 1.01, 0.01);
}
/*
 * @brief Test for updateVelocity()
 */
TEST(updateVelocity, retrieveUpdatedVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.updateVelocity(), 0);
}
/*
 * @brief Test for getVelocity()
 */
TEST(getVelocity, retriveVelocity) {
  Vehicle tricycle(4, 30, 2, 1);
  tricycle.updateVelocity();
  EXPECT_EQ(tricycle.getVelocity(), 0);
}
/*
 * @brief Test for getOrientation()
 */
TEST(getOrientation, retriveOrientation) {
  Vehicle tricycle(4, 30, 2, 1);
  EXPECT_EQ(tricycle.getOrientation(), 0);
}
