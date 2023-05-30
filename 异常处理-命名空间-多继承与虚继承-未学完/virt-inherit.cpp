/*
 * 虚继承
*/ 

#include "Animal_virtual_baseVers.h"
#include <iostream>
using std::cout; using std::endl; using std::ostream;

void dance(const Bear&) 
	{ cout << "dance(const Bear&)" << endl; }

void rummage(const Raccoon&) 
	{ cout << "rummage(const Raccoon&)" << endl; }

ostream& operator<<(ostream&, const ZooAnimal&) 
	{ return cout << "ZooAnimal output operator" << endl; }

int main ()
{
	Panda ying_yang;
	dance(ying_yang);   // ok: passes Panda object as a Bear 
	rummage(ying_yang); // ok: passes Panda object as a Raccoon 

	cout << ying_yang;  // ok: passes Panda object as a ZooAnimal

	return 0;
}
