/*
 * 展示了一种报错的情况
*/ 

#include "Version_test.h"

// if the regular expression library isn't support, do nothing
#ifdef REGEX

#include <iostream>
using std::cout; using std::endl;

#include <regex>
using std::regex; using std::sregex_iterator; using std::smatch;
using std::regex_error;

int main()
{
	try {
		// 方括号之间少了一个闭合括号，因此输出会报错
		regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase); 
	} catch (regex_error e) 
	     { cout << e.what() << "\ncode: " << e.code() << endl; }

	return 0;
}
#else

// do nothing
int main() { return 0; }

#endif

