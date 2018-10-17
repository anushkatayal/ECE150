#include <iostream>
using namespace std;

enum DayType { SUN, MON, TUE, WED, THU, FRI, SAT };

int main()
{
  DayType Oct26 = THU;
  DayType Oct27 = (DayType) ( (int)Oct26 + 1 );
  cout << "Size of a DayType variable is " << sizeof(DayType) << endl;
  cout << "The value of Oct26 is " << Oct26 << endl;
  cout << "Oct 27 "<< Oct27 <<endl;
  return 0;

}
