/* 很好的展示了内存string流的用法 */
#include <iostream>
using std::cin; using std::cout; using std::cerr;
using std::istream; using std::ostream; using std::endl;

#include <sstream>	// 内存string流
using std::ostringstream; using std::istringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

// members are public by default
struct PersonInfo { 
	string name;
	vector<string> phones;
};

// 我们将会在chapter 17看到如何重新格式化电话号码
// 现在直接返回我们给定的string即可
string format(const string &s) { return s; }

bool valid(const string &s)
{
	// we'll see how to validate phone numbers 
	// in chapter 17, for now just return true
	return true;
}

vector<PersonInfo>
getData(istream &is)	// 输入流
{
	// will hold a line and word from input, respectively
	string line, word;

	// 保存所有人的个人信息
	vector<PersonInfo> people;

	// 按行读取，直接结束
	while (getline(is, line)) {       
		PersonInfo info;            // 保存输入的数据信息的对象
	    istringstream record(line); // 把刚刚读入的line绑定到record
		record >> info.name;        // 读入到的信息送进info对象的名字程院长
	    while (record >> word)      // 读入号码，加循环是为了考虑到多个号码的情况 
			info.phones.push_back(word);  
		people.push_back(info); // 放进people数组
	}
	
	return people;
}

ostream& process(ostream &os, vector<PersonInfo> people)
{
	for (const auto &entry : people) {    // 对分组中的每个人进行处理
		ostringstream formatted, badNums; // objects created on each loop
		for (const auto &nums : entry.phones) {  // 对每个人的每个号码进行处理 
			if (!valid(nums)) {           
				badNums << " " << nums;  // 将nums送进ostring流对象
			}
			else	formatted << " " << format(nums); 	// 格式化后送进ostring流对象
		}
		if (badNums.str().empty())      // there were no bad numbers
			os << entry.name << " "     // print the name 
			   << formatted.str() << endl; // and reformatted numbers 
		else                   // otherwise, print the name and bad numbers
			cerr << "input error: " << entry.name 
			     << " invalid number(s) " << badNums.str() << endl;
	}
	
	return os;
}

int main()
{
	process(cout, getData(cin));

	return 0;
}
