#include"mai.h"

int main()
{ 
    setlocale(LC_ALL, "Rus");
    int x;
    while (_getch() != 27)
    {
        system("cls");
        std::cout << "Выберите действие:\n1.Добавить пользователя в телефонную книгу\n2.Удалить пользователя из телефонной книги\n3.Поиск пользователя в телефонной книге\n";
        std::cin >> x;
        std::cin.get();
        system("cls");
        switch (x)
        {
            case 1:
            {
                std::cout << "1.Добавить пользователя в телефонную книгу\n";
                auto fio = get_fio();
                auto phoneNumber = get_phone();
                if (is_valid_fio(fio) && is_valid_number(phoneNumber))
                {
                    User new_user(fio, phoneNumber);
                    add_to_Db(new_user);
                    std::cout << "Пользователь успешно добавлен\n";
                }
                break;
            }
            case 2:
            {
                std::cout << "2.Удалить пользователя из телефонной книги\n";
                auto fio = get_fio();
                if (is_valid_fio(fio))
                {
                    User new_user(fio);
                    delete_from_Db(new_user);
                    std::cout << "Пользователь удалён из базы данных\n";
                }
                break;
                
            }
            case 3:
            {
                std::cout << "3.Поиск пользователя в телефонной книге\n";
                auto fio = get_fio();
                if (is_valid_fio(fio))
                {
                    User new_user(fio);
                    search_at_Db(new_user);
                }
                break;
            }
        }
    }
	return 0;
}