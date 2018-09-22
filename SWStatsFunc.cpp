//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <math.h>
#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  


int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn) {

	if (windowSize<0)
	{
	//cerr<< "Error: Data cannot be evaluated over given windowsize." <<endl;
	return -1; 
	}

	int i = currentSample;


	if(i < windowSize){
		
		SWMaximum(dataset,size,i,i+1,max);
		SWMinimum(dataset,size,i,i+1,min);
		SWAverage(dataset,size,i,i+1,avg);
		SWMedian(dataset,size,i,i+1,mdn);
		SWSmplStdDev(dataset,size,i,i+1,smplSD);
	}
	else{
		
		SWMaximum(dataset,size,i,windowSize,max);
		SWMinimum(dataset,size,i,windowSize,min);
		SWAverage(dataset,size,i,windowSize,avg);
		SWMedian(dataset,size,i,windowSize,mdn);
		SWSmplStdDev(dataset,size,i,windowSize,smplSD);

	}
	


	return 0;

}

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum) {

	int i;
	float min = dataset[currentSample];

	for(i = currentSample - windowSize + 1; i<=currentSample; i++)

		{
		if (dataset[i]<min)
		{
			min=dataset[i];

		}

	}
		
	minimum=min;

	return 0;

}

int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average) {

	float sum = 0;
  	int i;

  for(i = currentSample - windowSize + 1; i<=currentSample; i++)
  {
    sum += dataset[i];
  }

  average = sum/windowSize;

  return 0;
}

int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum) {

	int i;
	float max = dataset[currentSample];

	for(i = currentSample - windowSize + 1; i<=currentSample; i++)

		{
		if (dataset[i]>max)
		{
			max=dataset[i];

		}

	}
		
	maximum=max;

	return 0;
}

float myfunction(const float dataset[], const int size, float x_bar, int currentSample, int windowSize) 
{
  float temp;
  int l;
  float summation=0.0;

  for(l=0;l<currentSample+windowSize;l++)
  {
    temp= (dataset[l] - x_bar)*(dataset[l] - x_bar);
    summation += temp;

  }

  return summation;

}
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev) {
	float avg;
	SWAverage(dataset,size,currentSample,windowSize,avg);
  float summation3=myfunction(dataset,size,avg,currentSample,windowSize);
  float y;
  float s;


  y= summation3/(currentSample+windowSize-1);
  s=sqrt(y);
  smplStdDev=s;
  return s;
}

int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median) {
int m;
  int n ;
  int s = currentSample+windowSize;
  float a[currentSample+windowSize];
  for(m=0;m<currentSample+windowSize;m++)
  {
    a[m] = dataset[m];
  }

  for(m=0;m<currentSample+windowSize;m++)
  {
       float help;
    for(n=m+1;n<currentSample+windowSize;n++)
    {
      if(a[m]>a[n])
      {

         help = a[m];
         a[m] = a[n];
         a[n] = help;


      }
    }

  }
   median=0 ;
    int b = s/2;
    int d = (s+1)/2;
    if(size%2==0)
    {
      median = a[b-1] + a[b + 1];
    }
    if(!(s%2==0))
    {
      median = a[d-1];
    }
return(median);

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

int main(const int argc, const char* const argv[]) {
  int size = 5;
  float dataset[] = {1, 2, 3, 4, 5};
  int windowSize = 3;
  int currentSample = 0;
  float min;
  float avg;
  float max;
  float smplSD;
  float median;

  cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
    	//cout << currentSample << "\t " << min << "\t " << max << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }
    ++currentSample;
  }
  return 0;
}

#endif
