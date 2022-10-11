#include "test.h"

int main()
{
    //std::cout << "n=" << n << "\n";
    std::cout << "a=" << a << "\n";
    func_normal();
    static_func_normal_hpp();

    Test t;
    std::cout << Test::m_test << "\n";
    Test::static_func_normal();

    return 1;
}
