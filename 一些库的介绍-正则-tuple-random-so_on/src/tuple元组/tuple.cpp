/*
 * 介绍了tuple的使用，tuple是一个元组，它提供了一个通用的、固定大小的、异构的数据结构
 * 可以存储多个不同类型的值，一旦创建了std::tuple，其大小和元素类型就是固定的，不能直接
 * 添加或删除元素。但是可以有很聪明的办法绕过这个限制：将现有的std::tuple中的元素和要添加的
 * 新元素一起复制到新的std::tuple中来模拟向std::tuple添加元素的效果。这样做会创建一个包含
 * 原始元素和新元素的新std::tuple。
*/ 

#include <list>	// 链表
using std::list;

#include <vector>
using std::vector;

#include <tuple>	// 元组
using std::tuple; using std::get; 
using std::tuple_size; using std::tuple_element;
using std::make_tuple;	// 制造tuple

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl; 

int main()
{
	// tuple代表了书店的交易：
	// ISBN号, 书本数量, 每本书的价格
	auto item = make_tuple("0-999-78345-X", 3, 20.00);	// 所以这个类型由编译器去推断是吗(是的，在编译的时候去推导)
	auto book = get<0>(item);      // 返回item的第一个成员
	auto cnt = get<1>(item);       // 返回item的第二个成员
	auto price = get<2>(item)/cnt; // 返回item的最后一个成员
	get<2>(item) *= 0.8;           // 打八折
	
	cout << book << " " << cnt << " " << price << endl;

	typedef decltype(item) trans; // trans与item同类型 
	
	// 返回trans对象的成员数量，这里也比较清楚的看出tuple_size模板的用法
	size_t sz = tuple_size<trans>::value;

	// cnt与item中的第二个成员的类型相同
	// tuple_element<1, trans>::type获取trans这个tuple中
	// 第二个元素的类型
	tuple_element<1, trans>::type cnt2 = get<1>(item);
	tuple_element<0, trans>::type book2 = get<0>(item);
	tuple_element<2, trans>::type price2 = get<2>(item);
	cout << tuple_size<trans>::value << endl;	// 输出tuple中元素数量的值
	
	cout << book2 << " " << cnt2 << " " << price2 << endl;
	
	tuple<size_t, size_t, size_t> threeD;  // 三个成员都设置为0
	tuple<string, vector<double>, int, list<int>>	// 去自行定义三个成员
	    someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});
	
	return 0;
}
