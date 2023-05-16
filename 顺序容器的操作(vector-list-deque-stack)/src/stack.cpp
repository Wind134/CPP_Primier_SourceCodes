/* 栈的用法 */
#include <cstddef>
using std::size_t;

#include <deque>	// 指的是双端队列的数据结构，双端队列支持在
using std::deque;	// 队列的前后两端进行高效地插入和删除操作

#include <stack>	// 栈的数据结构
using std::stack; 

#include <iostream>
using std::cout; using std::cerr; using std::endl;

// bool process(int);

int main()
{
	stack<int> intStack;  // empty stack

	// fill up the stack
	for (size_t ix = 0; ix != 10; ++ix)
    	intStack.push(ix);   // intStack holds 0 . . . 9 inclusive

	// while there are still values in intStack
	while (!intStack.empty()) {
    	int value = intStack.top();
    	// code that uses value
		cout << value << endl;
    	intStack.pop(); // pop the top element, and repeat
	}

	return 0;
}
