/* 使用输入流迭代器 */
#include <algorithm>
using std::copy;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
	vector<int> vec;
	istream_iterator<int> in_iter(cin);  // read ints from cin
	istream_iterator<int> eof;           // istream ``end'' iterator

	// use in_iter to read cin storing what we read in vec
	while (in_iter != eof)  // while there's valid input to read
		// postfix increment reads the stream and 
		// returns the old value of the iterator
		// we dereference that iterator to get 
		// the previous value read from the stream 
		vec.push_back(*in_iter++);  

	// use an ostream_iterator to print the contents of vec
	ostream_iterator<int> out_iter(cout, " ");
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
	
	// alternative way to print contents of vec
	for (auto e : vec)
		*out_iter++ = e;  // the assignment writes this element to cout
	cout << endl;
	
	return 0;
}
	
