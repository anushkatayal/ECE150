//Lab2
//4. Smoothing Statistics

#include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main (const int argc, const char* const argv[])
{
	if (argc<4)
	{
		cerr<< "Error: Unable to compute statistics over data det due to insufficient number of arguments"<<endl;
		return -1;
	}


	int i =1;
	int j=3;
	float sum = 0;
	float min = FLT_MAX;
	float max = -1 * FLT_MAX;
	float emw= atof(argv[3]);
	float limit=atof(argv[2]);
	float maxc=0;
	float minc=0;

	if (limit<1)
	{
		cerr<<"Error: Limit is invalid"<<endl;
		return -1;
	}

	else
	{
		cout<< "Sample   Value   Minimum   EWMA   Maximum" << endl;

	}

	if ((atof(argv[1])<=0)|| (atof(argv[1])>1))
	{
		cerr<<"Error: Weight cannot be less zero or greater than 1"<<endl;
		return -1;
	}

	while (i <= argc - 3){
		float x = atof (argv[j]);
		emw= ((atof(argv[1])*x) + ((1-atof(argv[1]))*emw));

		if (maxc>limit){
			maxc=1;
			max=x;
		}

		if (x>=max){
			maxc=1;
			max=x;
		}


		if (minc>limit){
			minc=1;
			min=FLT_MAX;

		}

		if(x<=min){
			minc=1;
			min=x;
		}



		cout<<i<<"         "<<x<<"     "<<min<<"    "<<emw<<"    "<<max<<endl;
		maxc++;
		minc++;
		i++;
		j++;
	}
	
	return 0;
}
