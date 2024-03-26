#include "func.h"
bool is_valid_number(std::string phone)
{
    if (phone[0] != '+' && phone[0] != '8')
        return false;
    if (phone[0] == '+' && phone[1] != '7')
        return false;
    if (size(phone) > 12 || size(phone) < 11)
    {
        return false;
    }
    for (int i = 1; i < size(phone); i++)
    {
        if (!isdigit(phone[i]))
        {
            return false;
        }
    }
    return true;
}
bool is_valid_fio(std::string fio)
{
    for (int i = 0; i < size(fio); i++)
    {
        if (isdigit(fio[i]))
            return false;
    }
    return true;
}
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