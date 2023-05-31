/* 函数引用：只需注意做左值的情况 */
#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

char &get_val(string &str, string::size_type ix) 
{
    return str[ix]; // 函数引用可作左值
}

int main() 
{
    string s("a value");
    cout << s << endl;   // prints a value

    get_val(s, 0) = 'A'; // changes s[0] to A
    cout << s << endl;   // prints A value

    return 0;
}

