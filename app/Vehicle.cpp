/**
 * @file Controller.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of header for Vehicle class
 */

#include "Vehicle.hpp"
#include <iostream>

/**
 * @brief                Constructor for Vehicle class
 * @param wheelD         Defines the wheel diameters of type double
 * @param steerAngleConstraint Defines the steering angle constraint of type double
 * @param trackW          Defines the track-width of the vehicle of type double
 */

Vehicle::Vehicle(double wheelD,double steerAngleConstraint,
          double trackW){
  wheelDiameter = wheelD;
  steeringAngleConstraint = steerAngleConstraint;
  trackWidth = trackW;
}

Vehicle::~Vehicle() {
}


