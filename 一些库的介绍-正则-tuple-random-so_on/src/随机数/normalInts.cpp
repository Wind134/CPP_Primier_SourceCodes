/*
 * 整个过程模拟了从正态分布中生成随机数并统计频率的过程。
*/ 

#include <string>
using std::string;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;

#include <random>
using std::default_random_engine;
using std::normal_distribution;

#include <iostream>
using std::cerr; using std::cout; using std::endl;

#include <vector>
using std::vector; 

#include <algorithm>
using std::max_element; 

#include <numeric>
using std::accumulate;

#include <cmath>
using std::lround;

#include <cstddef>
using std::size_t;

int main()
{
	default_random_engine e;        // 生成随机整数
	normal_distribution<> n(4,1.5); // 均值为4, 标准差1.5
	vector<unsigned> vals(9);       // nine elements each 0

	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));  // 使用lround函数将其四舍五入为最接近的整数
		if (v < vals.size())        // 如果这个整数在vals的索引范围内
			++vals[v];              // 就将对应的元素加一，统计该数出现的次数。
	}

	int sum = accumulate(vals.begin(), vals.end(), 0);

	if (sum != 200)
		cout << "discarded " << 200 - sum << " results" << endl;

	for (size_t j = 0; j != vals.size(); ++j)
		cout << j << ": " << string(vals[j], '*') << endl;

	return 0;
}
