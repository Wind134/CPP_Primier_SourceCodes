/* 针对C风格字符串的讲解 */
#include <string>	// C++字符串
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstring>	// C风格字符串

#include <cstddef>	// C标准库的类型定义
using std::size_t;

int main() {
	string s1 = "A string example";
	string s2 = "A different string";
	
	if (s1 < s2)  // false: s2 is less than s1
		cout << s1 << endl;
	else
		cout << s2 << endl;
	const char ca1[] = "A string example";	// 注意会多一个结束字符'\0'，这就是C风格字符串的特点
	const char ca2[] = "A different string";
	
	if (strcmp(ca1, ca2) < 0)	// 笔记两个字符是否相等，相等返回0，小于返回负数，大于返回正数
		cout << ca1 << endl;
	else
		cout << ca2 << endl;
	
	const char *cp1 = ca1, *cp2 = ca2;
	cout << strcmp(cp1, cp2) << endl; 	// 输出15，因为s的ASCII码大于d的ASCII码
	cout << strcmp(cp2, cp1) << endl; 	// output is negative
	cout << strcmp(cp1, cp1) << endl; 	// output is zero
	
	
	cout << strlen(cp1) << endl; 		// 返回实际大小，忽略了末尾的空字符
	
	const unsigned sz = 16 + 18 + 2;
	char largeStr[sz];      // 保存两个相加的值
	// disastrous if we miscalculated the size of largeStr
	strcpy(largeStr, ca1);  // 字符串复制
	strcat(largeStr, " ");  // 字符串连接
	strcat(largeStr, ca2);  // concatenates ca2 onto largeStr
	// prints A string example A different string
	cout << largeStr << endl;       
	
	strncpy(largeStr, ca1, sz); // 拷贝ca1中的sz个字符到largeStr
	if (strlen(ca1) > sz)		// 如果ca1的长度大于sz，则末尾置'\0'
		largeStr[sz-1] = '\0';
	strncat(largeStr, " ", 2);  // 2代表的是连接的字符数，虽然冗余但是个好习惯，为'\0'留下空间
	strncat(largeStr, ca2, sz - strlen(largeStr)); 
	cout << largeStr << endl;       
	
	// initialize large_string as a concatenation of s1, a space, and s2
	string large_string = s1 + " " + s2; 
	cout << large_string << endl;       
	
	return 0;
}
