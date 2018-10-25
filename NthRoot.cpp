//Lab3
//2.Square-Root

#include <iostream>
#include <stdlib.h>

using namespace std;
float power(float number, int pow);
float abs(float number);

int main (const int argc, const char* const argv[])
{
	if(argc < 4){
		cerr<< "Error: Unable to compute Nth root because insufficient amount of arguments" << endl;
		return -1;
	}

	if(argc > 4){
		cerr<<"Warning: Expecting four command line arguments; received"<< argc-1<< "; ignoring extraneous arguments."<< endl;
	}

	float a = atof(argv[1]);
	int root = atoi(argv[2]);

	//float result = a / root;

	float accuracy = 1;
	float precision = atof(argv[3]);
	float currentguess=a/2;

	if (root!=2){
		cerr <<"Error: Unable to compute Nth root because input is invalid." <<endl;
		return -1;
	}

	if (a<0){
		cerr <<"Error: Unable to compute Nth root because input is invalid." <<endl;
		return -1;
	}

	if (precision<0 || precision>1){
		cerr <<"Error: Unable to compute Nth root because input is invalid." <<endl;
		return -1;
	}
	/*if (a == 0){
	result = 0;
	}*/


		else{

			while(accuracy > precision){
					currentguess= (currentguess+(a/currentguess))/2;

				//float case1 = ((float)(root - 1) / (float)(root)) * result;
				//float case2 = a / ((float)(root) * (power(result, root - 1)));

				//result = case1 + case2;
				//cout << accuracy << endl;

				accuracy = (a - currentguess*currentguess)/a ;
				accuracy = abs(accuracy);
			}
		}

		cout << "Root (" << a << ", " << root << ") = " << currentguess << "\n(with precision " << abs(accuracy) << ")" << endl;

		return 0;
	}

	float power(float a, int pow){

		if(pow == 0)
		return 1;

		else{
			float result2 = 1;

			while (pow > 0){
				result2 *= a;
				pow--;
			}

		 return result2;
		}
	}

	float abs(float a){
		if(a < 0)
		a *= -1;

		return a;
	}
