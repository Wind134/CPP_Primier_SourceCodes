/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include <iostream>
using std::cout; using std::endl; 

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::sqrt;

int main()
{
	// cout.precision报告当前的精度值
	cout  << "Precision: " << cout.precision()  
	      << ", Value: "   << sqrt(2.0) << endl;
	
	// cout.precision(12)要求打印12位有效数字(包括小数点前的非0数字)
	cout.precision(12);
	cout << "Precision: " << cout.precision() 
	     << ", Value: "   << sqrt(2.0) << endl;
	
	// alternative way to set precision using the setprecision manipulator
	cout << setprecision(3);
	cout << "Precision: " << cout.precision() 
	     << ", Value: "   << sqrt(2.0) << endl;

	cout << setprecision(3);
	cout << "Precision: " << cout.precision() 
	     << ", Value: "   << 10.223 << endl;	// 打印出10.2
	
	return 0;
}
