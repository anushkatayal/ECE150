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

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool statistics(const float dataset[], const int size,
	   float& min, float& avg, float& max,
	   float& popSD, float& smplSD, float& mdn) {
  
}

float minimum(const float dataset[], const int size) 
{
    int min = dataset[0];

  for(int i=0; i<size; i++)
  {
    if (dataset[i]<min)
    {
      min=dataset[i];
    }


  }

  return min;
}

float average(const float dataset[], const int size) 
{
  float sum;
  int k;

  sum= dataset[0];

  for(k=1;k<size;k++)
  {
    sum += dataset[k];
  }

  int avg;
  avg=sum/size;

  return avg;
}

float myfunction(const float dataset[], const int size) 
{
  float x_bar=average(dataset,size);
  float temp;
  int l;
  float summation=0.0;

  for(l=0;l<size;l++)
  {
    temp= (dataset[l] - x_bar)*(dataset[l] - x_bar);
    summation += temp;

  }

  return summation;

}

float maximum(const float dataset[], const int size) 
{
  int max = dataset[0];
  
  for (int j=0;j<size;j++)
  {
    if (dataset[j]>max)
    {
      max=dataset[j];
    }

  }

  return max;
}

float popStdDev(const float dataset[], const int size) 
{
  float x;
  float summation2=myfunction(dataset,size);
  float sigma;

  x= summation2/size;
  sigma=sqrt(x);

  return sigma;
}

float smplStdDev(const float dataset[], const int size) 
{

  float summation3=myfunction(dataset,size);
  float y;
  float s;


  y= summation3/size-1;
  s=sqrt(y);

  return s;
}

float median(const float dataset[], const int size) 
{
  int m;
  float median=0;
  int mid=0;
  float array[size];
  
    for(m=0;m<size;m++)
    {
    array[m]=dataset[m];
    }
    
    for (m=0;m<size; m++)
    {
      for(int n=m+1;n<size;n++)
        {
          if (array[m]>array[n]) 
          {
              float temp=0;
              temp=array[m];
              array[m]=array[n];
              array[m]=temp;
          }
        }
    }
    
    if (size%2==0)
    {
        mid=size/2;
        median=((array[mid]+array[mid-1])/2);
    }
    
    else
    {
      mid=(size+1)/2;
    median=array[mid-1];
  }
    
    return median;
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
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
