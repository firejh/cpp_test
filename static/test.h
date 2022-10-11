#include <stdlib.h>
#include <stdint.h>
#include <iostream>

// 必须声明extern，否则多模块引用会造成重复定义
extern int n;

// static 普通变量，直接初始化，静态区域存储
static int a = 1;


// 普通非成员函数，默认是extern声明，编译只会在本模块产生（T）
void func_normal();

// static非成员函数，可以在头文件声明，但是多余，直接在cpp中实现即可
//static void static_func_normal();

// static非成员函数，在头文件中实现，所有引用的模块都会编译一份模块内部使用，会造成包体变大，不建议
static void static_func_normal_hpp()
{
    std::cout << __FUNCTION__ << "\n";
}

class Test
{
public:
    Test();

    // static成员变量，数据存储在静态存储区，不能直接初始化，需要在类外初始化，但是要在cpp文件初始化，否则会出现重复定义问题；同时也受到对象的一些限制（外部调用需要加域名（类名）、private则只能由类成员访问）
    static int m_test;

    // 函数基本变为static非成员函数，也不再有对象的this指针，对象名作用类似namespace。注意static声明在头文件，不能在cpp。
    static void static_func_normal();
};
//可以编译，但是如果多个模块引用该头文件就会报错，即类似static非成员变量
//int Test::m_test = 1;

