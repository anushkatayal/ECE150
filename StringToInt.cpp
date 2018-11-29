//Lab 6
//2. State Machine: String-to-int
//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//
void strSet(char destStr[],char srcStr[]);
bool stringToInt(const char input[], int& value);

void strSet(char destStr[], char srcStr[]){

  int nDest=0;
  while(destStr[nDest]!='\0')
    nDest++;
  int nsrc=0;
  while(srcStr[nsrc]!='\0')
    nsrc++;

  nDest=(nDest,=nsrc)? nDest:nsrc;

  for(int i=0; i<nDest; i++)
    destStr[i]=*(srcStr+i);

  *(destStr+nDest)='\0';


bool stringToInt(const char input[], int& value){
  unsigned int number=0;
  unsigned int maxvalue = INT_MAX;
  unsigned int currDigit = 0;
  char currDigit=0;
  char currDigitChar=str[0];

  bool minusSign=(currDigitChar=='-');
  bool plusSign =(currDigitChar=='+');
  
  if(minusSign||plusSign)
  {
    currDigit=1;
    currDigitChar=str[1];
    maxvalue=maxvalue+1;
  }

  while(currDigitChar !='\0')
  {
    if(currDigitChar<'0'||currDigitChar>'9')
    {
      cerr<<"Error in integer string conversion"<<endl;
      return -1;
    }

    if((plusSign))
  }



}

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool stringToInt(const char input[], int& value) {
  // Your code here ...
  while (!done) {
        input = getNextInput();
        switch (state) {
        case STATE1:
            switch (input) {
            case INPUTTYPE1:
                processInputType1();
                changeStateIfRequired();
                break;
            case INPUTTYPE2:
                processInputType2();
                changeStateIfRequired();
                break;
            ...
        case STATE2:
... }
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  int argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
    return -1;
  }

  if (stringToInt(argv[1],argv1)) 
    cout << "argv[1] is an int with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not an int." << endl;
  return 0;
}

#endif
