/* 文件IO流的状态，并且展示了main参数的使用 */
#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <fstream>	// 文件流
using std::ifstream, std::ofstream; 

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

void truncWrite(const string& fpath, const string& s)
{
	ofstream os(fpath, ofstream::out | ofstream::trunc);
	if(os)
	{
		os << s << endl;
		os.close();
	}
	else	cout << "Write to file Successfully" << endl;
}


void appWrite(const string& fpath, const string& s)
{
	ofstream os(fpath, ofstream::app);
	if(os)
	{
		os << s << endl;
		os.close();
	}
	else	cout << "Failed to write to file!" << endl;
}

int main(int argc, char* argv[])	// 第一个参数是程序，第二个参数一般是我们要打开的文件(以该源码为例)
{
	// for each file passed to the program
	if (argc == 1)
	{
		cerr << "Please Select The File!" << endl;
		exit(1);
	}

	// 以下代码为测试写入模式之用
	appWrite(*(argv + 1), "This is the first line");
	truncWrite(*(argv + 1), "This is the second line");	// 正常来说第一行的写入就被覆盖了
	appWrite(*(argv + 1), "This is the third line");
	ifstream file(*(argv + 1));

	if (file) {          // 文件没问题，就打开
	        process(file);
		} else
	        cerr << "couldn't open: " + string(*(argv + 1));	// 否则报错


	for (auto p = argv + 1; p != argv + argc; ++p) {
	    ifstream input(*p);   // p是一个指针，指向文件的位置，ifstream打开该文件(文件的内容输入->input)
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
