/* 函数形参的几种使用 */
#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

// function that takes a reference to an int 
// and sets the given object to zero
// i is just another name for the object passed to reset
void reset(int &i)  
{
    i = 0;  // changes the value of the object to which i refers
}

// function that takes a pointer 
// and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0;  // 改变了ip指向的值
    ip = 0;   // 这个只是指针在函数体内发生改变而已，不影响指针指向的值
}

int main() 
{
	int j = 42;
	reset(j);  // j is passed by reference; the value in j is changed
	cout << "j = " << j  << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	reset(&j);                     // changes j but not the address of j
	cout << "j = "  << j << endl;  // prints j = 0

	j = 42;    // restore the original value of j
	int *p = &j;
	reset(p); // changes object to which p points not the address in p
	cout << "j = "  << *p << endl;  // prints j = 0

    return 0;
}
