#include <iostream>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
using namespace std;

int main( const int argc, const char* const argv[]) 
{	
	int x;
	unsigned int y;

	x = atoi(argv[1]); //converting char to int
	y = x;

	cout << "The value of x is " << x << " ." << endl; 	//output value of x
	cout << "The value of y is " << y << " ." << endl;	//output value of y
	cout << "The most significant bit of x is " << (x >> (8 * sizeof(x)-1)) << " ." << endl; //bit-shift for most significant bit
	cout << "The most significant bit of y is " << (y >> (8 * sizeof(y)-1)) << " ." << endl;  

	//int
	int i; 
	cout<< "Type: \"int\"; " << "Size: " << sizeof(i) << " bytes; " << "Minimum value: " << INT_MIN <<" ; Maximum value: " << INT_MAX << endl;

	//short int
	short int j; 
	cout<< "Type: \"short int\"; " << "Size: " << sizeof(j) << " bytes; " << "Minimum value: " << SHRT_MIN <<" ; Maximum value: " << SHRT_MAX << endl;

	//long int
	long int k; 
	cout<< "Type: \"long int\"; " << "Size: " << sizeof(k) << " bytes; " << "Minimum value: " << LONG_MIN <<" ; Maximum value: " << LONG_MAX << endl;

	//long long int
	long long int l; 
	cout<< "Type: \"long long int\"; " << "Size: " << sizeof(l) << " bytes; " << "Minimum value: " << LLONG_MIN <<" ; Maximum value: " << LLONG_MAX << endl;

	//unsigned short int
	unsigned short int m; 
	cout<< "Type: \"unsigned short int\"; " << "Size: " << sizeof(m) << " bytes; " << "Minimum value: " << "0" <<" ; Maximum value: " << USHRT_MAX << endl;

	//unsigned int
	unsigned int n; 
	cout<< "Type: \"unsigned int\"; " << "Size: " << sizeof(n) << " bytes; " << "Minimum value: " << "0" <<" ; Maximum value: " << UINT_MAX << endl;

	//unsigned long int
	unsigned long int o; 
	cout<< "Type: \"unsigned long int\"; " << "Size: " << sizeof(o) << " bytes; " << "Minimum value: " << "0" <<" ; Maximum value: " << ULONG_MAX << endl;

	//unsigned long long int
	unsigned long long int p; 
	cout<< "Type: \"unsigned long long int\"; " << "Size: " << sizeof(p) << " bytes; " << "Minimum value: " << "0" <<" ; Maximum value: " << ULLONG_MAX << endl;

	//float
	float q; 
	cout<< "Type: \"float\"; " << "Size: " << sizeof(q) << " bytes; " << "Minimum value: " << FLT_MIN  <<" ; Maximum value: " << FLT_MAX << endl;

	//double
	double r; 
	cout<< "Type: \"double\"; " << "Size: " << sizeof(r) << " bytes; " << "Minimum value: " << DBL_MIN  <<" ; Maximum value: " << DBL_MAX  << endl;

	//long double
	long double s; 
	cout<< "Type: \"long double\"; " << "Size: " << sizeof(s) << " bytes; " << "Minimum value: " << LDBL_MIN <<" ; Maximum value: " << LDBL_MAX << endl;

	//signed char
	signed char t; 
	cout<< "Type: \"signed char\"; " << "Size: " << sizeof(t) << " bytes; " << "Minimum value: " << SCHAR_MIN <<" ; Maximum value: " << SCHAR_MAX << endl;

	//unsigned char
	unsigned char u; 
	cout<< "Type: \"unsigned char\"; " << "Size: " << sizeof(u) << " bytes; " << "Minimum value: " << "0" <<" ; Maximum value: " << UCHAR_MAX << endl;

	return 0;
}
