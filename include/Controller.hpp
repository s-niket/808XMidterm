/**
 * @file Controller.hpp
 * @author Niket Shah Zachary Zimits
 * @copyright 2018 Niket Shah
 * @brief Header for Controller class
 */

#ifndef INCLUDE_CONTROLLER_HPP_
#define INCLUDE_CONTROLLER_HPP_


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
  double steeringConstraint;/*!<maximum value for steering angle  */
  //
  double steeringAngle = 0;/*!<Steering angle to be needed for motion  */
  //
  double turningRadius = 0;/*!<Turning Radius  */
  //
  double leftWheelSpeed = 0;/*!<Speed of left wheel of the vehicle  */
  //
  double rightWheelSpeed = 0;/*!<Speed of right wheel of the vehicle  */
  //
  double vehicleSpeed = 0;/*!<Speed of the entire vehicle  */
  //
  double wheelCircumference;/*!<Circumference of the wheels  */
  //
  double trackWidth;/*!<Distance between the two rear wheels  */
  //
  double wheelBase;/*!<Distance between the front and rear wheels  */
  double acceleration = 1.1;/*!<value to increment the velocity  */

  // new variables
  // Threshold for PID controller
  double errorThreshold = 0.001;
  // Previous error for the controller
  double previousError = 0;
  // Sum of previous errors
  double previousErrorSum = 0;
  // Difference in time intervals
  double dTime = 0;

  // New attributes for GMock Testing
  // Proportional Gain
  double kp;

 public:
  /*
   * @brief Calculate steering angle to execute the turn
   */
  double calculateSteeringAngle(double currentOrientation,
                                double desiredOrientation);


  /*
   * @brief Calculate the total vehicle velocity
   */
  double calculateVehicleSpeed(double currentVelocity, double desiredVelocity);



  /*
   * @brief Calculate the wheel speed ratios for
   *        getting the different wheel speeds
   */
  double calculateWheelSpeedRatio();

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
  /*
   * @brief Returns the steering angle
   */
  double getSteeringAngle();

  /*
   * @brief Constructor for Controller class
   */
  Controller(double steeringConstraint,
             double wheelDiameter, double trackWidth, double wheelBase);

  /*
   * @brief Function to compute the final orientation and
   * velocities of the vehicle
   */
  double compute(double currentOrientation, double desiredOrientation,
                 double currentVelocity, double desiredVelocity);

  /*
   *@brief Destructor for class Controller
   */
  ~Controller();

  // New methods for GMock Testing

  /*
   * @brief Set proportional gain for the PID controller
   * @param double _kp
   * @return void
   */
  void setPgain(double _kp);

  /*
   * @brief Get proportional gain of the PID controller
   * @param none
   * @return double kp
   */

  double getPgain();
};

#endif  // INCLUDE_CONTROLLER_HPP_
