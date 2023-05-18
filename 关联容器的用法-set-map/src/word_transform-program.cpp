/* 这是一个应用，通过给定的规则转化文本，结合了多种类型的使用 */

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using std::map; using std::string; using std::vector;
using std::ifstream; using std::cout; using std::endl;
using std::getline; 
using std::runtime_error; using std::istringstream;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;   // 维护一个转换映射
    string key;    // 要转换的词
	string value;  // 要替代的结果
	// 先读取第一个词汇以获取key，再阅读该行的剩余内容作为value
	while (map_file >> key && getline(map_file, value)) 
		if (value.size() > 1) // 要替代的结果必须要>1，否则没有意义
        	trans_map[key] = value.substr(1); // 跳过前导空格 
		else
			throw runtime_error("no rule for " + key);  // 否则抛出错误
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
	// 对于给定的字符串s，去映射表m中做查询
	auto map_it = m.find(s);
	// if this word is in the transformation map
	if (map_it != m.cend()) 
		return map_it->second; // 使用替换词汇
	else
		return s;              // 否则返回自身
}

// 第一个参数是转换文件
// 第二个参数是要转换的文件
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file); // 根据转换文件建立Map

	// 为了调试而设计的打印命令
    cout << "Here is our transformation map: \n\n";
	for (auto entry : trans_map)
        cout << "key: "   << entry.first
             << "\tvalue: " << entry.second << endl;
    cout << "\n\n";

	// 对给定的文件做转换
    string text;                    // 一行一行转换
    while (getline(input, text)) {  // 从输入中读取一行
        istringstream stream(text); // 读取每个词汇，读入输入字符串流 
        string word;
        bool firstword = true;      // 用来控制空格打印
        while (stream >> word) {
           if (firstword)
               firstword = false;
           else
               cout << " ";  // print a space between words
           // transform returns its first argument or its transformation 
           cout << transform(word, trans_map); // print the output 
        }
        cout << endl;        // done with this line of input
    }
}

int main(int argc, char **argv)
{
	// open and check both files
    if (argc != 3)
        throw runtime_error("wrong number of arguments");

    ifstream map_file(argv[1]); // open transformation file 
    if (!map_file)              // check that open succeeded
        throw runtime_error("no transformation file");
    
    ifstream input(argv[2]);    // open file of text to transform
    if (!input)                 // check that open succeeded
        throw runtime_error("no input file");

	word_transform(map_file, input);

    return 0;  // exiting main will automatically close the files
}
