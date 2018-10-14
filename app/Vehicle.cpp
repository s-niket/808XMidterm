/**
 * @file Controller.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Implementation of header for Vehicle class
 */

#include "Vehicle.hpp"
#include <iostream>
#include <math.h>

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
  wheelBase = wheelB;
}

Vehicle::~Vehicle() {
}

double Vehicle::updateOrientation(){
  double _orientation;
  double distanceTraveled = currentVelocity * dTime;
  double deltaOrientation = (distanceTraveled*360)/(2*M_PI*orientControl.getTurningRadius());
  if(orientControl.getSteeringAngle()>0)
	  currentOrientation += deltaOrientation;
  else
	  currentOrientation -= deltaOrientation;
  return currentOrientation;
}

double Vehicle::updateVelocity(){
  double leftWheelSpeed = orientControl.getLeftWheelSpeed();
  double rightWheelSpeed = orientControl.getRightWheelSpeed();
  currentVelocity = (leftWheelSpeed+rightWheelSpeed)/2;
  return currentVelocity;
}

double Vehicle::getOrientation(){
	return currentOrientation;
}

double Vehicle::getVelocity(){
	return currentVelocity;
}
