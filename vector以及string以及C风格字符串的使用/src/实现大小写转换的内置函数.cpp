/* 字符串大小写的简单转换 */

#include <string>
using std::string;

#include <cctype>	// 该头文件定义了一些处理字符的函数
using std::isupper; using std::toupper;	// 是否大写，转化成大写
using std::islower; using std::tolower;	// 是否小写，转化成小写
using std::isalpha; using std::isspace;	// 是否字母，是否空格

#include <iostream>
using std::cout; using std::endl;

int main()
{
	string s("Hello World!!!");
	// punct_cnt has the same type that s.size returns
	decltype(s.size()) punct_cnt = 0; 	// 推断出size_t
	
	// count the number of punctuation characters in s
	for (auto c : s)         // for every char in s
		if (ispunct(c))      // if the character is punctuation
			++punct_cnt;     // increment the punctuation counter
	
	cout << punct_cnt 
	     << " punctuation characters in " << s << endl;
	
	// convert s to uppercase
	string orig = s;
	for (auto &c : s)   // 引用，改变c
		// c is a reference, so this assignment changes the char in s
		c = toupper(c);
	cout << s << endl;
	
	// convert first word in s to uppercase
	s = orig;  // restore s to original case
	decltype(s.size()) index = 0;

	// process characters in s until we run out of characters 
	// or we hit a whitespace
	while (index != s.size() && !isspace(s[index])) {

	    // s[index] returns a reference so we can change 
		// the underlying character
		s[index] = toupper(s[index]);

		// increment the index to look at the next character 
		// on the next iteration
		++index; 
	}
	cout << s << endl;
	
	return 0;
}
