/**
 * @file Controller.hpp
 * @author Niket Shah
 * @copyright 2018 Niket Shah
 * @brief Header for Controller class
 */

#ifndef INCLUDE_CONTROLLER_HPP
#define INCLUDE_CONTROLLER_HPP

/**
 * @brief Class Controller
 * Class defines controller attributes and
 * member functions to calculate error and 
 * get the contoller output for orientation
 * and velocity 
 */

public class Controller{
 private:
  double kp;
  double kd;
  double ki;
  double steeringConstraint;
  double steeringAngle;
  double leftWheelSpeed;
  double rightWheelSpeed;
  double vehicleSpeed;
  double WheelDiameter;
  double steeringAngle;
  double trackWidth;
  

  double calculateErrorOrientation(double initialOrientation,double desiredOrientation){  
  
  }
  
  double calculateErrorVelocity(double initialVelocity,double desiredVelocity){   
  
  }
  
  double implementPID(){
  
  }
  
  double calculateSteeringAngle(){
    
  }
  
  double calculateWheelSpeedRatio(){
    
  }
  
 public:
  Controller(double kp,double kd,double ki,double vehicleSpeed);
  
  double compute(){
    
  }
    
  ~Controller();
};

#endif //INLCUDE_CONTROLLER_HPP