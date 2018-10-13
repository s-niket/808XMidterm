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
  // Proportional gain
  double kp;
  // Derivative gain
  double kd;
  // Integral gain
  double ki;
  double steeringConstraint;
  // Steering angle to be needed for motion
  double steeringAngle=0;
  // Speed of left wheel of the vehicle
  double leftWheelSpeed=0;
  // Speed of right wheel of the vehicle
  double rightWheelSpeed=0;
  double vehicleSpeed=0;
  double wheelCircumference;
  double trackWidth;


  //new variables
  // Threshold for PID controller
  double errorThreshold = 0.001;
  // Previous error for the controller
  double previousError = 0;
  // Sum of previous errors
  double previousErrorSum = 0;
  // Difference in time intervals
  double dTime = 0;

  /*
   * @brief Function to calculate error in orientation
   * and velocity
   */
  double calculateError(double initial, double desired) {
    double error = 0;
    return error;
  }

  /*
   * @brief Implement PID controller for the given values
   */
  double implementPID(){
    double output;
    return output;
  }

  /*
   * @brief Calculate steering angle to execute the turn
   */
  double calculateSteeringAngle(){
    double steeringAngle;
    return steeringAngle;
  }

  /*
   * @brief Calculate the wheel speed ratios for
   *        getting the different wheel speeds
   */
  double calculateWheelSpeedRatio();

  /*
   * @brief Returns the Left Wheel Speed
   */
  double getLeftWheelSpeed();
  /*
   * @brief Returns the Right Wheel Speed
   */
  double getRightWheelSpeed();

 public:
  /*
   * @brief Constructor for Controller class
   */
  Controller(double kp, double kd, double ki, double steeringConstraint,
		  double heelDiameter, double trackWidth, double wheelBase);

  /*
   * @brief Function to compute the final orientation and
   * velocities of the vehicle
   */
  double compute(){
    double output;
    return output;
  }

  /*
   *@brief Destructor for class Controller
   */
  ~Controller();
};

#endif //INLCUDE_CONTROLLER_HPP
