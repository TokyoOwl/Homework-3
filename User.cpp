#include"User.h"

User::User(std::string fio, std::string phone)
{
    this->FIO = fio;
    this->phone = phone;
};
User::User(std::string fio)
{
    this->FIO = fio;
};