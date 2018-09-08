#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main (const int argc, const char* const argv[]){

	int N;
	int S;

	N = atoi(argv[1]);
	S = atoi(argv[2]);

cout << "N: " << argv[1] << endl;
cout << "S: " << argv[2] << endl;

cout << "Left-shift of N by S bits is: "<< (N << S) << endl;
cout << "Right-shift of N by S bits is: " << (N >> S) << endl;
cout << "The equivalent math operation of left-shift N by S bits is: " << "N times two to the power of S"  << endl;
cout << "And the result of that operation is: " << N*(pow(2,S)) << endl;
cout << "The equivalent math operation of right-shift N by S bits is: " << "N divided by two to the power of S" << endl;
cout << "And the result of that operation is: "<< N/(pow(2,S)) << endl;
}

