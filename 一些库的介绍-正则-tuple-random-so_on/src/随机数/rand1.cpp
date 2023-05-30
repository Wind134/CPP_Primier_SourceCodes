/*
 * 介绍默认的随机数生成算法，均匀整数分布，正态分布
*/ 

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;	// 伪随机生成函数，注意是伪随机

#include <random>
using std::default_random_engine;		// 使用默认的随机数生成算法
using std::uniform_int_distribution;	// 均匀整数分布
using std::normal_distribution;			// 正态分布

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <algorithm>
using std::max_element;

#include <cstddef>
using std::size_t;

int main()
{
	default_random_engine e;  // generates random unsigned integers
	for (size_t i = 0; i < 10; ++i)
		// e() "calls" the object to produce the next random number
		cout << e() << " ";
	cout << endl;

	// 0~9之间的整数均匀分布
	uniform_int_distribution<unsigned> u(0,9);
	default_random_engine e2;  
	for (size_t i = 0; i < 10; ++i)
		// u uses e as a source of numbers
		// each call returns a uniformly distributed value 
		// in the specified range
    	cout << u(e2) << " ";
	cout << endl;

	default_random_engine e3;  
	// generates normally distributed doubles 
	// with mean 100, standard deviation 15
	normal_distribution<> n(100,15);  
	for (size_t i = 0; i < 10; ++i)
    	cout << n(e3) << " ";
	cout << endl;

	// bad, but common way to generate random numbers in a given range
	for (size_t i = 0; i < 10; ++i)
		// r will be a between 0 and 9, but randomness is compromised
		cout << rand()%10 << " ";
	cout << endl;

	default_random_engine e4;
	// uniformly distributed from 0 to 9 inclusive
	uniform_int_distribution<unsigned> u2(0,9);
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e4) << " ";
	cout << endl;

	// seeding the engine causes it to generate different numbers 
	// on different executions
	default_random_engine e5(time(0));  
	for (size_t i = 0; i < 10; ++i)
    	cout << u2(e5) << " ";
	cout << endl;

    // assuming shorts have 16 bits
    uniform_int_distribution<short> us1;     // values from 0 to 32767
    uniform_int_distribution<short> us2(42); // values from 42 to 32767
    cout << "min: " << us1.min() << " max: " << us1.max() << endl;
    cout << "min: " << us2.min() << " max: " << us2.max() << endl;

    default_random_engine e6;
    cout << "min: " << e6.min() << " max: " << e6.max() << endl;

	return 0;
}
