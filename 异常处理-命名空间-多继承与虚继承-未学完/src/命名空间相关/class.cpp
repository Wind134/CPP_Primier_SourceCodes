/*
 * 初步给我们展示了命名空间的特点
 */ 

#include <iostream>
#include <string>

int main()
{
    std::string s;

    // ok: 会根据std::cin参数调用std::getline(std::istream&, const std::string&)
    // 理解为这是命名空间的一个特点即可
    getline(std::cin, s);

	std::cout << s << std::endl;

    return 0;
}

