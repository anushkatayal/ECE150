//Lab2
//1. Error Checking The Braking System

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[])
{

  // declaring variables
  float u; // initial velocity
  float s; // stopping distance
  float a_max; // maximum deceleration

  // part A - If number of arguments is less than 3 (array length 4), then the command is invalid.
  if (argc<4){
    // throw error
    cerr << "Insufficient number of command line arguments. Please provide exactly three arguments - velocity of the self-driving car, distance to obstacle and maximum acceptable rate of deceleration." << endl;
    return -1;
  }

  else{
    // setting variables
    u = atof(argv[1]);
    s = atof(argv[2]);
    a_max = atof(argv[3]);
  }

  // part B, C - No collison will occur if the car is already at rest or moving in opposite direction

  if (u == 0){
    cout << "There is no possibility of collision because the car is not moving." << endl;
  }

  else if ((u*s)<0){
    cout <<"There is no possibility of collision because the car is moving in the opposite direction from the obstacle."<<endl;
  }

  // part D.1 - output the required deceleration rate and maximum stopping time

  else{

    float a;
    a =  ((u * u) / (2 * s));

    if (a <= a_max){
      cout << "Initial car velocity: " << u << " m/s" << endl;
      cout << "Distance to obstacle: " << s << " m" << endl;
      cout << "Minimum deceleration: " << a << " m/s/s" << endl;
      float t;
      t = u/a;
      cout << "Maximum stopping time: " << t << " s" << endl;
    }

    else{
    // part D.2

    float crash_v;  //final velocity at the time of crash
    float crash_t;  // time to crash
    crash_v = abs(sqrt((u*u) - (2*a_max*s)));
    crash_t = abs((crash_v - u) / a);
    cout<< "Crash will occur in "<< crash_t << " seconds at velocity " << crash_v << " m/s; deploying airbags." << endl;
    }
  }

  return 0;

}
