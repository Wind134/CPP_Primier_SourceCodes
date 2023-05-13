#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int ival = 1024;
    int *pi = &ival;   // 存储变量所在地址的指针
    int **ppi = &pi;   // 存储指针所在地址的指针
    cout << "The value of ival\n"
         << "direct value: " << ival << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;
    cout << "ival变量的地址信息\n"
         << "直接存储变量的指针: " << pi << "\n"
         << "存储变量指针地址的指针 " << ppi << "\n";

	int i = 2; 
	int *p1 = &i;     // p1 points to i
	*p1 = *p1 * *p1;  // equivalent to i = i * i
	cout << "i  = " << i << endl;

	*p1 *= *p1;       // equivalent to i *= i
	cout << "i  = " << i << endl;

	return 0;
}
