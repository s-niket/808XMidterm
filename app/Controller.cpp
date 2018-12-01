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
 * @author Niket Shah Zachar Zimits
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of header for Controller class
 */

#include "Controller.hpp"
#include <math.h>

/**
 * @brief                Constructor for Controller class
 * @param gainP          Proportional gain of type double
 * @param gainI          Integral gain of type double
 * @param gainD          Derivative gain of type double
 */

Controller::Controller(double steeringLimit, double wheelDiameter, double width,
                       double base) {
  steeringConstraint = steeringLimit;
  wheelCircumference = wheelDiameter;
  trackWidth = width;
  wheelBase = base;
}

/**
 * @brief                Method to calculate steering angle for executing turn
 * @param currentOrientation   Initial value of orientation of type double
 * @param desiredOrientation   Final value of orientation of type double
 * @return steeringAngle       Value of steering angle after introducing steering
 *                             constraint of type double
 */
double Controller::calculateSteeringAngle(double currentOrientation,
                                          double desiredOrientation) {
  double deltaOrientation = desiredOrientation - currentOrientation;
  if (fabs(deltaOrientation) >= steeringConstraint)
    steeringAngle = steeringConstraint
        * (deltaOrientation / fabs(deltaOrientation));
  else
    steeringAngle = deltaOrientation;
  return steeringAngle;
}
/**
 * @brief                Method to calculate vehicle speed to set it to the
 *                       desired value by introducing acceleration
 * @param currentVelocity   Initial value of velocity of type double
 * @param desiredVelocity   Final value of velocity of type double
 * @return vehicleSpeed     Value of vehicle speed after acceleration of type double
 */
double Controller::calculateVehicleSpeed(double currentVelocity,
                                         double desiredVelocity) {
  double deltaVelocity = desiredVelocity - currentVelocity;
  if (deltaVelocity > 0) {
    if (acceleration + currentVelocity > desiredVelocity) {
      vehicleSpeed = desiredVelocity;
    else
      vehicleSpeed = acceleration + currentVelocity;

    else if (currentVelocity - acceleration < desiredVelocity)
    vehicleSpeed = desiredVelocity;
    else
    vehicleSpeed = currentVelocity - acceleration;
  }

  return vehicleSpeed;
}
/**
 * @brief                Method to calculate vehicle's wheel speed ratio to
 *                       get the different wheel speeds
 * @return radiusRatio   Value of radius ratio of type double
 */
double Controller::calculateWheelSpeedRatio() {
  double radiusRatio;
  double rearSpeed = vehicleSpeed / wheelCircumference;
  if (steeringAngle != 0) {
    turningRadius = wheelBase / tan(abs(steeringAngle) * M_PI / 180);
    double leftRearRadius = turningRadius - (wheelBase / 2);
    double rightRearRadius = turningRadius + (wheelBase / 2);
    if (steeringAngle > 0)
      radiusRatio = leftRearRadius / rightRearRadius;
    else
      radiusRatio = rightRearRadius / leftRearRadius;
    } else {
    radiusRatio = 1;
    }
  leftWheelSpeed = rearSpeed * radiusRatio;
  rightWheelSpeed = rearSpeed / radiusRatio;
  return radiusRatio;
}
/**
 * @brief                Method to get vehicle speed
 * @return radiusRatio   Value of vehicle speed of type double
 */
double Controller::getVehicleSpeed() {
  return vehicleSpeed;
}
/**
 * @brief                Method to get vehicle's left wheel speed
 * @return radiusRatio   Value of left wheel speed of type double
 */
double Controller::getLeftWheelSpeed() {
  return leftWheelSpeed;
}
/**
 * @brief                Method to get vehicle's right wheel speed
 * @return radiusRatio   Value of right wheel speed of type double
 */
double Controller::getRightWheelSpeed() {
  return rightWheelSpeed;
}
/**
 * @brief                Method to get vehicle's turning radius for
 *                       executing the turn
 * @return radiusRatio   Value of turning radius of type double
 */
double Controller::getTurningRadius() {
  return turningRadius;
}
/**
 * @brief                Method to get steering angle for executing the turn
 * @return radiusRatio   Value of steering angle of type double
 */
double Controller::getSteeringAngle() {
  return steeringAngle;
}
/**
 * @brief                Method to compute the vehicle's steering angle given a desired
 *                       orientation and velocity
 * @param currentOrientation   Initial value of orientation of type double
 * @param desiredOrientation   Final value of orientation of type double
 * @param currentVelocity   Initial value of velocity of type double
 * @param desiredVelocity   Final value of velocity of type double
 * @return steeringAngle    Value of steering angle required for the turn of type double
 */
double Controller::compute(double currentOrientation, double desiredOrientation,
                           double currentVelocity, double desiredVelocity) {
  calculateSteeringAngle(currentOrientation, desiredOrientation);
  calculateVehicleSpeed(currentVelocity, desiredVelocity);
  calculateWheelSpeedRatio();
  return steeringAngle;
}
/*
 * @brief Destructor for Vehicle class
 */
Controller::~Controller() {
}

