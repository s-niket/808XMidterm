/**
 * @file Controller.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Controller class
 */

#ifndef INCLUDE_CONTROLLER_HPP
#define INCLUDE_CONTROLLER_HPP

#include "Vehicle.hpp"
#include <iostream>
/**
 * @brief Class Controller
 * Class defines controller attributes and
 * member functions to calculate error and
 * get the contoller output for orientation
 * and velocity
 */

class Controller : Vehicle {
 private:
  double kp;
  double kd;
  double ki;
  //double steeringConstraint;
  double steeringAngle;
  double leftWheelSpeed;
  double rightWheelSpeed;
  //double vehicleSpeed;
  //double WheelDiameter;
  //double trackWidth;


  //new variables
  double errorThreshold = 0.001;
  double previousError = 0;
  double previousErrorSum = 0;
  double dTime = 0;

  double calculateError(double initial, double desired) {
    double error = 0;
    return error;
  }

  double implementPID(){
    double output;
    return output;
  }

  double calculateSteeringAngle(){
    double steeringAngle;
    return steeringAngle;
  }

  double calculateWheelSpeedRatio(){
    double wheelSpeeds;
    return wheelSpeeds;
  }

 public:
  Controller(double kp, double kd, double ki, double rightWheelSpeed,
             double leftWheelSpeed);

  double compute(){
    double output;
    return output;
  }

  ~Controller();
};

#endif //INLCUDE_CONTROLLER_HPP
