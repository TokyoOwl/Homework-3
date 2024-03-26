#include "func.h"
#include "validation.h"

std::string get_fio()
{
    std::string fio;
    std::cout << "������� ���\n";
    while (getline(std::cin, fio))
    {
        if (is_valid_fio(fio))
            break;
        else
        {
            std::cout << "���������� ��� ���\n";
        }
    }
    return fio;
}
std::string get_phone()
{
    std::string phone;
    std::cout << "������� ����� �������� ��������� +7 ��� 8\n";
    while (getline(std::cin, phone))
    {
        if (is_valid_number(phone))
            return phone;
        else
        {
            std::cout << "���������� ��� ���\n";
        }
    }
}