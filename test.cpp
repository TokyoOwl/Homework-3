#include"test.h"
void is_valid_tests()
{
    assert(is_valid_number("+79999999999") == true);
    assert(is_valid_fio("Litov Yakov Lvovich") == true);
    std::cout << "Tests OK\n";
}