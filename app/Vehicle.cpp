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
          double trackW, double wheelB){
  wheelDiameter = wheelD;
  steeringAngleConstraint = steerAngleConstraint;
  trackWidth = trackW;
  wheelBase = wheelB;
}

Vehicle::~Vehicle() {
}

double Vehicle::setOrientation(double desiredOrient){
	desiredOrientation = desiredOrient;
	return desiredOrientation;
}

double Vehicle::setVelocity(double desiredVelo){
	desiredVelocity = desiredVelo;
	return desiredVelocity;
}

double Vehicle::updateOrientation(double turnRadius,double steeringAngle){
  double orientation;
  double distanceTraveled = currentVelocity * dTime;
  double deltaOrientation = (distanceTraveled*360)/(2*M_PI*turnRadius);
  if(steeringAngle>0)
	  orientation = currentOrientation + deltaOrientation;
  else
	  orientation = currentOrientation - deltaOrientation;
  if(orientation >= 360)
	  currentOrientation = orientation-360;
  else if(orientation < 0)
	  currentOrientation = 360+orientation;
  else
	  currentOrientation = orientation;
  return currentOrientation;
}

double Vehicle::updateVelocity(double newVelocity){
  currentVelocity = newVelocity;
  return currentVelocity;
}

double Vehicle::getOrientation(){
	return currentOrientation;
}

double Vehicle::getVelocity(){
	return currentVelocity;
}
