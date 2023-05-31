/*
 * 这是之前定义的Screen类
*/ 

#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    typedef std::string::size_type pos;

	
	using Action = Screen&(Screen::*)();    // Action一个指向Screen类成员函数(没有参数)的指针，返回类型是Screen&

    // constructor: build screen of given size containing all blanks
    Screen(pos ht = 0, pos wd = 0): contents(ht * wd, ' '), cursor(0), 
                                    height(ht), width(wd) { }
	friend int main();
	// data is a static member that returns a pointer to member
	static const std::string Screen::*data() 
	    { return &Screen::contents; }

	char get_cursor() const { return contents[cursor]; }
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
private:
    std::string contents;
    pos cursor;
    pos height, width;

public:
	// cursor movement functions 
	// beware: these functions don't check whether the operation is valid
    Screen& home() { cursor = 0; return *this; }
    Screen& forward() { ++cursor; return *this; }
    Screen& back() { --cursor; return *this; }
    Screen& up() { cursor += height; return *this; }
    Screen& down() {cursor -= height; return *this; }

    // specify which direction to move; enum see XREF(enums)
    enum Directions { HOME, FORWARD, BACK, UP, DOWN };
    Screen& move(Directions);
private:
    static Action Menu[];      // 一个函数表，该表保存的就是那个指针
};

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // compute row location
    return contents[row + c]; // return character at the given column
}

inline
Screen& Screen::move(Directions cm)
{
    // run the element indexed by cm on this object
    return (this->*Menu[cm])(); // Menu[cm] points to a member function
}

#endif

