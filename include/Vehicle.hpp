/**
 * @file Vehicle.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Header for Vehicle class
 */

#ifndef INCLUDE_VEHICLE_HPP_
#define INCLUDE_VEHICLE_HPP_

#include <iostream>
#include "Controller.hpp"
/**
 * @brief Class Vehicle
 * Class defines vehicle attributes and
 * member functions to update vehicle's orientation
 * and velocity to a desired value
 */

class Vehicle {
 private:
  double wheelDiameter;/*!<diameter of the wheels  */
  double dTime = 0.05;/*!< Time step for controller inputs */
  double steeringAngleConstraint;/*!< For restricting the motion of steering */
  double trackWidth;/*!<The distance between the two back wheels  */
  double wheelBase;/*!<The length between the front and the back wheels  */
  double currentVelocity = 1;/*!<The current velocity of the vehicle  */
  double desiredVelocity;/*!<The desired velocity of the vehicle  */
  double currentOrientation = 0;/*!<dThe current orientation of the vehicle  */
  double desiredOrientation;/*!<The desired orientation of the vehicle  */
  Controller pid;/*!<Instance of the controller class  */



 public:
  /*
   * @brief Constructor of class Vehicle
   */
  Vehicle(double wheelDiameter, double steeringAngleConstraint,
          double trackWidth, double wheelBase);

  double setOrientation(double desiredOrient);
  double setVelocity(double desiredVelo);



  /*
   * @brief Method to update the orientation of the vehicle
   */
  double updateOrientation();

  /*
   * @brief Method to update velocity of the vehicle
   */
  double updateVelocity();

  /*
   * @brief Method to calculate a controller output and update the vehicle
   */
  double update();

  /*
   * @brief Method to return the orientation of the vehicle
   */
  double getOrientation();

  /*
   * @brief Method to return the velocity of the vehicle
   */
  double getVelocity();

  /*
   * @brief Destructor for class Vehicle
   */
  ~Vehicle();

  // New method for GMock Testing

  /*
   * @brief Get controller gains of the vehicle
   * @param double kp
   * @return double kP
   */
  double getControllerGain(double kp);
};


#endif  // INCLUDE_VEHICLE_HPP_
