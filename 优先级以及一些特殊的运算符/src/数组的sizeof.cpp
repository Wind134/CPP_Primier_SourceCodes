/* 数组字节大小 */
#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int ia[] = {0,1,2,3,4,5,6,7,8,9};

int main()
{
   // sizeof(ia)/sizeof(*ia) returns the number of elements in ia
   constexpr size_t sz = sizeof(ia)/sizeof(*ia);

   int arr2[sz];  // ok sizeof returns a constant expression 

   cout << "ia size: " << sz
   << "\nsizeof(ia): " << sizeof(ia) 
   << "\nsizeof per num: "<< sizeof(*ia) << endl;

   return 0;
}
