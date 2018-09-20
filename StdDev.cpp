#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <float.h>

using namespace std;
int main (const int argc, const char* const argv[])
{

	if (argc<2)
		{
			cerr<< "Error: Unable to compute statistics over data set because of insufficient arguments."<< endl;
			return -1;
		}

	int length = argc-1;
	float arr[length];
	float min = FLT_MAX;
	float max = -1 * FLT_MAX;

	int i;

	for(i=0; i<length; i++){
		arr[i]= atof(argv[i+1]);
	}
	for(i=0;i<length;i++){
		if (arr[i]>max){
			max=arr[i];
		}

		if (arr[i]<min){
			min=arr[i];
		}
	}

	float avg = 0.0;
	for(i=0;i<length;i++){
		avg+= arr[i];
	}
	avg = avg/length;

	for(i=0;i<length;i++){
		arr[i] = arr[i] - avg;
	}	

	for(i=0;i<length;i++){
		arr[i] = arr[i]*arr[i];
	}

	float sum = 0.0;
	for(i=0;i<length;i++){
		sum+= arr[i];
	}

	float temp1 = sum/length;

	float sigma = sqrt(temp1); // answer 1

	float temp2 = sum/(length - 1);

	float s = sqrt(temp2); // answer 2	

	cout << "Number of floating-point numbers: " << length << endl;
	cout << "Minimum floating-point number: " << min << endl;
	cout << "Average floating-point number: " << avg << endl;
	cout << "Maximum floating-point number: " << max << endl;
	cout << "Population standard deviation: " << sigma << endl;
	if(s == -1){
		cout << "Sample standard deviation: infinity";
	}
	else
		cout << "Sample standard deviation: " << s << endl;


	return 0;
}