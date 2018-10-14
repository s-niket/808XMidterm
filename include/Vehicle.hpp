/**
 * @file Vehicle.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah Zachary Zimits
 * @brief Header for Vehicle class
 */

#ifndef INCLUDE_VEHICLE_HPP
#define INCLUDE_VEHICLE_HPP

#include <iostream>
#include <Controller.hpp>
/**
 * @brief Class Vehicle
 * Class defines vehicle attributes and
 * member functions to update vehicle's orientation
 * and velocity to a desired value
 */

class Vehicle {
 private:
  // diameter of the wheels
  double wheelDiameter;
  // Time step for controller inputs
  double dTime = 0.05;
  // The steering angle constraint restricting the motion
  double steeringAngleConstraint;
  // The distance between the two back wheels
  double trackWidth;
  // The length between the front and the back wheels
  double wheelBase;
  // The current velocity of the vehicle
  double currentVelocity;
  // The desired velocity of the vehicle
  double desiredVelocity;
  // The current orientation of the vehicle
  double currentOrientation;
  // The desired orientation of the vehicle
  double desiredOrientation;
  Controller orientControl(0.1,0.1,0.1,45,2,4,6);

 public:
  /*
   * @brief Constructor of class Vehicle
   */
  Vehicle(double wheelDiameter,double steeringAngleConstraint,
          double trackWidth);

  /*
   * @brief Method to update the orientation of the vehicle
   */
  double updateOrientation();

  /*
   * @brief Method to update velocity of the vehicle
   */
  double updateVelocity();

  /*
   * @brief Destructor for class Vehicle
   */
  ~Vehicle();
};



#endif //INLCUDE_VEHICLE_HPP
