/* 展示了参数绑定，谓词，lambda表达式的使用，也展示了unique算法 */
#include <algorithm>
using std::sort; using std::for_each;

#include <functional>
using std::bind; 
using namespace std::placeholders;

#include <string>
using std::string;

#include <vector>
using std::vector; 

#include <iostream>
using std::cin; using std::cout; using std::endl; 

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)	// 词汇大小长短的比较
{
    return s1.size() < s2.size();
}

bool LT(const string &s1, const string &s2)		// string词汇大小的比较
{
	return s1 < s2;
}

void print(const vector<string> &words)
{
	for_each(words.begin(), words.end(),
	        [](const string &s) { cout << s << " "; });
	cout << endl;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }
	print(words);

	vector<string> cpy = words; // 保存初始数据

	sort(words.begin(), words.end());	// 默认排序，从小到大

	words = cpy;  // return to the original data
	// uses the LT function to compare elements
	// should have the same output as the previous sort
	sort(words.begin(), words.end(), LT);	// 基于大小排序
    print(words);

	words = cpy;  // return to the original data

	// eliminate duplicates
	sort(words.begin(), words.end());	// 先排序
	auto it = unique(words.begin(), words.end());	// 返回一个指向这些不重复元素之后的位置的迭代器。
	words.erase(it, words.end());		// 因此erase

	// sort by length using a function
	stable_sort(words.begin(), words.end(), isShorter);  
    print(words);

	words = cpy; // return to the original data
	// sort the original input on word length, shortest to longest
	sort(words.begin(), words.end(), isShorter);  
    print(words);

	// use bind to invert isShorter to sort longest to shortest
	sort(words.begin(), words.end(), bind(isShorter, _2, _1));  
    print(words);

	return 0;
}
