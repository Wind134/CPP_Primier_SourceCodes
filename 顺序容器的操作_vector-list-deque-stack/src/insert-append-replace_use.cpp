/* 展示了insert以及append以及replace的详细用法 */
#include <algorithm>
using std::replace;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;


int main() 
{
	string s = "some string", s2 = "some other string";
	// equivalent ways to insert all the characters from s2 at beginning of s
	// insert iterator range before s.begin()
	s.insert(s.begin(), s2.begin(), s2.end());	// 在s.begin()的位置插入s2的[begin, end)范围的元素  
	cout << "insert iterators version:        " << s << endl;
	
	s = "some string";
	s.insert(0, s2); // 同上
	cout << "insert string at given position: " << s << endl;

	s = "some string";
	// 第一个参数代表s的插入起始位，第二个参数代表要插入的字符串s2
	// 第三个、第四个参数代表要插入s2中的元素的范围[s2[0], s2[s2.size())
	s.insert(0, s2, 0, s2.size());   
	cout << "insert positional version:       " << s << endl;

	
	s = "";  // s is now empty
	vector<char> c_vec(1, 'a');
	// insert characters from c_vec into s
	s.insert(s.begin(), c_vec.begin(), c_vec.end());  
	// 这里不存在迭代器，第二个参数代表的是要插入的第三个参数对应的字符的个数
	s.insert(s.size(), 5, '!');
	cout << s << endl;

	s.erase(s.size() - 5, 5);   // 删除倒数5个数
	cout << s << endl;

	s = "";  // s is now empty
	const char *cp = "Stately, plump Buck";
	// assign用于将容器中的元素替换为新的元素
	// 第一个参数是要插入的字符串，第二个参数代表要插入的字符的个数
	s.assign(cp, 7);            // s == "Stately"
	cout << s << endl;
	// 在这里第一个参数是要插入字符的位置
	// 第二个参数代表的是要插入的cp的起始位
	// 没有第三个参数，代表没有右边界，因此会直接到尾端
	s.insert(s.size(), cp + 7); // s == "Stately, plump Buck"
	cout << s << endl;
	
	s = "C++ Primer";  // reset s and s2
	s2 = s;            // to "C++ Primer"
	s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
	// append代表的就是在末尾添加
	s2.append(" 4th Ed."); // equivalent: appends " 4th Ed." to s2; 
	cout << s << " " << s2 << endl;
	
	// 两种方式替换"4th" by "5th"
	// 1. 先erase再insert
	s.erase(11, 3);                 // s == "C++ Primer Ed."
	s.insert(11, "5th");            // s == "C++ Primer 5th Ed."
	
	// 2. 直接使用replace函数
	// 从下标11开始删除3个字符，然后再从下标11插入"5th"
	s2.replace(11, 3, "5th"); // equivalent: s == s2
	
	cout << s << " " << s2 << endl;
	
	// 两种方式替换 "5th" by "Fifth"
	// 1. 从下标11开始删除3个字符，然后再从下标11插入"Fifth"
	s.replace(11, 3, "Fifth"); // s == "C++ Primer Fifth Ed."
	
	// 2. 找pos，然后同上
	auto pos = s2.find("5th");
	if (pos != string::npos)
		s2.replace(pos, 3, "Fifth");
	else
		cout << "something's wrong, s2 is: " << s2 << endl;
	cout << s << " " << s2 << endl;

	std::vector<string> strs = {"love", "go", "some", "place", "some", "you", "yes"};

	auto strs1 = strs;
    // 将容器中的所有值为 2 的元素替换为 0
    replace(strs.begin(), strs.end(), "some", "anye");

    // 输出结果
    for (const auto& str : strs) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

	for (auto& str : strs1) {
        auto pos = str.find("some");
        if (pos != std::string::npos) {
            str.replace(pos, 4, "any");
        }
    }

	for (const auto& str : strs1) {
        std::cout << str << " ";
    }
    std::cout << std::endl;


	return 0;
}
