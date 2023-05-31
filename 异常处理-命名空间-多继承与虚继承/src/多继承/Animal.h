/*
 * 这是一个多继承关系的学习
*/ 

#include <string>
#include <iostream>
#include <algorithm>

class Endangered {  // 这是一个为濒危动物设计的类
public:
    virtual ~Endangered()   // 虚析构函数
		{ std::cout << "Endangered dtor" << std::endl; }
    virtual std::ostream& print() const // 下面是各个函数执行显示
		{ return std::cout << "Endangered::print" << std::endl; }
    virtual void highlight() const
		{ std::cout << "Endangered::highlight" << std::endl; }
	virtual double max_weight() const
		{ std::cout << "Endangered::max_weight" << std::endl; return 0; }
    // . . .
};

class ZooAnimal;
extern std::ostream&  // 作用于全局
operator<<(std::ostream&, const ZooAnimal&);

class ZooAnimal {
public:
    ZooAnimal() = default;
    ZooAnimal(std::string animal, bool exhibit,
              std::string family): nm(animal), 
                                   exhibit_stat(exhibit), 
                                   fam_name(family) { } 
    virtual ~ZooAnimal()
		{ std::cout << "Animal dtor" << std::endl; }

    virtual std::ostream& print() const
		{ return std::cout << "Animal::print" << std::endl; }
    virtual int population() const
		{ std::cout << "Animal::population" << std::endl; return 0;}
	virtual double max_weight() const
		{ std::cout << "Animal::max_weight" << std::endl; return 0;}

    // 访问受保护成员的函数，一个接口
    std::string name() const { return nm; } // 动物类型名
    std::string family_name() const { return fam_name; }  // 该动物又属于什么科 
    bool onExhibit() const { return exhibit_stat; }
    // . . .
protected:
    std::string nm;
    bool        exhibit_stat = false;
    std::string fam_name;
    // . . .
private:
};

using DanceType = unsigned; // 别名
constexpr DanceType two_left_feet = 0;
constexpr DanceType Astaire = 1;
constexpr DanceType Rogers = 42;

class Bear : public ZooAnimal {
public:
    Bear() = default;
    Bear(std::string name, bool onExhibit=true, 
         std::string family = "Bear"):
                         ZooAnimal(name, onExhibit, family),
                         dancetype(two_left_feet) { }

    virtual std::ostream &print() const
		{ return std::cout << "Bear::print" << std::endl; }
    virtual int toes() const
		{ std::cout << "Bear::toes" << std::endl; return 0; }
    int mumble(int)
		{ std::cout << "Bear::mumble" << std::endl; return 0; }
    void dance(DanceType) const 
		{ std::cout << "Bear::dance" << std::endl; }

    virtual ~Bear()
		{ std::cout << "Bear dtor" << std::endl; }
private:
    DanceType   dancetype = Rogers;
};

class Panda : public Bear, public Endangered {  // 多继承
public:
    Panda() = default;
    Panda(std::string name, bool onExhibit=true);
    virtual ~Panda()
		{ std::cout << "Panda dtor with" << std::endl; }
    virtual std::ostream& print() const
		{ return std::cout << "Panda::print" << std::endl; }
    void highlight()
		{ std::cout << "Panda::highlight" << std::endl; }
    virtual int toes()
		{ std::cout << "Panda::toes" << std::endl; return 0; }
    virtual void cuddle()
		{ std::cout << "Panda::cuddle" << std::endl; }
	virtual double max_weight() const;
// . . .
};

inline
Panda::Panda(std::string name, bool onExhibit)  // 构造函数部分交给他继承的基类Bear来处理
      : Bear(name, onExhibit, "Panda") { }

inline
double Panda::max_weight() const
{
    return std::max(ZooAnimal::max_weight(), 
	                Endangered::max_weight());
}

class PolarBear : public Bear { /* . . . */ };
