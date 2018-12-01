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
 * @file Vehicle.hpp
 * @author Niket Shah Zachary Zimits
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of header for Vehicle class
 */

#include "Vehicle.hpp"
#include <iostream>
#include <math.h>

/**
 * @brief                Constructor for Vehicle class
 * @param wheelD         Defines the wheel diameters of type double
 * @param steerAngleConstraint Defines the steering angle
 *                             constraint of type double
 * @param trackW          Defines the track-width of the vehicle of type double
 */

Vehicle::Vehicle(double wheelD, double steerAngleConstraint, double trackW,
                 double wheelB)
    : pid(steerAngleConstraint, wheelD, trackW, wheelB) {
  wheelDiameter = wheelD;
  steeringAngleConstraint = steerAngleConstraint;
  trackWidth = trackW;
  wheelBase = wheelB;
  desiredOrientation = currentOrientation;
  desiredVelocity = currentVelocity;
  dimension = nullptr;
}

/**
 * @brief                Function to set the orientation of the
 *                       vehicle to a desired value
 * @param desiredOrient  Defines the desired orientation of type double
 * @return desiredOrientation Returns the desired orientation of the vehicle
 */

double Vehicle::setOrientation(double desiredOrient) {
  desiredOrientation = desiredOrient;
  return desiredOrientation;
}
/**
 * @brief                Function to set the velocity of the
 *                       vehicle to a desired value
 * @param desiredVelo    Defines the desired velocity of type double
 * @return desiredVelocity  Returns the desired velocity of the vehicle
 */
double Vehicle::setVelocity(double desiredVelo) {
  desiredVelocity = desiredVelo;
  return desiredVelocity;
}
/**
 * @brief                Function to update the orientation of
 *                       the vehicle to a desired value
 * @return currentOrientation  Returns the current orientation of the vehicle
 *                             after the turn of type double
 */

double Vehicle::updateOrientation() {
  double orientation;
  double deltaOrientation;
  double distanceTraveled = currentVelocity * dTime;
  if (pid.getTurningRadius() == 0)
    deltaOrientation = 0;
  else
    deltaOrientation = (distanceTraveled * 360)
        / (2 * M_PI * pid.getTurningRadius());
  if (pid.getSteeringAngle() > 0)
    orientation = currentOrientation + deltaOrientation;
  else
    orientation = currentOrientation - deltaOrientation;
  if (orientation >= 360)
    currentOrientation = orientation - 360;
  else if (orientation < 0)
    currentOrientation = 360 + orientation;
  else
    currentOrientation = orientation;
  return currentOrientation;
}
/**
 * @brief                Function to update the velocity of
 *                       the vehicle to a desired value
 * @param newVelocity    Defines the desired velocity of type double
 * @return currentVelocity  Returns the current velocity of the
 *                          vehicle after the update
 */
double Vehicle::updateVelocity() {
  currentVelocity = pid.getVehicleSpeed();
  return currentVelocity;
}
/**
 * @brief                Function to calculate the controller output
 *                       then call the update velocity and orientation
 *                       functions.
 * @return currentVelocity  Returns the current orientation
 */
double Vehicle::update() {
  pid.compute(currentOrientation, desiredOrientation,
            currentVelocity, desiredVelocity);
  updateVelocity();
  updateOrientation();
  return currentOrientation;
}

/**
 * @brief                Function to get the value of orientation
 * @return currentOrientation  Returns the current orientation of the vehicle
 */
double Vehicle::getOrientation() {
  return currentOrientation;
}

/**
 * @brief                Function to get the value of orientation
 * @return currentOrientation  Returns the current orientation of the vehicle
 */
double Vehicle::getVelocity() {
  return currentVelocity;
}

/*
 * @brief Destructor for Vehicle class
 */
Vehicle::~Vehicle() {
}

// New method for GMock Testing

/*
 * @brief Get length ofthe vehicle
 * @param none
 * @return double len: length of the vehicle
 */
double Vehicle::getVehicleLength() {
  double len = dimension->getLength();
  return len;
}

/*
 * @brief Get width of the vehicle
 * @param none
 * @return double wid: width of the vehicle
 */
double Vehicle::getVehicleWidth() {
  double wid = dimension->getWidth();
  return wid;
}

