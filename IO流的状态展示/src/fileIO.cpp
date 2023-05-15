/* 文件IO流的状态，并且展示了main参数的使用 */
#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <fstream>	// 文件流
using std::ifstream; 

#include <string>
using std::string;

#include <stdexcept>	// 包含诸多异常类的标准库头文件
using std::runtime_error;

void process(ifstream &is)	// 参数是文件输入流的引用
{
	string s;
	// while (is >> s)			// 以每个string隔开，也就是说读取每一个string之后就换行
	// 	cout << s << endl;
	while (getline(is, s))			// 按行读取
		cout << s << endl;
}

int main(int argc, char* argv[])	// 第一个参数是程序，第二个参数一般是我们要打开的文件(以该源码为例)
{
	// for each file passed to the program
	if (argc == 1)	cerr << "Please Select The File!" << endl;
	for (auto p = argv + 1; p != argv + argc; ++p) {
	    ifstream input(*p);   // p是一个指针，指向文件的位置，ifstream打开该文件
	    if (input) {          // 文件没问题，就打开
	        process(input);
		} else
	        cerr << "couldn't open: " + string(*p);	// 否则报错
	} // input goes out of scope and is destroyed on each iteration
	
	auto p = argv + 1, end = argv + argc;
	
	ifstream input;           
	while (p != end) {        // for each file passed to the program
		input.open(*p);       // open the file, automatically clears the stream 
	    if (input) {          // if the file is ok, read and ``process'' the input
	        	process(input);
		} else
			cerr << "couldn't open: " + string(*p);
	    input.close();        // close file when we're done with it
	    ++p;                  // increment pointer to get next file
	}
}
