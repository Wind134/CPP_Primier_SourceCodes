/* 讲解vector以及string的构造 */
#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Sales_item.h"

int main()
{
	// list initialization, articles has 3 elements
	vector<string> articles = {"a", "an", "the"};

	vector<string> svec; // default initialization; svec has no elements
	vector<int> ivec;             // ivec holds objects of type int
	vector<Sales_item> Sales_vec; // holds Sales_items
	
	vector<vector<string>> file;  // vector whose elements are vectors
	vector<vector<int>> vecOfvec; // each element is itself a vector
	
	// all five vectors have size 0
	cout << svec.size() << " " << ivec.size() << " "
	     << Sales_vec.size() << " "
	     << file.size() << " " << vecOfvec.size() << endl;
	
	vector<int> ivec2(10);     // 十个元素，每个默认是0
	vector<int> ivec3(10, -1); // 十个元素，每个初始化为-1
	vector<string> svec2(10);  // 十个元素，每个字符串初始化为空
	vector<string> svec3(10, "hi!"); // 是个元素，每个字符串初始化为"Hi"
	cout << ivec2.size() << " " << ivec3.size() << " "
	     << svec2.size() << " " << svec3.size() << endl;
	
	// 10并非字符串，因此不可以列表初始化
	vector<string> v1(10); // 初始化10个元素，空
	vector<string> v2{10}; // 同上
	vector<string> v3(10, "hi");  // ten elements with value "hi"
	// again list initialization is not viable, so ordinary construction
	vector<string> v4{10, "hi"};  // ten elements with values "hi"
	
	// all four vectors have size ten
	cout << v1.size() << " " << v2.size() 
	     << " " << v3.size() << " " << v4.size() << endl;
	
	vector<string> vs1{"hi"}; // list initialization: vs1 has 1 element 
	vector<string> vs2{10};   // ten default-initialized elements
	vector<string> vs3{10, "hi"}; // has ten elements with value "hi"
	cout << vs1.size() << " " << vs2.size() << " " << vs3.size() << endl;
	
	vector<int> v5(10, 1);  // ten elements with value 1
	vector<int> v6{10, 1};  // two elements with values 10 and 1
	cout << v5.size() << " " << v6.size() << endl;
	
	// intention is clearer
	vector<int> alt_v3 = {10};    // one element with value 10
	vector<int> alt_v4 = {10, 1}; // two elements with values 10 and 1
	cout << alt_v3.size() << " " << alt_v4.size() << endl;

	return 0;
}
