//Lab6
//3. Statistical Data from a File
//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
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

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);
bool parseLine(const char line[], int& id, int& grade);
bool doHistogramStuff(int histogram[], int grade);
//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

int histogram(const char filename[], int histogram[10],
    const int minAcceptableID, const int maxAcceptableID,
    int*& rejects)
{
    //errors
    // min > max
    if(minAcceptableID  > maxAcceptableID || histogram == NULL){
      return -1;
    }
    const int maxNumRejects=10;
    const int maxLineLength = 100;
    int numOfRejects=0;
    int id=0;
    int grade=0;
    char line[maxLineLength];

    std::ifstream infile;
    infile.open(filename);

    if (!infile.is_open()) {
        return -1;
    }
    rejects = new int[10];
    for (int i = 0; i < 10; i++) {
        histogram[i] = 0;
    }
    bool done = false;
    int fileLineNumber = 0;
    while (!done) { // Read from file
        ++fileLineNumber;
        grade=0;
        id=0;
        if (!infile.getline(line, maxLineLength)) { // Get next line
            if (infile.eof()) { // End of file
                done = true;
            }
            else { // Some error reading file
                return -1;
            }
        }
        if(!done){
        if(parseLine(line, id ,grade)){
          if(id >= minAcceptableID && id <= maxAcceptableID && grade >=0 && grade <=100){
        doHistogramStuff(histogram, grade);
      }else{
        //reject it id/grade bad
        rejects[numOfRejects] = fileLineNumber;
        numOfRejects++;
        
      }

      }else{
        //reject it parse failed
        rejects[numOfRejects] = fileLineNumber;
        numOfRejects++;
      }

      if(numOfRejects>10){
        return -1;
      }

    }
  }
  return numOfRejects;
}

bool parseLine(const char line[], int& id, int& grade){
  //things we need to do:
  //parse for id and grade
  enum States { START,WS1,ID,WS2,COMMA,GRADE,WS3,WS4}; 
  States state = START;
  for(int i=0;line[i]!=0;i++){
    char in = line[i];
    switch (state){
      case START:
        if(in == ' ' || in == '\t'){
          state = WS1;
        }else if(in >= '0' && in <= '9'){
          state = ID;
          id = id * 10 + (in - '0');
        }else{
          return false;
        }
      break;

      case WS1:
      if(in == ' ' || in == '\t'){
          state = WS1;
        }
        else if(in >= '0' && in <= '9'){
          state = ID;
          id = id * 10 + (in - '0');
        }else{
          return false;
        }
      break;

      case ID:
      if(in == ' ' || in == '\t'){
          state = WS2;
        }
        else if(in >= '0' && in <= '9'){
          state = ID;
          id = id * 10 + (in - '0');
        }
        else if(in==',')
        {
          state=COMMA;
        }

        else{
          return false;
        }
        break;

        case WS2:
        if(in == ' ' || in == '\t'){
          state = WS2;
        }
         else if(in==',')
        {
          state=COMMA;
        }
        else{
          return false;
        }
      break;

        case COMMA:
         if(in == ' ' || in == '\t'){
          state = WS3;
        }
        else if(in >= '0' && in <= '9'){
          state = GRADE;
          grade = grade * 10 + (in - '0');
        }else{
          return false;
        }
      break;

        case WS3:
        if(in == ' ' || in == '\t'){
          state = WS3;
        }
        else if(in >= '0' && in <= '9'){
          state = GRADE;
          grade = grade * 10 + (in - '0');
        }else{
          return false;
        }
      break;

        case GRADE:
        if(in == ' ' || in == '\t' || in == '\r' || in == '\n'){
          state = WS4;
        }
        else if(in >= '0' && in <= '9'){
          state = GRADE;
          grade = grade * 10 + (in - '0');
        }
        else if(in==0)
        {
          return true;
        }

        case WS4:
        if(in == ' ' || in == '\t' || in == '\r' || in == '\n'){
          state = WS4;
        }
        else if(in==0)
        {
          return true;
        }
    }
  }
  return true;
}

bool doHistogramStuff(int histogram[], int grade){
  //need to do
  // add grade to histo
  if(grade == 100){
    histogram[9]++;
  }else{
    histogram[grade/10]++;
  }
  return true;
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
  // int grade=0;
  // int id=0; 
  // char line[] = "     123     ,    -23     ";
  // if(parseLine(line,id,grade))
  // cout<<id << '\t' << grade<<endl;
 //  // Some test driver code here ....
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 0, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else {
    for (int i = 0; i < numBuckets; ++i)
      if (i != numBuckets-1)
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
      else
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
    if (retCode > 0) {
      cout << "Number of rejected records: " << retCode << endl;
      cout << "Rejected records are:";
      for (int i = 0; i < retCode; ++i)
	cout << " " << rejectedRecords[i];
      cout << endl;
      delete[] rejectedRecords;
    }
  }

  return 0;
}

#endif
