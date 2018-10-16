#include <iostream>
#include <math.h>
#include "Vehicle.hpp"
#include "Controller.hpp"

int main()
{
    double delta=10;
	double steeringAngleConstraint = 45;
    double wheelDiameter = 2;
    double trackWidth = 4;
    double wheelBase = 4;
    double desiredOrientation = 270;
    double desiredVelocity=10;
    Vehicle tricycle(wheelDiameter,steeringAngleConstraint,trackWidth,wheelBase);
    tricycle.setVelocity(desiredVelocity);
    tricycle.setOrientation(desiredOrientation);
    Controller pid(.1,.1,.1,steeringAngleConstraint,wheelDiameter,trackWidth,wheelBase);

    while(delta>.1||fabs(tricycle.getVelocity()-desiredVelocity)>.5){
		pid.compute(tricycle.getOrientation(),desiredOrientation,tricycle.getVelocity(),desiredVelocity);
		tricycle.updateOrientation(pid.getTurningRadius(),pid.getSteeringAngle());
		tricycle.updateVelocity(pid.getVehicleSpeed());
		delta = fabs(tricycle.getOrientation()-desiredOrientation);
    }

std::cout<<tricycle.getOrientation()<<" "<<tricycle.getVelocity();


	return 0;

}
