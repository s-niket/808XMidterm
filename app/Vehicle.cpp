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
 * @param steerAngleConstraint Defines the steering angle
 *                             constraint of type double
 * @param trackW          Defines the track-width of the vehicle of type double
 */

Vehicle::Vehicle(double wheelD, double steerAngleConstraint, double trackW,
                 double wheelB) : pid(.1, .1, .1, steerAngleConstraint, wheelD, trackW,
               		  wheelB) {
  wheelDiameter = wheelD;
  steeringAngleConstraint = steerAngleConstraint;
  trackWidth = trackW;
  wheelBase = wheelB;
  desiredOrientation = currentOrientation;
  desiredVelocity = currentVelocity;
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
 * @param turnRadius     Defines the radius to execute the turn of type double
 * @param steeringAngle  Defines the steering angle to execute
 *                       the turn of type double
 * @return currentOrientation  Returns the current orientation of the vehicle
 *                             after the turn of type double
 */
double Vehicle::updateOrientation() {
  double orientation;

  double distanceTraveled = currentVelocity * dTime;
  double deltaOrientation = (distanceTraveled * 360) / (2 * M_PI * pid.getTurningRadius());
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
 *                          vehicle after the updation
 */
double Vehicle::updateVelocity() {
  currentVelocity = pid.getVehicleSpeed();
  return currentVelocity;
}

double Vehicle::update(){
	pid.compute(currentOrientation, desiredOrientation,
            currentVelocity, desiredVelocity);
	updateVelocity();
	updateOrientation();
	return 0;
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
