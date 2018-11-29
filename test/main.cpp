/**
 * @file       main.cpp
 * @author     Niket Shah Zachary Zimits
 * @copyright  2018 GNU Public License
 * @brief      Implements the tests for the
 *             member functions.
 */
#include <gtest/gtest.h>
#include "gmock/gmock.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  ::testing::GTEST_FLAG(throw_on_failure) = true;
  ::testing::InitGoogleMock(&argc, argv);
}
