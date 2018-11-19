//Lab5
//3.Sorted
//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// #defines, enum, and function declarations; do not remove
//

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#define NaN std::numeric_limits<float>::quiet_NaN() // (comes from <limits>)

enum sortType { ASCENDING, DESCENDING, UNKNOWN, UNSORTED };

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort);
bool sorted(const float data[]);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
//

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort) {

  if(data[currentDataItem]!=data[currentDataItem])
  {
  	return true;
  }

  switch (typeOfSort)
  {

  	case UNSORTED:
  		return false;

  	case UNKNOWN:
  	while (currentDataItem==0)
  	{

  	if(data[currentDataItem]<data[currentDataItem+1])
  		return isSorted(data,currentDataItem+1,ASCENDING);
  	if(data[currentDataItem]>data[currentDataItem+1])
  		return isSorted(data,currentDataItem+1,DESCENDING);
  	if(data[currentDataItem]==data[currentDataItem+1])
  		return isSorted(data,currentDataItem+1,UNSORTED);
  	else
  		return isSorted(data,currentDataItem+1,UNKNOWN);

  	}


  	case ASCENDING:
  	if (data[currentDataItem]<=data[currentDataItem+1])
  		return isSorted(data,currentDataItem+1,ASCENDING);
  	else
  		return isSorted(data,currentDataItem+1,UNSORTED);


  	case DESCENDING:
  	if (data[currentDataItem]>=data[currentDataItem+1])
  		return isSorted(data,currentDataItem+1,DESCENDING);
  	else
  		return isSorted(data,currentDataItem+1,UNSORTED);






  }

}

bool sorted(const float data[]) {
  if (data[0]==NaN)
  {
  	return false;
  }
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

  // Some test driver code here ....
  float data[] = {1, 2, 4, 5, 9, NaN};

  if (sorted(data))
    cout << "Data is sorted" << endl;
  else
    cout << "Data is not sorted" << endl;

  return 0;
}

#endif
