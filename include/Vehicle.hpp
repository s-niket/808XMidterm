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
