#include <iostream>
#include <stdlib.h>

using namespace std;

int greatestCommonDenominator(const int a, const int b)
{ 
	if (a<=0 || b<=0)
	{
		return -1;
	}
	

	int gcd = 1;
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

int leastCommonMultiple(const int a, const int b)
{	
	if (a<=0 || b<=0)
	{
		return -1;
	}

	int gcd = greatestCommonDenominator(a,b);
	int lcm = 0;
	lcm = ((a/gcd)*b);

	return lcm;
}
