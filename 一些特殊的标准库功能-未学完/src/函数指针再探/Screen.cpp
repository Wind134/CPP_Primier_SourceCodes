/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/

#include "Screen.h"

Screen::Action Screen::Menu[] = { &Screen::home,
                                  &Screen::forward,
                                  &Screen::back,
                                  &Screen::up,
                                  &Screen::down,
                                };  // Menu是一个数组，分别保存了指向这5个函数的指针

