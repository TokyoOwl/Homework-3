#include"mai.h"
struct User
{
	explicit User(){};
	~User(){};
	std::string FIO = "";
    std::string nomer = "";
	std::string fio()
	{
		std::cout << "Введите ФИО\n";
        while(FIO=="")
        {
            getline(std::cin, FIO);
            for (int i = 0; i < size(FIO); i++)
                if (isdigit(FIO[i]))
                    FIO = "";
        }
        return FIO;
	}
    std::string NOMER()
	{
		std::cout << "Введите номер телефона используя +7 или 8\n";
        while (nomer == "")
        {
            getline(std::cin, nomer);
            if (size(nomer) > 12) {
                std::cout << "Слишком длинный номер\n";
                nomer = "";
            }
            else if(size(nomer) < 11)
            {
                std::cout << "Слишком короткий номер\n";
                nomer = "";
            }
            for (int i = 0; i < size(nomer); i++)
                if (!isdigit(nomer[i]) && nomer[0] != '+')
                    nomer = "";
        }
        return nomer;
	}
    void clear_data()
    {
        FIO = "";
        nomer = "";
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
    //stmt = con->createStatement();
    //stmt->execute("DROP TABLE IF EXISTS Users");
    //std::cout << "Таблица удалена(если существовала)" << std::endl;
    //stmt->execute("CREATE TABLE Users (id serial PRIMARY KEY, FIO VARCHAR(50), Phone VARCHAR(50));");
    //std::cout << "Таблица создана" << std::endl;
    int x;
    while (_getch() != 27)
    {
        system("cls");
        std::cout << "Выберите действие:\n1.Добавить пользователя в телефонную книгу\n2.Удалить пользователя из телефонной книги\n3.Поиск пользователя в телефонной книге\n";
        std::cin >> x;
        system("cls");
        switch (x)
        {
            case 1:
            {
                std::cout << "1.Добавить пользователя в телефонную книгу\n";
                User new_user;
                pstmt = con->prepareStatement("INSERT INTO Users(FIO, Phone) VALUES(?,?)");
                pstmt->setString(1, new_user.fio());
                pstmt->setString(2, new_user.NOMER());
                pstmt->execute();
                delete pstmt;
                break;
            }
            case 2:
            {
                User new_user;
                pstmt = con->prepareStatement("DELETE FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.fio());
                pstmt->execute();
                std::cout << "Пользователь с ФИО: " << new_user.FIO << " удалён из базы данных\n";
                delete pstmt;
                new_user.clear_data();
                break;
            }
            case 3:
            {
                User new_user;
                pstmt = con->prepareStatement("SELECT * FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.fio());
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