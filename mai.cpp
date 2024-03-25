#include"mai.h"
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
void is_valid_tests()
{
    assert(is_valid_number("+79999999999" ) == true);
    assert(is_valid_fio("Litov Yakov Lvovich") == true);
    std::cout << "Tests OK\n";
}
struct User
{
    explicit User() {};
    ~User() {};
    std::string FIO;
    std::string phone;

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
    void clear_data()
    {
        FIO.clear();
        phone.clear();
    }
    void set_fio()
    {
        FIO = get_fio();
    }
    void set_phone()
    {
        phone = get_phone();
    }
};
int main()
{
    is_valid_tests();
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
        std::cout << "�������� ��������:\n1.�������� ������������ � ���������� �����\n2.������� ������������ �� ���������� �����\n3.����� ������������ � ���������� �����\n";
        std::cin >> x;
        std::cin.get();
        system("cls");
        switch (x)
        {
            case 1:
            {
                std::cout << "1.�������� ������������ � ���������� �����\n";
                User new_user;
                new_user.set_fio();
                new_user.set_phone();
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
                new_user.set_fio();
                pstmt = con->prepareStatement("DELETE FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.FIO);
                pstmt->execute();
                std::cout << "������������ ����� �� ���� ������\n";
                delete pstmt;
                new_user.clear_data();
                break;
            }
            case 3:
            {
                User new_user;
                new_user.set_fio();
                pstmt = con->prepareStatement("SELECT * FROM Users WHERE FIO = ?");
                pstmt->setString(1, new_user.FIO);
                res = pstmt->executeQuery();
                while (res->next())
                {
                    std::cout << "��� - " << res->getString("FIO") << std::endl;
                    std::cout << "����� �������� - " << res->getString("Phone") << std::endl;
                }
                delete pstmt;
                new_user.clear_data();
                break;
            }
        }
    }
	return 0;
}//