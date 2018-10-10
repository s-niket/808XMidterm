/**
 * @file Vehicle.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Vehicle class
 */

#ifndef INCLUDE_VEHICLE_HPP
#define INCLUDE_VEHICLE_HPP

#include <iostream>
#include "Controller.hpp"
/**
 * @brief Class Vehicle
 * Class defines vehicle attributes and
 * member functions to update vehicle's orientation
 * and velocity to a desired value 
 */

public class Vehicle{
 private:
  double wheelDiameter;
  double steeringAngleConstraint;
  double trackWidth;
  double currentVelocity;
  double desiredVelocity;
  double currentOrientation;
  double desiredOrientation;

 public:
  /*
   * @brief Constructor of class Vehicle
   */
  Vehicle(double wheelDiameter,double steeringAngleConstraint,
          double trackWidth);

  /*
   * @brief Method to udpate the orientation of the vehicle
   */
  double updateOrientation(){
    double _orientation;
    return _orientation;
  }

  /*
   *  @brief Method to update velocity of the vehicle
   */
  double updateVelocity(){
    double _velocity;
    return _velocity;
  }

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
};


#endif  // INCLUDE_VEHICLE_HPP_
