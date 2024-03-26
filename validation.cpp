#include"validation.h"
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