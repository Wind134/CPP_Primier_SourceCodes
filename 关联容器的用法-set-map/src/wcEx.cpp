/* 又一种词汇数量的统计方式 */
#include <map>
using std::map;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    // count number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
	string word;
	while (cin >> word)
      ++word_count.insert({word, 0}).first->second;

	for(auto it = word_count.cbegin(); it != word_count.cend(); ++it) {
		auto w = *it;
		cout <<  w.first << " occurs " << w.second << " times" << endl;
	}

    // get iterator positioned on the first element
    auto map_it = word_count.cbegin();
    // for each element in the map
    while (map_it != word_count.cend()) {
        // print the element key, value pairs
        cout << map_it->first << " occurs " 
             << map_it->second << " times" << endl;
        ++map_it;  // increment iterator to denote the next element
    }

	return 0;
}
