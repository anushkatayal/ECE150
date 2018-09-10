#include <iostream>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

using namespace std;

int main(const int argc, const char*const argv[])
{
if (argc==1)
{
cerr << "Unable to compute statistics over data set because you did not enter any numerical argument" << endl;
return -1;
}

cout<<"Number of floating-point numbers: "<<argc-1<<endl;
int num=1;
float sum1=0;
float min= FLT_MAX;
float max= -FLT_MAX;

while (num<=(argc-1)){
float i=atof(argv[num]);
sum1+=i;

if (i<min){
min=i;	
}

if (i>max){
max=i;
}

num++;
}

cout<<"Minimum floating-point number: "<<min<<endl;
cout<<"Average floating-point number: "<<float(sum1/(argc-1))<<endl;
cout<<"Maximum floating-point number: "<<max<<endl;

return 0;
}

