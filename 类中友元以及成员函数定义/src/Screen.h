/* 定义了一个屏幕类 */
#include <string>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;     // 别名
	Screen() = default;  // 有其他构造函数存在，因此需要一个默认构造，否则会覆盖默认构造
	// 设置屏幕窗口大小，以及每个位置的字符的构造函数
    Screen(pos ht, pos wd, char c): height(ht), width(wd), 
	                                contents(ht * wd, c) { }
	friend class Window_mgr;    // 这是一个窗口管理类
    Screen(pos ht = 0, pos wd = 0):     // 空屏幕，其实作用是不是有点像默认构造的作用
       cursor(0), height(ht), width(wd), contents(ht * wd, ' ') { }
    char get() const              // 获取当前位置的内容
	    { return contents[cursor]; }       // 隐含式内联
    inline char get(pos ht, pos wd) const; // 指定内联
	Screen &clear(char = bkground);        // 情况内容
private:
	static const char bkground = ' ';
public:
    Screen &move(pos r, pos c);      // 光标移动，给定两个位置参数
    Screen &set(char);               // 设置字符
    Screen &set(pos, pos, char);     // 设置指定位置字符
    // 根据对象是否是const进行的重载(其实不重载是不是也可以)
    Screen &display(std::ostream &os) 
                  { do_display(os); return *this; }
    // 不重载不可以，因为万一是const对象，隐含的*this可不是const的              
    const Screen &display(std::ostream &os) const
                  { do_display(os); return *this; }
private:
     // 展示screen内容，定为私有，且do_display为const成员函数
     void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen &Screen::clear(char c) 
{
	contents = std::string(height*width, c);    // 全部清空，或者设为c
	return *this;
}

inline                   // 指定内联
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // 将光标
    cursor = row + c;    // 移动到指定位置
    return *this;        // 返回这个Screen
}

char Screen::get(pos r, pos c) const // 在类中指定为内联的那个函数
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // 返回指定位置的字符
}

inline Screen &Screen::set(char c) 
{ 
    contents[cursor] = c; // 设置光标处的字符
    return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // 设置指定位置的字符
	return *this;                  // return this object as an lvalue
}

