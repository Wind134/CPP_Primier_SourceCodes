/* 详细介绍了unique_ptr的release的用法 */

#include <string>
using std::string;

#include <memory>
using std::unique_ptr;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	unique_ptr<string> p1(new string("Stegosaurus"));
	
	// transfers ownership from p1 
	// p2接管p1指向的原始对象
	// release使得p1为空指针
	unique_ptr<string> p2(p1.release()); 
	cout << *p2 << endl; // prints Stegosaurus
	
	unique_ptr<string> p3(new string("Trex"));

	// reset重置p2指向的那片内存
	// 然后接管p3指向的对象的所有权 
	p2.reset(p3.release()); 
	cout << *p2 << endl; // prints Trex
	
	// p1 is null, p2 is steg, and p3 is trex
	if (p1)		// p1为空
		cout << "p1 not null?" << endl;
	if (p3)		// p3为空
		cout << "p2 not null?" << endl;
	cout << *p2 << endl;
}
