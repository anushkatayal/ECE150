#include <iostream>
#include <stdlib.h>

using namespace std;
int main (const int argc, const char* const argv[])
{
	if(argc < 3)
	{
		cerr<< "Error: Unable to compute GCD and/or LCM because of insufficient arguments." << endl;
		return -1;
	}

	if(argc > 3)
	{
		cerr<<"Warning: Expecting two command line arguments; received "<< argc-1<< "; ignoring extraneous arguments."<< endl;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	if (a <=0 || b <= 0)
	{
		cerr <<"Error: Unable to compute GCD and/or LCM because of invalid input." <<endl;
		return -1;
	}

	int gcd = 1;
	int lcm = 0;

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
	cout<<2147483647%2147483647<<endl;
//a/gcd*b/gcd

	lcm = ((a/gcd)*b);

	cout << "GCD(" << a << ", "<< b << ") = "<< gcd << endl;
	cout << "LCM(" << a << ", "<< b << ") = "<< lcm << endl;

	return 0;
}