/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include <iostream>
using std::cerr; using std::endl;

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include <cstdlib> // for EXIT_FAILURE

int main()
{
    // 打开文件，文件指针定位到末尾，同时以输入输出模式打开，即可以同时读取和写入
    fstream inOut("/home/ping/C++primier源码/一些库的介绍-正则-tuple-random-so_on/data/copyOut", 
                   fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE; // EXIT_FAILURE 
    } 

    // inOut文件指针的位置在末尾
    auto end_mark = inOut.tellg();// 返回当前指针的位置并保存
    inOut.seekg(0, fstream::beg); // seekg移动文件指针到指定位置，beg代表相对于文件开头
    size_t cnt = 0;               // 字节数
    string line;                  // 读取到每一行

    // 在要求的条件下执行循环
    while (inOut && inOut.tellg() != end_mark
           && getline(inOut, line)) { // 一行一行读取
        cnt += line.size() + 1;       // 换行符也算一个1字节
		auto mark = inOut.tellg();    // 记住读取到的位置
        inOut.seekp(0, fstream::end); // 设置输出流的写入位置
        inOut << cnt;                 // 写入length到文件
        // 如果不是最后一行则打印一个空格符
        if (mark != end_mark) inOut << " "; 
        inOut.seekg(mark);            // 还原读取位置
    }
    inOut.seekp(0, fstream::end);     // seek to the end
    inOut << "\n";                    // write a newline at end-of-file

    return 0;
}
