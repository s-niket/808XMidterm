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
 * @file Controller.hpp
 * @author Niket Shah Zachary Zimits
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of a controller for a tricycle
 *        where it can enable the vehicle to make a turn
 *        at a specified orientation and run at a specified
 *        velocity
 *
 */
#include <math.h>
#include <iostream>
#include "Vehicle.hpp"
#include "Controller.hpp"

int main() {
  double steeringAngleConstraint = 45;
  double wheelDiameter = 2;
  double trackWidth = 4;
  double wheelBase = 4;
  double desiredOrientation;
  double desiredVelocity;
  Vehicle tricycle(wheelDiameter, steeringAngleConstraint, trackWidth,
                   wheelBase);
  std::cout << "Please enter the desired orientation (0 to 360 degrees): "
            << std::endl;
  std::cin >> desiredOrientation;
  std::cout << "Please enter the desired velocity: ";
  std::cin >> desiredVelocity;
  tricycle.setVelocity(desiredVelocity);
  tricycle.setOrientation(desiredOrientation);
  while (fabs(tricycle.getOrientation() - desiredOrientation) > 1
      || fabs(tricycle.getVelocity() - desiredVelocity) > .5) {
    tricycle.update();
    std::cout << "Current Orientation: " << tricycle.getOrientation()
              << " Current Velocity: " << tricycle.getVelocity() << "\n";
  }
  std::cout << "You have achieved your desired orientation and velocity!"
      << std::endl;
  return 0;
}
