#include <iostream>
int main() 
{
	std::cout << "Hello World!";  // simple character string literal
	std::cout << "";              // empty character string literal
	// literal using newlines and tabs
	std::cout << "\nCC\toptions\tfile.[cC]\n";

    // multiline string literal
    std::cout << "a really, really long string literal "
	             "that spans two lines" << std::endl;

	// 三种方式输出M
	std::cout << 'M' << " " << '\115' << " " << '\x4d' << std::endl;

    unsigned long long bigVal = -1ULL;	// 无符号长长整型的最大值
    std::cout << bigVal << std::endl;

    return 0;
}

