#include <iostream>
#include "Vehicle.hpp"
#include "Controller.hpp"

int main()
{
    double steeringAngleConstraint = 45;
    double wheelDiameter = 2;
    double trackWidth = 4;
    double wheelBase = 4;
    double desiredOrientation = 90;
    double desiredVelocity=10;
    //Vehicle tricycle(wheelDiameter,steeringAngleConstraint,trackWidth,wheelBase);
    Controller pid(.1,.1,.1,steeringAngleConstraint,wheelDiameter,trackWidth,wheelBase);

/*
    while(abs(tricycle.getOrientation()-desiredOrientation)>1&&abs(tricycle.getVelocity()-desiredVelocity)>.5){
		pid.compute(tricycle.getOrientation(),desiredOrientation,tricycle.getVelocity(),desiredVelocity);
		tricycle.updateOrientation(pid.getTurningRadius(),pid.getSteeringAngle());
		tricycle.updateVelocity(pid.getLeftWheelSpeed(),pid.getRightWheelSpeed());
		std::cout<<tricycle.getVelocity()<<"\n|";
    }

*/



	return 0;

}
