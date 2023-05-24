/* 这是对头文件Query.h的实现
* 更准确来说，是对每个特定派生类的eval的实现；
*/

#include "Query.h"
#include "TextQuery.h"

#include <memory>
using std::shared_ptr; using std::make_shared;

#include <set>
using std::set;

#include <algorithm>
using std::set_intersection;

#include <iostream>
using std::ostream;

#include <cstddef>
using std::size_t;

#include <iterator>
using std::inserter; 

// 返回不在操作数结果集中的行
QueryResult
NotQuery::eval(const TextQuery& text) const
{
    // 通过Query中的操作对eval的virtual调用 
    auto result = query.eval(text);		// result是一个结果查询类的对象

	// 从一个空的结果集中开始，这里存储不在正确结果集中的行
    auto ret_lines = make_shared<set<line_no>>();

	// 我们需要遍历操作数出现的行，这个是正确的结果集
	auto beg = result.begin(), end = result.end();

	// sz代表的整个输入文本的内容
	auto sz = result.get_file()->size();

	// 对于输入文件的每一行，如果该行不在结果中,
    // 则添加相应符合要求行号进去，因此遍历每一行
    for (size_t n = 0; n != sz; ++n) {
		// if we haven't processed all the lines in result
		// check whether this line is present
		if (beg == end || *beg != n) 	// 如果遍历到头了，或者这一行不在正确的结果集中
			ret_lines->insert(n);  		// 则插入该行号

		// 如果不满足上述情况，即还没有遍历到头且当前行号在正确结果集中	
		else // if (beg != end)			
			++beg; // 则beg递增
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

// 返回操作数结果的交集
QueryResult
AndQuery::eval(const TextQuery& text) const
{
    // 通过Query进行virtual调用以便得到操作符的结果集
    auto left = lhs.eval(text), right = rhs.eval(text);

	// 保存交集的结果
    auto ret_lines = make_shared<set<line_no>>();  

    // writes the intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
	// 下面是一个标准库函数，给定了两个迭代器范围，取两个范围内的交集
	// 插入到ret_lines所指向的set，并且从首位置开始插入
    set_intersection(left.begin(), left.end(), 
                   right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// 返回操作数结果的并集
QueryResult
OrQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query members, lhs and rhs 
	// the calls to eval return the QueryResult for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);  

	// 先把左操作数的结果给复制过来
	auto ret_lines = 
	     make_shared<set<line_no>>(left.begin(), left.end());

	// 再插入右操作数的结果集
	ret_lines->insert(right.begin(), right.end());
	
	// 以下返回结果
    return QueryResult(rep(), ret_lines, left.get_file());
}

