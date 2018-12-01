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
 * @author Niket Shah
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Header for Vehicle class
 */

#ifndef INCLUDE_VEHICLE_HPP_
#define INCLUDE_VEHICLE_HPP_

#include <iostream>
#include "Controller.hpp"
#include "Dimensions.hpp"
/**
 * @brief Class Vehicle
 * Class defines vehicle attributes and
 * member functions to update vehicle's orientation
 * and velocity to a desired value
 */

class Vehicle {
 private:
  double wheelDiameter;/*!<diameter of the wheels  */
  double dTime = 0.05;/*!< Time step for controller inputs */
  double steeringAngleConstraint;/*!< For restricting the motion of steering */
  double trackWidth;/*!<The distance between the two back wheels  */
  double wheelBase;/*!<The length between the front and the back wheels  */
  double currentVelocity = 1;/*!<The current velocity of the vehicle  */
  double desiredVelocity;/*!<The desired velocity of the vehicle  */
  double currentOrientation = 0;/*!<dThe current orientation of the vehicle  */
  double desiredOrientation;/*!<The desired orientation of the vehicle  */
  Controller pid;/*!<Instance of the controller class  */
  Dimensions* dimension;


 public:
  /*
   * @brief Constructor of class Vehicle
   */
  Vehicle(double wheelDiameter, double steeringAngleConstraint,
          double trackWidth, double wheelBase);

  explicit Vehicle(Dimensions* dim) : dimension(dim),
        wheelDiameter(0),
        steeringAngleConstraint(0),
        trackWidth(0),
        wheelBase(0),
        currentVelocity(0),
        desiredVelocity(0),
        currentOrientation(0),
        desiredOrientation(0),
        pid(0, 0, 0, 0) {

  }

  /*
   *  @brief Method to set the vehicle's dersired orientation
   */
  double setOrientation(double desiredOrient);

  /*
   * @brief Method to set vehicle's desired velocity
   */
  double setVelocity(double desiredVelo);

  /*
   * @brief Method to update the orientation of the vehicle
   */
  double updateOrientation();

  /*
   * @brief Method to update velocity of the vehicle
   */
  double updateVelocity();

  /*
   * @brief Method to calculate a controller output and update the vehicle
   */
  double update();

  /*
   * @brief Method to return the orientation of the vehicle
   */
  double getOrientation();

  /*
   * @brief Method to return the velocity of the vehicle
   */
  double getVelocity();

  /*
   * @brief Destructor for class Vehicle
   */
  ~Vehicle();

  // New method for GMock Testing

  /*
   * @brief Get length of the vehicle
   */
  double getVehicleLength();

  /*
   * @brief Get vehicle's width
   */
  double getVehicleWidth();

};


#endif  // INCLUDE_VEHICLE_HPP_
