#include "func.h"
#include "validation.h"

std::string get_fio()
{
    std::string fio;
    std::cout << "Введите ФИО\n";
    while (getline(std::cin, fio))
    {
        if (is_valid_fio(fio))
            break;
        else
        {
            std::cout << "Попробуйте ещё раз\n";
        }
    }
    return fio;
}
std::string get_phone()
{
    std::string phone;
    std::cout << "Введите номер телефона используя +7 или 8\n";
    while (getline(std::cin, phone))
    {
        if (is_valid_number(phone))
            return phone;
        else
        {
            std::cout << "Попробуйте ещё раз\n";
        }
    }
}