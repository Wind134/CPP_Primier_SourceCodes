/* 类的实现 */

#include "TextQuery.h"
#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>

// cctype 是 C++ 标准库中的头文件，提供了一组用于字符处理的函数和常量。
// 它包含了一些用于字符分类、转换和处理的函数，如判断字符的类型（字母、数字、标点符号等）
// 转换字符的大小写、检查字符的空白性质等。
#include <cctype>

#include <cstring>      // c风格字符串
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

// 读取输入文件，并且建立 查询词汇->所有行 的映射
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {       // is是一个文件输入流，将文本的每一行
		file->push_back(text);        // push进file中
		int n = file->size() - 1;     // 更新行号
		istringstream line(text);     // 将每一行中的string字符串提取
		string word;               
		while (line >> word) {        // 将每一行中的string字符串提取
            word = cleanup_str(word);   // 每个单词转小写

            // 如果单词不在映射中, 则添加，这功能在if中执行
            auto &lines = wm[word]; // lines is a shared_ptr 
            if (!lines) // 当第一次遇见那个单词的时候，set应该是空的
                lines.reset(new set<line_no>); // 此时就分配一个新的set，带有行号类型
            lines->insert(n);      // 此时插入行号，构造函数部分执行完成
		}
	}
}


// 去逗号，转小写
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it))  // 只要不是逗号(那就是字母了)
            ret += tolower(*it);    // 就将其转换为小写字母
    }
    return ret;    // 返回这个string
}

QueryResult
TextQuery::query(const string &sought) const    // 直接去查询结果
{
	// 没发现要查询的词汇则返回一个空指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>); 

    // 使用find而不是subscript来避免向wm中添加单词
    auto loc = wm.find(cleanup_str(sought));    // 查询是针对key进行的

	if (loc == wm.end()) 
		return QueryResult(sought, nodata, file);  // 没找到
	else 
		return QueryResult(sought, loc->second, file);  // 返回对应结果
}

ostream &print(ostream & os, const QueryResult &qr)     // 输出打印结果
{
    // 如果找到了单词, 打印数量和所有出现的情况
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;

    // 打印单词出现的每一行
	for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " 
		   << *(qr.file->begin() + num) << endl;

	return os;
}

// 用来debugging的方法，书本中没讲
void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();

    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(),
                        loc_iter_end = text_locs->cend();

        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                 cout << ", ";

         }

         cout << "}\n";
    }
    cout << endl; 
}

