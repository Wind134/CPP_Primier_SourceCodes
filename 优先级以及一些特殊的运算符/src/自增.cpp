/* i++与++i的区分 */
#include <iostream>
using std::cout; using std::endl;

int main() 
{
	int i = 0, j;
	j = ++i; // j = 1, i = 1: prefix yields the incremented value
	cout << i << " " << j << endl;

	j = i++; // j = 1, i = 2: postfix yields the unincremented value
	cout << i << " " << j << endl;

	return 0;
}
