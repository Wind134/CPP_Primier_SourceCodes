/*
 * 11标准下的新东西
*/ 

#include <iostream>
using std::cout; using std::endl;

#include "Version_test.h"
#ifdef HEX_MANIPS
using std::hexfloat; using std::defaultfloat;	// 浮点数以十六进制输出，或者以默认浮点数输出
#endif

int main()
{
	double pi = 3.14;
	cout << pi << " " 
#ifdef HEX_MANIPS
	     << hexfloat << pi    // no workaround for this missing manipulator
#endif
	     << defaultfloat << " " << pi << endl;
	
	return 0;
}
