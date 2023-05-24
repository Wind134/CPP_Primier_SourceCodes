/* 这是一个展示查询结果的类 */

#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

// 观察下面这个类，包含了三个属性：查询的单词、指向这个单词所在行集合的指针、指向输出内容的指针
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);	// 友元函数，执行打印功能
public:
	typedef std::vector<std::string>::size_type line_no;		// 行号
	typedef std::set<line_no>::const_iterator line_it;			// set类型的迭代器
	QueryResult(std::string s, 									// 查找的字符串
	            std::shared_ptr<std::set<line_no>> p, 			// 查询结果(行号)
	            std::shared_ptr<std::vector<std::string>> f):	// 所有文本的内容
		sought(s), lines(p), file(f) { }
	std::set<line_no>::size_type size() const  { return lines->size(); }	// 出现的次数
	line_it begin() const { return lines->cbegin(); }			// 第一次出现的行
	line_it end() const   { return lines->cend(); }				// 最后一次出现的行
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }	// 指向文本内容的指针
private:
	std::string sought;  // 这个查询代表的单词
	std::shared_ptr<std::set<line_no>> lines; 		// 所在行
	std::shared_ptr<std::vector<std::string>> file; // 输入文件的内容
};

std::ostream &print(std::ostream&, const QueryResult&);
#endif
