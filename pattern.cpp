#include <iostream>
#include <stdlib.h>
using namespace std;

int main (const int argc, const char* const argv[])
{

// each line of the pyramid
	int triangle_width = atoi(argv[1]);
	int spaces_counter=0;
while (triangle_width >= 1)
{	
	int spaces_counter = 0;

	while (spaces_counter < spaces_per_line)
		{	cout << " ";
	spaces_counter = spaces_counter + 1;
	}
	
	int asterisk_counter = 

	while(asterisk_counter >= 1)
	{
		cout << "*";
		asterisk_counter = asterisk_counter - 1;
	}

	cout << endl;
	triangle_width= triangle_width - 2;
	spaces_per_line = spaces_per_line + 1;

}
	return 0;
}