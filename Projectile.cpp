//Lab6
//1. Projectile Destination
//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <cmath>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
  // Your code here ...

    if(h<0||v<0)
    {
      return false;
    }

    else if(m<=0)
    {
      return false;
    }

    else if(b<0)
    {
      return false;
    }

    else if(d<0 || w<0)
    {
      return false;
    }

    float angle;
    angle=(theta*3.141592)/180;

    float x= v*(sin(angle));
    float y= v*(cos(angle));

    float g=9.8;

    /*float time=0;
    time=(2*v*sin(angle))/g;*/

    float R=0;
    R=((y/g)*(x+sqrt(pow(x,2)+2*g*h)));
    //R= (v*cos(angle))*time;
    //R=(pow(v,2)*sin(2*theta))/g;
    //R= sqrt((((2*pow(v,2)))/g)*(h+(pow(v,2))/2*g));
    if(theta == 90){
      destX=0;
      destY=h;
      return true;
    }

   if (theta>90){
    destY=0;
    destX=((x/g)*(y+pow(((y*y)+(19.6*h)),0.5)));
    return true;
  }

    if (v==0)
    {
      destX=0;
      destY=h;

      return true;
    }

    if(R>0)
    {

      if (R<b)

      {
        destX=R;
        destY=0;
      }

      else if (R==b)
      {
        destX=b;
        destY=0;

      }

      else if (R==b+w)
      {
        destX=R;
        destY=0;

      }

      else if(R>b && R<(b+w))
      {
        destX=R;
        destY=t;

      }

      else if(R>(b+w))
      {
        destX=R;
        destY=0;
      }

    return true;

    }


    else {
      return false;
    }

  }

//////////////////////////////////////////////////////////////
//
// Test Driver

//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....
  //-56.2701
  float h = 50;
  float v = 18.4;
  float m = 1;
  float theta = 127.61;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 20;
  float b = 30;
  float w = 20;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
