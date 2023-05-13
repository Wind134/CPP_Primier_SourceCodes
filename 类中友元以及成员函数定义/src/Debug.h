/* 定义了一个debug类
更精确的说是字面值常量类
 */
#ifndef DEBUG_H
#define DEBUG_H
class Debug {
public:
	constexpr Debug(bool b = true): hw(b), io(b), other(b) { }	// 默认是硬件Debug
	constexpr Debug(bool h, bool i, bool o): 					// 三个参数时自行定义
	                                hw(h), io(i), other(o) { }
	constexpr bool any() const { return hw || io || other; }			// 只要有一个需要debug就返回true
	constexpr bool hardware() const { return hw || io; }				// 硬件层面的debug只要hw或io有一个true就true
	constexpr bool app() const { return other; }		// app的debug

	void set_io(bool b) { io = b; }	// 设置IO debug
	void set_hw(bool b) { hw = b; }	// 依此类推
	void set_other(bool b) { hw = b; }
private:
	bool hw;    // 硬件错误而非IO错误
	bool io;    // IO错误
	bool other; // 其他错误
};

class HW_Subsystem {
public:
	HW_Subsystem(): debug(false) { }          // 默认不debug
	bool field_debug()   { return debug.any(); }
	bool default_debug() { return enable.any() && debug.any(); }
	void set_debug(bool b) { debug.set_hw(b); }  // 打开硬件调试
private:
	Debug debug;
	constexpr static Debug enable{true, false, false};
};

class IO_Subsystem {
public:
	IO_Subsystem(): debug(false) { }          // 默认不调试
	bool field_debug()     { return debug.any(); }
	bool default_debug()   { return enable.any() && debug.any(); }
	void set_debug(bool b) { debug.set_io(b); }  // 打开IO调试
private:
	Debug debug;
	constexpr static Debug enable{true, false, true};
};
#endif
