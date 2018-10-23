//Lab0
//2.Welcome

#include <iostream>

using namespace std;

int main( const int argc, const char* const argv[])
{
    cout << "Welcome to UW Engineering, " << argv[1] << "." << endl;

    cout << "Your University of Waterloo E-mail address is: " << argv[2] << "@uwaterloo.ca" << endl;
     // add a line of code to output the second command-line argument (argv[2])

    cout << "The value stored in argc is " << argc << "." << endl;
    // add a line of code to output the content of argc


    cout << "The variable \"argc\" contains the length of argv." << endl;
    // add a line of code to explain what is stored in argc


    return 0;
}
