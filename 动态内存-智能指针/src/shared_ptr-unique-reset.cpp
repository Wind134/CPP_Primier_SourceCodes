/* 核心还是解释了智能指针的unqiue以及reset方法的使用 */
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::ostream; using std::cin; using std::cout; using std::endl;

#include <memory>
using std::shared_ptr;

int main() 
{
	shared_ptr<string> p(new string("Hello!"));
	shared_ptr<string> p2(p);    // 分配的string对象现在有两个指针指向它了，引用计数为2
	string newVal = " World";
	if (!p.unique())	// 若p.use_count为1，即p的引用计数若为1，则p.unqiue()返回true
		// 若p是唯一指向其对象的shared_ptr，reset会释放此对象；
		// 如果传递了可选参数指针q，则会令p->q指向的对象，如下行代码所示；
		// 若是还传递了参数d，则将会调用d而不是delete来释放q
		p.reset(new string(*p)); // we aren't alone; allocate a new copy
	*p += newVal; // now that we know we're the only pointer, okay to change this object
	// 下面的输出就很明显 
	cout << *p << " " << *p2 << endl;
}
