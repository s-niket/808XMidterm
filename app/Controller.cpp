/**
 * @file Controller.hpp
 * @author Niket Shah
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

Controller::Controller(double gainP, double gainD, double gainI, double steeringLimit,
		  double wheelDiameter, double width, double base){
  kp = gainP;
  ki = gainI;
  kd = gainD;
  steeringConstraint = steeringLimit;
  wheelCircumference = wheelDiameter;
  trackWidth = width;
  wheelBase = base;
}

/**
 * @brief                Method to calculate error
 * @param initialValue   initial value of velocity/orientation of type double
 * @param desiredValue   final value of velocity/orientation of type double
 */

double Controller::calculateError(double initialValue, double desiredValue) {
  double error = initialValue - desiredValue;
  return error;
}

/**
 * @brief                Method to implement PID given the gains and the initial
 *                       desired values
 * @return               the output of the controller after implemenation of PID
 */
double Controller::calculateVehicleSpeed(double currentVelocity,
                                         double desiredVelocity) {
  double deltaVelocity = desiredVelocity - currentVelocity;
  if (deltaVelocity > 0)
    if (acceleration + currentVelocity > desiredVelocity)
      vehicleSpeed = desiredVelocity;
    else
      vehicleSpeed = acceleration + currentVelocity;
  else
    if (currentVelocity - acceleration < desiredVelocity) {
    vehicleSpeed = desiredVelocity;
  }
    else {
    vehicleSpeed = currentVelocity - acceleration;
  }

double Controller::implementPID() {
 /* while (fabs(desiredVelocity - currentVelocity) > errorThreshold) {
    double proportionalError = calculateError(currentVelocity, desiredVelocity);
    double derivativeError = (proportionalError - previousError) / dTime;
    previousErrorSum += (proportionalError * dTime);
    double integralError = previousErrorSum;
    double controllerOutput = kp * proportionalError + kd * derivativeError
        + ki * integralError;
    currentVelocity += controllerOutput;
  }
  return currentVelocity;
  */
	return 0;
}

Controller::~Controller(){

}

double Controller::calculateSteeringAngle(double currentOrientation, double desiredOrientation){
  double deltaOrientation = desiredOrientation - currentOrientation;
  if(fabs(deltaOrientation) >= steeringConstraint)
	  steeringAngle = steeringConstraint*(deltaOrientation/fabs(deltaOrientation));
  else
	  steeringAngle = deltaOrientation;
  return steeringAngle;
}


double Controller::calculateVehicleSpeed(double currentVelocity, double desiredVelocity){
  double deltaVelocity = desiredVelocity - currentVelocity;
  if(deltaVelocity>0)
	  if(acceleration+currentVelocity>desiredVelocity)
	  currentVelocity=desiredVelocity;
	  else
		  currentVelocity = acceleration+currentVelocity;
  else
	  if(currentVelocity-acceleration<desiredVelocity)
	  	  currentVelocity=desiredVelocity;
	  else
	  	  currentVelocity = currentVelocity-acceleration;

  return currentVelocity;
}

double Controller::calculateWheelSpeedRatio(){
  double radiusRatio;
  double rearSpeed = vehicleSpeed/wheelCircumference;
  if(steeringAngle != 0)
  {
	  turningRadius = wheelBase/tan(abs(steeringAngle)*M_PI/180);
	  double leftRearRadius = turningRadius -(wheelBase/2);
	  double rightRearRadius = turningRadius +(wheelBase/2);
	  if(steeringAngle>0)
		 radiusRatio= leftRearRadius/rightRearRadius;
	  else
		  radiusRatio=rightRearRadius/leftRearRadius;
  }
  else
	  radiusRatio=1;
  leftWheelSpeed = rearSpeed*radiusRatio;
  rightWheelSpeed = rearSpeed/radiusRatio;
  return radiusRatio;
}

double Controller::getLeftWheelSpeed(){
	return leftWheelSpeed;
}

double Controller::getRightWheelSpeed(){
	return rightWheelSpeed;
}

double Controller::getTurningRadius(){
	return turningRadius;
}

double Controller::getSteeringAngle(){
	return steeringAngle;
}
double Controller::compute(double currentOrientation,double desiredOrientation, double currentVelocity, double desiredVelocity){
  calculateSteeringAngle(currentOrientation,desiredOrientation);
  implementPID();
  calculateVehicleSpeed(currentVelocity,desiredVelocity);
  calculateWheelSpeedRatio();
  return steeringAngle;

}
