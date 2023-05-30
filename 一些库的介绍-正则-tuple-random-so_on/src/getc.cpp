/*
 * iostream同样包含EOF
*/ 

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstdio> // for EOF

int main()
{
	int ch;    // use an int, not a char to hold the return from get()

	// loop to read and write all the data in the input
	while ((ch = cin.get()) != EOF)
         	cout.put(ch);
	cout << endl;

	return 0;
}
