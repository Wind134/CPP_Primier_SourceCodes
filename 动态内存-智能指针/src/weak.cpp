/* 展示了weak指针的初步用法 */
#include <iostream>
#include <memory>
using std::make_shared; using std::weak_ptr; using std::shared_ptr;

int main()
{
	auto p = make_shared<int>(42);

	weak_ptr<int> wp(p);  // wp weakly shares with p; use count in p is unchanged

	p.reset(); // assuming p.unique() was true, the int is deleted

	if(!p)	std::cout << "p is a nullptr;" << std::endl;

	if (shared_ptr<int> np = wp.lock()) { // true if np is not null
		std::cout << "np isn't a nullptr;" << std::endl;
	}
}
