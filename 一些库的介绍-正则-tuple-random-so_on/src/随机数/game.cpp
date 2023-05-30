/*
 * 通过一个游戏引入随机数引擎以及概率分布类
*/ 

#include <string>
using std::string;

#include <random>
using std::default_random_engine;	// 是随机数生成器引擎的类，C++标准库提供的一种默认的随机数生成器。它根据特定的算法和种子(seed)生成随机数序列
using std::bernoulli_distribution;	// 是一个概率分布类，表示伯努利分布(Bernoulli distribution)

#include <iostream>
using std::cin; using std::cout; using std::endl;

bool play(bool player) { return player; }
int main()
{
	string resp;

	default_random_engine e;  // 定义随机数生成引擎

	// 50/50 odds by default
	bernoulli_distribution b(0.55); // 事件发生的概率为0.55

	do {
		bool first = b(e);    // 0.55的概率为true
		cout << (first ? "We go first" 
	                   : "You get to go first") << endl;
					   
		cout << ((play(first)) ? "sorry, you lost" 
	                           : "congrats, you won") << endl;
		cout << "play again? Enter 'yes' or 'no'" << endl;
	} while (cin >> resp && resp[0] == 'y');

	return 0;
}
