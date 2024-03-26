#include"mai.h"
struct User
{
    explicit User() {};
    ~User() {};
    std::string FIO;
    std::string phone;

    
    void clear_data()
    {
        FIO.clear();
        phone.clear();
    }
    void set_fio(std::string str)
    {
        FIO = str;
    }
    void set_phone(std::string str)
    {
        phone = str;
    }
};
int main()
{
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    setlocale(LC_ALL, "Rus");
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        system("pause");
        exit(1);
    }
    con->setSchema("phonebook");
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
                User new_user;
                auto fio = get_fio();
                auto phoneNumber = get_phone();
                new_user.set_fio(fio);
                new_user.set_phone(phoneNumber);
                pstmt = con->prepareStatement("INSERT INTO Users(FIO, Phone) VALUES(?, ?)");
                pstmt->setString(1, new_user.FIO);
                pstmt->setString(2, new_user.phone);
                pstmt->execute();
                new_user.clear_data();
                delete pstmt;

                break;
            }
            case 2:
            {
                User new_user;
                auto fio = get_fio();
                new_user.set_fio(fio);
                pstmt = con->prepareStatement("DELETE FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.FIO);
                pstmt->execute();
                std::cout << "Пользователь удалён из базы данных\n";
                delete pstmt;
                new_user.clear_data();
                break;
            }
            case 3:
            {
                User new_user;
                auto fio = get_fio();
                new_user.set_fio(fio);
                pstmt = con->prepareStatement("SELECT * FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.FIO);
                res = pstmt->executeQuery();
                while (res->next())
                {
                    std::cout << "ФИО - " << res->getString("FIO") << std::endl;
                    std::cout << "Номер телефона - " << res->getString("Phone") << std::endl;
                }
                delete pstmt;
                new_user.clear_data();
                break;
            }
        }
    }
	return 0;
}