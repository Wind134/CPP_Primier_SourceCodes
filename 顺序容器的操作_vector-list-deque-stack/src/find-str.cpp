/* string中的find使用以及npos的介绍 */
#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

int main() 
{
    string name("AnnaBelle");
    auto pos1 = name.find("Anna"); // pos1 == 0
    cout << pos1 ;
    string lowercase("annabelle");
    pos1 = lowercase.find("Anna");   // (pos1 == npos)，其中string::npos是std::string类中的一个特殊
    cout << " " << pos1 << endl;     // 静态成员，用于表示无效或未找到的位置。
    return 0;
}
