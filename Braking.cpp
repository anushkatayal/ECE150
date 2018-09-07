#include <iostream>
#include <stdlib.h>
using namespace std;

int main (const int argc, const char* const argv[])
{
	float velocity ;
	float distance ;
	velocity = atof(argv[1]);
	distance = atof(argv[2]);

	float a; //acceleration

	a = -((velocity * velocity) / (2*distance));	//calculating deceleration using kinematics equation

	cout<< "Initial car velocity: " << velocity << " m/s" << endl;
	cout<< "Distance to obstacle: " << distance << " m" << endl;
	cout<< "Minimum deceleration: " << a << " m/s/s" << endl;

	float t;
	t = -(velocity/a); //calculating time using kinematics equation

	cout<< "Maximum stopping time: " << t << " s" << endl;

	return 0;
}