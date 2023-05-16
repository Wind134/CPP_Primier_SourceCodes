
// Version_test.h contains definitions for to_string and stod
// if the compiler does not yet define these functions,
// this code will use the definitions we provide
#include "Version_test.h" 

#include <string>
using std::string;
#ifdef STRING_NUMERIC_CONVS
using std::to_string; using std::stod;
#endif

#include <iostream>
using std::cout; using std::endl;

int main()
{
	int i = 42;
	// converts the int i to its character representation
	string s = std::to_string(i);  

	double d = std::stod(s);   // converts the string s to floating-point
	cout << "i = " << i << " s = " << s << " d is: " << d << endl;

	// convert the first substring in s that starts with a digit,  d = 3.14
	string s2 = "pi = 3.14";
	d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));

	cout << "d = " << d << " s = " << s << " s2 is: " << s2 << endl;

	return 0;
}
