/*
 * 位操作相关方法
*/ 

#include <cstddef>
#include <iostream>
#include <string>
using std::cout; using std::cin;
using std::endl;
using std::string;
using std::size_t;

#include <bitset>
using std::bitset;
int main() 
{
	bitset<32> bitvec(1U); // 1U是一个无符号整数常量，代表十进制1，其中最低位(最右边)的为1
	                       // 其余位为0
	bool is_set = bitvec.any();      // 表示是否存在任何设置(置位)的位，置位就是有一个位被置为1
	bool is_not_set = bitvec.none(); // 表示是否所有位都没置位，显然返回false，因为有最低位置为1
	bool all_set = bitvec.all();     // 表示是否所有位都已置位，返回false，因为只有一位被置位
	size_t onBits = bitvec.count();  // 表示置位为1的数量，显然返回1
	size_t sz = bitvec.size();       // 总共32位
	
	bitvec.flip();     // 翻转所有位，0->1，1->0
	bitvec.reset();    // 所有位设置为0
	bitvec.set();      // 所有位置为1
	
	cout << "bitvec: " << bitvec << endl;
	
	sz = bitvec.size();  // 返回32
	
	onBits = bitvec.count();  // 返回32
	
	// 偶数位分配1
	for (int index = 0; index != 32; index += 2)
		bitvec[index] = 1; 

	// 等价操作
	for (int index = 0; index != 32; index += 2)
		bitvec.set(index); 
	
	// bitvec还是全1，上面的操作并没有影响到
	auto b2 = ~bitvec;  // 取反后的结果是b2

	cout << "b2: " << b2 << endl;

	// 分配bitvec的最后一个位值给b2的第一位
	b2[0] = bitvec[bitvec.size() - 1]; 
	bitvec[0] = 0;          
	bitvec[31] = bitvec[0];
	bitvec[0].flip();       
	~bitvec[0];
	bool b = bitvec[0];
	b2[0] = ~bitvec[0];
	
	unsigned i = 0;
	if (bitvec.test(i))	// 为1则true
	        ;
	
	if (bitvec[i])
	        ;
	
	cout << "bitvec: positions turned on:\n\t";
	for (int index = 0; index != 32; ++index)
		if (bitvec[index])
	    	cout << index << " ";
	cout << endl;
	

	bitvec.flip(0); 
	bitvec.set(bitvec.size() - 1);  
	bitvec.set(0, 0); // 关掉第一个位置，也就是将第一个位设置为0
	bitvec.reset(i);  // 关掉第i位 
	bitvec.test(0);   // 检查第0位
	bitvec[0] = 0;
	
	bitvec.flip(0);   // 翻转第0(1)位
	bitvec[0].flip(); // 等价操作
	
	cout << "new inits" <<endl;
	// 13位不够存0xbeef
	// 0xbeef的高位被丢弃
	bitset<13> bits13(0xbeef);  // bits are 1111011101111 

	// 20位够放
	// 多余的高位设为0
	bitset<20> bits20(0xbeef);  // bits are 00001011111011101111

	// 在64位的设备上long long 0ULL是64位的0, 
	// 所以~0ULL是64位的1, 因此0 ... 63位是one, 而64 ... 127则是0，因为高位不在取反的范围内，所以补0
    // 如果long long是32位, 则0 ... 32是1, 33 ... 127是0
	bitset<128> bits128(~0ULL); 
	cout << "bits13: " << bits13 << endl;
	cout << "bits20: " << bits20 << endl;
	cout << "bits128: " << bits128 << endl;
	cout << "bits20[0] " << bits20[0] << endl;
	cout << "bits20[19] " << bits20[19] << endl;
	
	// bitvec1 is smaller than the initializer
	bitset<32> bitvec1(0xffff);  // 0 ... 15设置为1; 
	                             // 16 ... 31 are 0
	
	// 同
	bitset<64> bitvec2(0xffff);  // bits 0 ... 15 are set to 1; 
	                             // 16 ... 63 are 0
	
	// 同
	bitset<128> bitvec3(0xffff); // bits 32 through 127 are zero
	
	cout << "bitvec1: " << bitvec1 << endl;
	cout << "bitvec2: " << bitvec2 << endl;
	cout << "bitvec2[0] " << bitvec2[0] << endl;
	cout << "bitvec2[31] " << bitvec2[31] << endl;
	
	cout << "bitvec3: " << bitvec3 << endl;
	
	
	bitset<32> bitvec4("1100"); // bits 2 and 3 are 1, all others are 0
	
	cout << "strval: " << "1100" << endl;
	cout << "bitvec4: " << bitvec4 << endl;
	
	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4); // four bits starting at str[5], 1100
	bitset<32> bitvec6(str, str.size()-4); // use last four characters 
	
	cout << "str: " << str << endl;
	cout << "bitvec5: " << bitvec5 << endl;
	
	cout << "str: " << str << endl;
	cout << "bitvec6: " << bitvec6 << endl;
	
	unsigned long ulong = bitvec3.to_ulong();
	cout << "ulong = " << ulong << endl;
	
	bitset<32> bitvec7 = bitvec1 & bitvec4;
	
	cout << "bitvec7: " << bitvec7 << endl;
	
	bitset<32> bitvec8 = bitvec1 | bitvec4;	// 或运算
	
	cout << "bitvec8: " << bitvec8 << endl;
	
	bitset<16> chk("111100110011001100000");
	cout << "chk: " << chk << endl;			// 注意：这里是丢弃低位(也就仅仅就是我们以为的低位而已)
	
	bitset<16> bits;
	cin >> bits;  // read up to 16 1 or 0 characters from cin
	cout << "bits: " << bits << endl; // print what we just read

	return 0;
}
