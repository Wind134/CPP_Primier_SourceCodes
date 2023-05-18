/* 结合map和set统计数量 */
#include <map>
using std::map;

#include <set>
using std::set;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    // count the number of times each word occurs in the input
    map<string, size_t> word_count; // empty map from string to size_t
	set<string> exclude = {"The", "But", "And", "Or", "An", "A", 
	                       "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
		// 不在集合中的元素数量+1
		if (exclude.find(word) == exclude.end())
			++word_count[word];   // fetch and increment the counter for word

	for (const auto &w : word_count) // for each element in the map
		// print the results
		cout <<  w.first << " occurs " << w.second 
		     << ((w.second > 1) ? " times" : " time") << endl;

return 0;
}
