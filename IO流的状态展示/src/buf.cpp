/* IO流的缓冲区 */
#include <iostream>
using std::endl; using std::flush; using std::ends;
using std::unitbuf; using std::nounitbuf; using std::cout;

int main()
{
	// 打印hi和新的一行，然后刷新缓冲区
    cout << "hi!" << endl;  

	// 输出hi，然后刷新缓冲区；未添加任何数据
    cout << "hi!" << flush; 

	// 打印hi以及空字符'\0'，然后刷新缓冲区
    cout << "hi!" << ends;  

    cout << unitbuf;         // 所有的写入将被直接刷新

	// 将所有的输出直接刷新，没有缓冲
    cout << "first" << " second" << endl;

	cout << nounitbuf;       // 设置为正常的缓冲模式

	return 0;
}
