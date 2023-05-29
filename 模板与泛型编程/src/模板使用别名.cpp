/*
 * 总体介绍了一下别名的使用
*/ 

#include "Blob.h"

#include <utility>
using std::pair;

#include <string>
using std::string;

typedef Blob<string> StrBlob; 


template<typename T> using twin = pair<T, T>;			// 将模板使用别名

template <typename T> using partNo = pair<T, unsigned>;	// 将模板使用别名

int main()
{
	// 作者是一对string
	twin<string> author("Mark", "Twain");
	
	twin<int> win_loss(2, 45);  // win_loss is a pair<int, int>
	
	typedef string Vehicle;
	partNo<Vehicle> car("volvo", 242);  // car is a pair<Vehicle, unsigned>

	return 0;
}
