/**
 * Copyright 2018, Niket Shah
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @file       test.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  2018 GNU Public License
 * @brief      Defines test cases for class Vehicle's
 *             member functions.
 */
#include <gtest/gtest.h>
#include "Vehicle.hpp"
#include <gmock/gmock.h>
#include "Dimensions.hpp"

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
  EXPECT_CALL(dimension,getWidth()).Times(AtLeast(1));
  Vehicle batmobile(&dimension);
  EXPECT_EQ(0, batmobile.getVehicleLength());
  EXPECT_EQ(0, batmobile.getVehicleWidth());
  }

