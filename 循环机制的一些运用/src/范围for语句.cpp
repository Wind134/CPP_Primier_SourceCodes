#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main()
{
	vector<int> ivec;
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};

	// range variable must be a reference so we can write to the elements
	for (auto &r : v)   // for each element in v
		r *= 2;         // double the value of each element in v
	
	// print every element in v
	for (int r : v)
		cout << r << " "; // print the elements in v
	cout << endl;

	return 0;
}
