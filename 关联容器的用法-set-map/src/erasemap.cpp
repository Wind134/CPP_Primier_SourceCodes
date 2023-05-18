/* map的使用，主要介绍了map移除一个条目的方式 */
#include <map>
using std::map;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() 
{
    map<string, size_t> word_count;  // 从"string"到"size_t"的映射
    string word;
    while (cin >> word)
      ++word_count[word];		// 每一个word的映射都为1

	string removal_word = "the";
	
	// 从映射中移除条目的两种方式
	// 1. 通过值
	// erase on a key returns the number of elements removed
	if (word_count.erase(removal_word))
	     cout << "ok: " << removal_word << " removed\n";
	else cout << "oops: " << removal_word << " not found!\n";

	for (const auto& w : word_count)
	{
		cout << w.first << " ";	// 这个输出会按照字典序的方式输出，这个要注意，并不是按照原先的输入顺序输出的
	}

	cout << endl;
	
	// 2. 通过移除对应的迭代器来进行移除
	removal_word = "The";  // strings are case sensitive
	map<string,size_t>::iterator where;
	where = word_count.find(removal_word);  // should be gone
	
	if (where == word_count.end())
	     cout << "oops: " << removal_word << " not found!\n";
	else {
	     word_count.erase(where);   // erase iterator returns void
	     cout << "ok: " << removal_word << " removed!\n";
	}
	    return 0;
}
