/* 对书籍进行分类 */
#include <algorithm>
using std::sort;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "Sales_item.h"

int main() 
{
    Sales_item trans;
    vector<Sales_item> file;

    while (std::cin >> trans)  // read the transations
        file.push_back(trans);

	for (auto i : file)        // print what was read
		cout << i << endl;
	cout << "\n\n";

	sort(file.begin(), file.end(), compareIsbn); // sort into ISBN order
	for (auto i : file)        // print in ISBN order
		cout << i << endl;

	return 0;
}

