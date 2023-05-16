/* vector数组的capacity调整 */
#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> ivec;

    // size应该是0; 容量大小由实现方式来定义
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;

    // give ivec 24 elements
    for (vector<int>::size_type ix = 0; ix != 24; ++ix) 
         ivec.push_back(ix);
     
    // size应该是24; capacity要>= 24但具体大小由实现方式去判定
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;
    ivec.reserve(50); // 将capacity设置为至少50; 也许会更多
    // size应该是24; capacity将>=50，具体由实现方式去确定
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;

    // 补0，直到最后充满容量大小
    while (ivec.size() != ivec.capacity())
         ivec.push_back(0);

    // capacity与size大小一致
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;
    ivec.push_back(42); // add one more element

    // size是51; capacity将>= 51，但具体大小依赖于实现方式
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;

    ivec.shrink_to_fit();  // 该成员函数要求容器缩减容量以适应当前存储的元素数量

    // size should be unchanged; capacity is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: "  << ivec.capacity() << endl;

return 0;
}

