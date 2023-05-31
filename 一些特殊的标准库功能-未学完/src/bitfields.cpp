/*
 * 位域是一种在C++中用于定义和控制结构体或类成员变量的特性。它允许你精确地控制变量所占用的位数，从而有效地利用内存空间。
 * 位域(bitfield)-来定义具有指定位数的成员变量，像这里mode分配两位，来应对modes中的三种场景
*/
#include <iostream>
using std::cout; using std::endl;

typedef unsigned int Bit;	// 设置别名

class File {
    // 下面是位域的定义
	Bit mode: 2;       // mode有2位位域，用于存储无符号整型，下面同理，也就是自定义无符号整型的所占位数
    Bit modified: 1;   
    Bit prot_owner: 3; 
    Bit prot_group: 3;
    Bit prot_world: 3;

public:
	// file modes specified as octal literals; see XREF(intLiterals)
	enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };	// modes有三个枚举常量：READ、WRITE和EXECUTE，分别是八进制的01、02、03，2bit足够
	File &open(modes);
	void close();
	void write();
	bool isRead() const;
	void setWrite();
	void execute();
	bool isExecute() const;
};

void File::write()
{
    modified = 1;	// 通过这个标志位告诉程序，我写入了
    // . . .
}

void File::close()
{
    if (modified)	// 收到写入信号，接下来做保存内容的工作
        // . . . save contents
	;
}

inline bool File::isRead() const { return mode & READ; }	// 如果mode中的READ被设置，则返回已读的确认
inline void File::setWrite() { mode |= WRITE; }				// 将WRITE设置为1


File &File::open(File::modes m)	// m表示的是modes中的某一个变量，每个变量都属于modes的一部分
{
	mode |= READ;    // 打开文件就将read位设置为1 <=> mode = mode | READ
	// other processing
	if (m & WRITE) 	// 如果是以读方式打开，则不会写入，也就是说if下的语句压根不会执行，只有写的方式会执行
	// processing to open the file in read/write mode
	cout << "myFile.mode READ is set" << endl;
	return *this;
}

int main()
{
	File myFile;
	
	myFile.open(File::WRITE);
	if (myFile.isRead()) 
		cout << "reading" << endl;
	
	return 0;
}

