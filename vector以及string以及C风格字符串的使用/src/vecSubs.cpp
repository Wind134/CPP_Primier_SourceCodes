#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	auto sz = v.size(); 
	decltype(sz) i = 0;
	// duplicate contents of v onto the back of v
	while (i != sz) {
		v.push_back(*v.begin() + i);
		++i;
	}
	// prints 0...9 0...9
	for (auto it : v)
		cout << it << " ";
	cout << endl;
	
	// alternative way to stop when we get to the original last element
	vector<int> alt_v = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0...9
	for (decltype(alt_v.size()) i = 0, sz = alt_v.size(); i != sz; ++i)
		alt_v.push_back(alt_v[i]);

	// prints 0...9 0...9
	for (auto it : alt_v)
		cout << it << " ";
	cout << endl;

	vector<int> v2 = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0 ... 9
	decltype(v2.size()) ix = 0;   // we'll use ix to index the vector

	// set the elements with values less than 5 to 0
	while (ix != v2.size() && v2[ix] < 5) {
		v2[ix] = 0; // changes the value of the element in v
		++ix;       // increment the index so the next iteration fetches the next element
	}

	// print the elements using subscripts
	for (unsigned i = 0; i != v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	// equivalent but using iterators
	vector<int> alt_v2 = {0,1,2,3,4,5,6,7,8,9}; // vector with values 0...9
	// set the elements to 0 up to the first one that is 5 or greater
	auto it = alt_v2.begin();
	while (it != alt_v2.end() && *it < 5) {
		*it = 0;   // 改变元素值
		++it;      // 递增迭代器
	}
	for (auto it = alt_v2.begin(); // it denotes first element in alt_v2
	          it != alt_v2.end();  // so long as it denotes an element
	          ++it)          // increment the iterator to next element
		cout << *it << " ";  // print element denoted by it from alt_v2
	cout << endl;

	return 0;
}
