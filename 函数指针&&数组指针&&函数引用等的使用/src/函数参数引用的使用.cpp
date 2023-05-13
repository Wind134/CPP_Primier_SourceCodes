/* 展示了通过形参引用改变参数的行为 */
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstddef>
using std::size_t;

// 返回了第一次c代表的变量第一次出现的次数
// 而occurs代表了c变量代表的字符出现的次数
string::size_type find_char(const string &s, char c, 
                           string::size_type &occurs)
{
    auto ret = s.size();   // position of the first occurrence, if any
    occurs = 0;            // set the occurrence count parameter 

    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size()) 
                ret = i;   // remember the first occurrence of c
            ++occurs;      // increment the occurrence count
         }
	}
    return ret;            // count is returned implicitly in occurs
}

// 使用迭代器的等价做法
// the reference parameter occurs contains a second return value
vector<int>::const_iterator find_val(
    vector<int>::const_iterator beg,  // first element
    vector<int>::const_iterator end,  // one past last element
    int value,                        // the value we want
    vector<int>::size_type &occurs)   // number of times it occurs
{
    auto res_iter = end; // res_iter will hold first occurrence, if any
    occurs = 0;          // set occurrence count parameter 

    for ( ; beg != end; ++beg)
        if (*beg == value) {
            // remember first occurrence of value
            if (res_iter == end) 
                res_iter = beg;
            ++occurs;    // increment occurrence count
         }

    return res_iter;     // count returned implicitly in occurs
}

int main() 
{
	
	string s;
	getline(cin, s); 
	size_t ctr = 0;
	auto index = find_char(s, 'o', ctr);
	cout << index << " " << ctr << endl;
	
	vector<int> ivec;
	int i;
	// read values into ivec
	while (cin >> i)
		ivec.push_back(i);

	// for each value in the list of ints
	for (auto i : {42, 33, 92}) {
		auto it = find_val(ivec.begin(), ivec.end(), i, ctr);
		if (it == ivec.end())
			cout << i << " is not in the input data" << endl;
		else
			cout << i << " was at position " 
			     << it - ivec.begin() << endl;
	}

	return 0;
}
