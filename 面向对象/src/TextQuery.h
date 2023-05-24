/* 这是一个文本查询类 */

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "QueryResult.h"

/* this version of the query classes includes two
 * members not covered in the book:  
 *   cleanup_str: which removes punctuation and 
 *                converst all text to lowercase
 *   display_map: a debugging routine that will print the contents
 *                of the lookup mape
*/

class QueryResult; // 后续要返回这个类型，因此需要先声明

// 观察下面这个类，包含了两个属性：指向文件内容的字符串指针、文中出现的词汇与所在行的集合的映射
// 定义了三个方法：query方法返回查询的结果、display_map打印上面的映射、以及cleanup_str方法以清除标点并且使得每个字母小写
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;    // 行号
	TextQuery(std::ifstream&);      // 输入文件流做参数的构造函数
    QueryResult query(const std::string&) const;    // 查询结果类
    void display_map();        // debugging aid: print the map
private:
    std::shared_ptr<std::vector<std::string>> file; // 指向输入文件的指针
    // 文中出现的词汇->所在行的集合的映射(string->point to set)
    std::map<std::string, 
	         std::shared_ptr<std::set<line_no>>> wm;  

	// 以下函数执行的功能: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};
#endif
