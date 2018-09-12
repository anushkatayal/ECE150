 #include <iostream>
#include <stdlib.h>
#include <float.h>

using namespace std;

int main (const int argc, const char* const argv[])
{ 	
if (argc==1)
{cerr<< "Unable to compute statistics over data set because argument entered was out of range"<<endl;
return -1;
}

cout<< "Sample   Value   Minimum   Average   Maximum" << endl;

int i =1;
float sum = 0;
float min = FLT_MAX;
float max = -1 * FLT_MAX;
float avg=0;

while (i <= argc-1)
{
float x = atof (argv[i]);
sum+=x;
avg=(sum/i);

if (x>max){
max=x;
}

if (x<min){
min=x;
}


cout<<i<<"         "<<x<<"     "<<min<<"    "<<avg<<"    "<<max<<endl;
i++;
}



return 0;
}

