/*
 * 针对我们自行定义的vec容器的使用示例
*/
 

#include "Vec.h"

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::istream;

void print(const Vec<string> &svec)
{
	for (auto it : svec)
		cout << it << " " ;
	cout <<endl;
}

Vec<string> getVec(istream &is)
{
	Vec<string> svec;
	string s;
	while (is >> s)
		svec.push_back(s);
	return svec;
}
	
int main()
{
	Vec<string> svec = getVec(cin);
	print(svec);

	cout << "copy " << svec.size() << endl;
	auto svec2 = svec;
	print(svec2);

	cout << "assign" << endl;
	Vec<string> svec3;
	svec3 = svec2;
	print(svec3);

	Vec<string> v1, v2;
	Vec<string> getVec(istream &);	// 竟然是先声明了一个函数
	v1 = v2;           // 拷贝分配
	v2 = getVec(cin);  // 移动分配，因为getVec(cin)返回的是右值(因为是函数调用的返回值)

	return 0;
}
