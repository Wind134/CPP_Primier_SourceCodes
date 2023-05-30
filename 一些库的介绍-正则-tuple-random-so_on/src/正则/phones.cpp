/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;

void checkPattern(const regex &r, const string &s)
{
	smatch results;
	if (regex_search(s, results, r))	// r就是一个正则表达式规则
		cout << results.str() << endl;	// 输出结果
	else 
		cout << "no match for " << s << endl;
}

int main()
{
	// \\(?->开头得是"("，?表明(可以出现0次或者1次 \\d{3}->其次是三个数字 \\)?[-. ]?->其次是")?[-. ]?"
	// 上面的"[-. ]"表明'-' '.' ' '都是符合要求的部分,但都只能出现0次或者1次
	// 最后又是匹配4个数字
	string pattern = "\\(?\\d{3}\\)?[-. ]?\\d{3}[-. ]?\\d{4}";
	regex r(pattern);  // 匹配我们所需模式的正则对象

	// 尝试匹配的一些字符串
	string mtch1 = "(908) 555-0181";
	string mtch2 = "(908)555-0182";
	string mtch3 = "908 555-0183";
	string mtch4 = "908.555-0184";
	string mtch5 = "9085550185";

	smatch results;
	checkPattern(r, mtch1);
	checkPattern(r, mtch2);
	checkPattern(r, mtch3);
	checkPattern(r, mtch4);
	checkPattern(r, mtch5);

	string s;
	while (getline(cin, s)) 
	{
		checkPattern(r, s);
	}
	
	return 0;
}

#else

// do nothing
int main() { return 0; }

#endif

