/* 读取文件并通过该文件返回一个 */

#include "Query.h"
#include "TextQuery.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; 

#include <fstream>
using std::ifstream;

#include <stdexcept>
using std::runtime_error;

// 读取文件并通过该文件返回一个一个TextQuery对象，这个并不是TextQuery类的函数，因此单独放在一个源文件中
TextQuery get_file(int argc, char **argv)
{
    // get a file to read from which user will query words
	ifstream infile;
	if (argc == 2)
    	infile.open(argv[1]);
    if (!infile) {
        throw runtime_error("No input file!");
    }

    return TextQuery(infile);  // 建立查询映射
}

bool get_word(string &s1)
{
    cout << "enter a word to search for, or q to quit: ";
    cin >> s1;
    if (!cin || s1 == "q") return false;
    else return true;
}

// 该逻辑判断s1的输入是否是q，如果是q代表要结束这个过程，则返回false
bool get_words(string &s1, string &s2)
{

    // iterate with the user: 提示输入词汇
    cout << "enter two words to search for, or q to quit: ";
    cin  >> s1;

    // stop if hit eof on input or a "q" is entered
    if (!cin || s1 == "q") return false;
    cin >> s2;
    return true;
}

