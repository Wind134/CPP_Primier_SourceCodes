/*
 * 展示了bind的使用
*/ 

#include <string>
using std::string; 

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl; 

#include <algorithm>
using std::find_if;

#include <functional>
using std::bind;
using std::placeholders::_1; 

int main()
{
    vector<string> svec = {"hi", "bye"};
    // svec中每个元素都是string类型，可以检测vector中的string对象是否为空
    auto it = find_if(svec.begin(), svec.end(), 	// find_if返回第一个满足给定条件的迭代器
	                  bind(&string::empty, _1));	// 检测string是否存在字符串，不存在是空，否则不是
    if (it == svec.end())	// 代表没有为空的 
		cout << "worked" << endl; 
	else 
		cout << "failed"  << endl;
	auto f =  bind(&string::empty, _1);
	cout << f(*svec.begin()); // 显然不为空，因此empty返回false
	f(&svec[0]); // 同上
}


