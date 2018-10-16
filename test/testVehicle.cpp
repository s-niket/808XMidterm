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

}
