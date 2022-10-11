#include "test.h"

int n = 1;

void func_normal()
{
    std::cout << __FUNCTION__ << "\n";
}

// static，编译时函数是本模块所有，因此其他模块不能调用，也可以使用相同的函数名
static void static_func_normal()
{
    std::cout << __FUNCTION__ << "\n";
}

// 没有在头文件声明，别的模块无法调用，但是依然不能重名，这也是static函数存在的价值
void func_normal_cpp()
{
    std::cout << __FUNCTION__ << "\n";
}


int Test::m_test = 1;

Test::Test()
{
    std::cout << __FUNCTION__ << "\n";
}

void Test::static_func_normal()
{
    std::cout << __FUNCTION__ << "\n";
}
