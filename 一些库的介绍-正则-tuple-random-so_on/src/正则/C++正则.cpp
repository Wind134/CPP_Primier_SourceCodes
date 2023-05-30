/*
 * 介绍了正则表达式
*/ 

#include "Version_test.h"

// 如果不支持正则表达式库, 则什么都不做
#ifdef REGEX

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;	// 匹配结果将被存储在smatch对象中
using std::regex_error;

int main()
{
	try {
		// alnum本身就是表示字母或数字
		// ::两个冒号夹在中间的是一个特殊规则，如果没有冒号，则会被认为是匹配alnum中的任意一个字符
		// [:alnum:]表示符合这么一个规则的字符集，而不是单个字符
		// \\.表明匹配. 而(cpp|cxx|cc)表明符合三者中的任意一个字符皆是符合规则，$代表结束
		regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);	// r是一个正则表达式对象，regex::icase表示不区分大小写

		smatch results; // 匹配结果将被存储在smatch对象中
		string filename;
		while (cin >> filename) 
			if (regex_search(filename, results, r))
				cout << results.str() << endl;  // 打印匹配的结果
	} catch (regex_error e)	// 当出现语法错误
		{ cout << e.what() << " " << e.code() << endl; }	// e.what()获取异常的描述信息，通常是一条错误消息。e.code()表示异常的错误代码
	return 0;
}

#else

// do nothing
int main() { return 0; }
#endif
