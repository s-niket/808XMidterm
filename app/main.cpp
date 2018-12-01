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
 * @file Controller.hpp
 * @author Niket Shah Zachary Zimits
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of a controller for a tricycle
 *        where it can enable the vehicle to make a turn
 *        at a specified orientation and run at a specified
 *        velocity
 *
 */
#include <iostream>
#include <math.h>
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
