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
 * @copyright 2018 Niket Shah
 * @brief Header for Controller class
 */

#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_


#include <iostream>

/**
 * @brief Class Controller
 * Class defines controller attributes and
 * member functions to calculate error and
 * get the contoller output for orientation
 * and velocity
 */

class Controller {
 private:
  double steeringConstraint;/*!<maximum value for steering angle  */
  //
  double steeringAngle = 0;/*!<Steering angle to be needed for motion  */
  //
  double turningRadius = 0;/*!<Turning Radius  */
  //
  double leftWheelSpeed = 0;/*!<Speed of left wheel of the vehicle  */
  //
  double rightWheelSpeed = 0;/*!<Speed of right wheel of the vehicle  */
  //
  double vehicleSpeed = 0;/*!<Speed of the entire vehicle  */
  //
  double wheelCircumference;/*!<Circumference of the wheels  */
  //
  double trackWidth;/*!<Distance between the two rear wheels  */
  //
  double wheelBase;/*!<Distance between the front and rear wheels  */
  double acceleration = 1.1;/*!<value to increment the velocity  */

  // new variables
  // Threshold for PID controller
  double errorThreshold = 0.001;
  // Previous error for the controller
  double previousError = 0;
  // Sum of previous errors
  double previousErrorSum = 0;
  // Difference in time intervals
  double dTime = 0;

 public:
  /*
   * @brief Calculate steering angle to execute the turn
   */
  double calculateSteeringAngle(double currentOrientation,
                                double desiredOrientation);

  /*
   * @brief Calculate the total vehicle velocity
   */
  double calculateVehicleSpeed(double currentVelocity, double desiredVelocity);

  /*
   * @brief Calculate the wheel speed ratios for
   *        getting the different wheel speeds
   */
  double calculateWheelSpeedRatio();

  /*
   * @brief Returns the vehicle Speed
   */
  double getVehicleSpeed();

  /*
   * @brief Returns the Left Wheel Speed
   */
  double getLeftWheelSpeed();
  /*
   * @brief Returns the Right Wheel Speed
   */
  double getRightWheelSpeed();
  /*
   * @brief Returns the Turning Radius
   */
  double getTurningRadius();
  /*
   * @brief Returns the steering angle
   */
  double getSteeringAngle();

  /*
   * @brief Constructor for Controller class
   */
  Controller(double steeringConstraint, double wheelDiameter, double trackWidth,
             double wheelBase);

  /*
   * @brief Function to compute the final orientation and
   * velocities of the vehicle
   */
  double compute(double currentOrientation, double desiredOrientation,
                 double currentVelocity, double desiredVelocity);

  /*
   *@brief Destructor for class Controller
   */
  ~Controller();
};
#endif  // INCLUDE_CONTROLLER_HPP_
