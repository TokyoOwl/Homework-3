#include<string>
struct User
{
    explicit User(std::string fio, std::string phone);
    explicit User(std::string fio);
    std::string FIO;
    std::string phone;
};