#include "debug_rep.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{

	cout << debug_rep("hi world!") << endl; // 因为"hi world!"是一个字面值常量

	return 0;
}
