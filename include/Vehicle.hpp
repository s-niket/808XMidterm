/**
 * @file Vehicle.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Vehicle class
 */

#ifndef INCLUDE_VEHICLE_HPP
#define INCLUDE_VEHICLE_HPP

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
  
  Vehicle(double wheelDiameter,double steerinAngleConstraint,
          double trackWidth);
  
  double updateOrientation(){
  }
  
  double updateVelocity(){
  }
  
  ~Vehicle();
};



#endif //INLCUDE_VEHICLE_HPP