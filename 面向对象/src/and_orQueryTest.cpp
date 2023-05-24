
#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>

using std::set;
using std::string;
using std::cin; using std::cout; using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    // 获取文件进行读取且建立映射以支持查询
    TextQuery file = get_file(argc, argv); 

    // iterate with the user: prompt for a word to find and print results
    while (true) {
        string sought1, sought2, sought3;
        if (!get_words(sought1, sought2)) break;
        cout << "\nenter third word: " ;
        cin  >> sought3;
        // 查找所有请求的字符串的输入次数
        Query q = Query(sought1) & Query(sought2) 
                             | Query(sought3);
        cout << "\nExecuting Query for: " << q << endl;
        const auto results = q.eval(file);
        // report matches
		print(cout, results);
     } 
     return 0;
}
