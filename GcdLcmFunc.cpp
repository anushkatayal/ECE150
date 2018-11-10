//Lab 4
//1. GCD and LCM as Functions
//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed to use them ...
//

#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b){
  if (a<=0 || b<=0){
		return -1;
	}

  int gcd=1;

  int x;

	if(a<b){
		x=a;
	}
	else{
		x=b;
	}

	int i;
	for(i=1;i<=x;i++){

		if((a%i==0) && (b%i==0)){
			gcd = i;
		}

	}
  return gcd;
}

int leastCommonMultiple(const int a, const int b){
  if (a<=0 || b<=0){
		return -1;
	}

  int gcd=greatestCommonDenominator(a,b);

  if (gcd == -1){
    return -1;
  }

  int lcm = ((a/gcd)*b);

  if(lcm> INT_MAX){
  return -2;
  }

  return lcm;
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

int main(const int argc, const char* const argv[]){

  if(argc<3){
    cerr<<"Error:Unable to compute data due to insufficient number of arguments."<<endl;
    return -1;
  }

  int gcd=greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));

  if(gcd<0){
    cerr<<"Error:Unable to compute GCD("<<argv[1]<<","<<argv[2]<<")"<<endl;
    return -1;
  }
  else{
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;
  }

  int lcm=leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  
  if(lcm<1){
    cerr<<"Error:Unable to compute lcd("<<argv[1]<<","<<argv[2]<<")"<<endl;
    return -1;
  }
  else{
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;
  }

  return 0;
}

#endif
