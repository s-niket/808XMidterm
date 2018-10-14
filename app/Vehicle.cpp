/**
 * @file Controller.hpp
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
 * @param steerAngleConstraint Defines the steering angle constraint of type double
 * @param trackW          Defines the track-width of the vehicle of type double
 */

Vehicle::Vehicle(double wheelD,double steerAngleConstraint,
          double trackW){
  wheelDiameter = wheelD;
  steeringAngleConstraint = steerAngleConstraint;
  trackWidth = trackW;
  wheelBase = wheelB;
  desiredOrientation = currentOrientation;
  desiredVelocity = currentVelocity;
}

Vehicle::~Vehicle() {
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

double Vehicle::updateOrientation(){
  double orientation;
  double distanceTraveled = currentVelocity * dTime;
  double deltaOrientation = (distanceTraveled*360)/(2*M_PI*orientControl.getTurningRadius());
  if(orientControl.getSteeringAngle()>0)
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
double Vehicle::update(){
	pid.compute(currentOrientation, desiredOrientation,
            currentVelocity, desiredVelocity);
	updateVelocity();
	updateOrientation();
	return currentOrientation;
}

double Vehicle::updateVelocity(){
  double leftWheelSpeed = orientControl.getLeftWheelSpeed();
  double rightWheelSpeed = orientControl.getRightWheelSpeed();
  currentVelocity = (leftWheelSpeed+rightWheelSpeed)/2;
  return currentVelocity;
}
