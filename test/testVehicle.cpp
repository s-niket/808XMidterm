/**
 * Copyright 2018, Niket Shah
 *
 *Copyright (c) 2018 Niket Shah

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  2018 GNU Public License
 * @brief      Defines test cases for class Vehicle's
 *             member functions.
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Dimensions.hpp"
#include "Vehicle.hpp"

using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Expectation;
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


// GMock Testing


class MockDimensions : public Dimensions {
 public:
  MockDimensions(double a, double b)
      : Dimensions(a, b) {
  }
  MOCK_METHOD0(getLength, double());
  MOCK_METHOD0(getWidth, double());
};

/*
 * @brief test for checking if the dimensions of the vehicle
 *        are rightly passed from the Dimensions class to the Vehicle class
 */
TEST(DimensionsCheck, checkIfDimensionsPassed) {
  MockDimensions dimension(0, 0);
  EXPECT_CALL(dimension, getLength()).Times(AtLeast(1));
  EXPECT_CALL(dimension, getWidth()).Times(AtLeast(1));
  Vehicle batmobile(&dimension);
  EXPECT_EQ(0, batmobile.getVehicleLength());
  EXPECT_EQ(0, batmobile.getVehicleWidth());
  }

