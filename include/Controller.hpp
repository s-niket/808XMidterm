/**
 * @file Controller.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Controller class
 */

#ifndef INCLUDE_CONTROLLER_HPP
#define INCLUDE_CONTROLLER_HPP


#include <iostream>

/**
 * @brief Class Controller
 * Class defines controller attributes and
 * member functions to calculate error and
 * get the contoller output for orientation
 * and velocity
 */

class Controller {
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
  //Turning Radius
  double turningRadius=0;
  // Speed of left wheel of the vehicle
  double leftWheelSpeed=0;
  // Speed of right wheel of the vehicle
  double rightWheelSpeed=0;
  // Speed of the entire vehicle
  double vehicleSpeed=0;
  // Circumference of the wheels
  double wheelCircumference;
  // Distance between the two rear wheels
  double trackWidth;
<<<<<<< HEAD
  // Distance between the front and rear wheels
  double wheelBase;
  double acceleration=1.1;

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
  double calculateError(double initial, double desired);

  /*
   * @brief Implement PID controller for the given values
   */
  double implementPID();

  /*
   * @brief Calculate steering angle to execute the turn
   */
  double calculateSteeringAngle(double currentOrientation, double desiredOrientation);


  /*
   * @brief Calculate the total vehicle velocity
   */
  double calculateVehicleSpeed(double currentVelocity, double desiredVelocity);



  /*
   * @brief Calculate the wheel speed ratios for
   *        getting the different wheel speeds
   */
  double calculateWheelSpeedRatio();

 public:
  /*
     * @brief Returns the vehicle Speed
     */
    double getVehicleSpeed();

  /*
   * @brief Returns the Left Wheel Speed
   */
  double getLeftWheelSpeed();
  /*
   * @brief Returns the Right Wheel Speed
   */
  double getRightWheelSpeed();
  /*
   * @brief Returns the Turning Radius
   */
  double getTurningRadius();

  double getSteeringAngle();

  /*
   * @brief Constructor for Controller class
   */
  Controller(double kp, double kd, double ki, double steeringConstraint,
<<<<<<< HEAD
             double wheelDiameter, double trackWidth, double wheelBase);
=======
		  double wheelDiameter, double trackWidth, double wheelBase);
>>>>>>> c609bb0e214a7ebe025aa39ef78bf6422cce3631

  /*
   * @brief Function to compute the final orientation and
   * velocities of the vehicle
   */
  double compute(double currentOrientation,double desiredOrientation, double currentVelocity, double desiredVelocity);

  /*
   *@brief Destructor for class Controller
   */
  ~Controller();
};


#endif //INLCUDE_CONTROLLER_HPP
