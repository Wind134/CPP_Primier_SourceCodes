/*
 * 该头文件包含了枚举类型enum，枚举类型是一种用户自定义的类型，用于表示一组具有离散取值的常量；
*/ 

#include <string>
#include <iostream>

class Endangered {  // 这是一个濒危动物类
public:
    enum Status { critical, environment, improving }; // 定义了一个枚举类型Status，包括这三个内容
    Endangered(Status stat = improving): animal_status(stat) { }  // 构造函数初始化
    virtual ~Endangered()   // 虚析构函数
		{std::cout << "Endangered::~Endangered" << std::endl; }

    virtual std::ostream& print(std::ostream&) const  // 带参数的print执行
		{ return std::cout << "Endangered::print" << std::endl; }
    virtual void highlight() const                    // 不带参数的highlight
		{std::cout << "Endangered::highlighted" << std::endl; }
    // . . .
private:
    Status animal_status; // 定义了一个枚举变量animal_status
};

class ZooAnimal;  // 类声明
extern std::ostream&
operator<<(std::ostream&, const ZooAnimal&);  // 重载操作符，设置为全局的

class ZooAnimal { // 定义动物园动物类
public:
    ZooAnimal() = default;
    ZooAnimal(std::string animal, bool exhibit,
              std::string family): nm(animal), 
                                   exhibit_stat(exhibit), 
                                   fam_name(family) { } 
    virtual ~ZooAnimal()
		{std::cout << "ZooAnimal::~ZooAnimal" << std::endl; }

    virtual std::ostream& print(std::ostream&) const
		{ return std::cout << "ZooAnimal::print" << std::endl; }
    virtual int population() const
		{std::cout << "ZooAnimal::population" << std::endl;  return 0;}

    // 以下是用于访问和获取对象的私有成员变量的方法或函数
    std::string name() const { return nm; }
    std::string family_name() const { return fam_name; }
    bool onExhibit() const { return exhibit_stat; }
    // . . .
protected:
    std::string nm;
    bool exhibit_stat = false;
    std::string fam_name;
    // . . .
private:
};

// the order of the keywords public and virtual is not significant
class Raccoon : public virtual ZooAnimal {
public:
    Raccoon() = default;
    Raccoon(std::string name, bool onExhibit=true);

    virtual std::ostream& print(std::ostream&) const
		{ return  std::cout << "Raccoon::print" << std::endl; }

    bool pettable() const {return pettable_flag;  }
    void pettable(bool petval) {pettable_flag = petval;}
    // . . .

protected:
    bool pettable_flag = false;
    // . . .
};

class Bear : virtual public ZooAnimal {
public:
    // when the most derived class
    Bear(std::string name, bool onExhibit=true);
protected:
    // when an intermediate derived class
    Bear() : dance_flag(two_left_feet) { }

public:
    enum DanceType { two_left_feet, macarena, fandango };

    virtual std::ostream &print(std::ostream&) const
		{ return  std::cout << "Bear::print" << std::endl; }
    virtual std::string isA() const
		{ std::cout << "Bear::isA" << std::endl; return "Bear"; }
    int mumble(int)
		{ std::cout << "Bear::mumble" << std::endl; return 0; }
    void dance(DanceType) const
		{ std::cout << "Bear::dance" << std::endl; }

	virtual ~Bear() { std::cout << "Bear::~Bear" << std::endl; }
private:
    std::string name;
    DanceType dance_flag;
};

class Panda : public Bear,
              public Raccoon, public Endangered {
public:
    Panda() = default;
    Panda(std::string name, bool onExhibit=true);
    virtual std::ostream& print(std::ostream&) const
		{ return  std::cout << "Panda::print" << std::endl; }

    bool sleeping() const {return sleeping_flag;}
    void sleeping(bool newval) {sleeping_flag = newval;}
    // . . .

protected:
    bool sleeping_flag = false;
    // . . .
};


Bear::Bear(std::string name, bool onExhibit):
         ZooAnimal(name, onExhibit, "Bear") { }
Raccoon::Raccoon(std::string name, bool onExhibit)
       : ZooAnimal(name, onExhibit, "Raccoon") { }

Panda::Panda(std::string name, bool onExhibit)
      : ZooAnimal(name, onExhibit, "Panda"),
        Bear(name, onExhibit),
        Raccoon(name, onExhibit),
        Endangered(Endangered::critical),
        sleeping_flag(false)   { }

