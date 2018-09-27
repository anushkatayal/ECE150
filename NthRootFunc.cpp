//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

float power(float x, const int N)
{
  float a= 1;
  int i;
  for(i=1;i<=N;i++)
  {
    a = a*x; 

  }

  return a;
}

float absolute1(float j)
{

  if(j<0)
  {
    j= -j;
  }
  return j;
}



//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

float NthRoot(const float S, const int N, const float precision) 
{

  if ((S<0 && N%2==0) || N<=1 || precision<=0.0)
    return std::numeric_limits<float>::quiet_NaN();

    float xi = 1;
    int counter = 1;
    float num = float (N);
    float current = power(1500,2);

  while(current>=precision && counter<9000000)
 {
    xi = ((num-1)/num)*xi + S/(num*(power(xi,num-1)));
    current = absolute1((S - power(xi,num)));
    counter++;
 }

return(xi);

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

int main(const int argc, const char* const argv[]) 
{
  
  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl; 

  return 0;
}

#endif