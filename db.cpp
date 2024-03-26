#include"db.h"
void add_to_Db(User a)
{
    sql::Driver* driver;
    sql::Connection* con;
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    con->setSchema("phonebook");
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("INSERT INTO Users(FIO, Phone) VALUES(?, ?)");
    pstmt->setString(1, a.FIO);
    pstmt->setString(2, a.phone);
    pstmt->execute();
    delete pstmt;
}
void delete_from_Db(User a)
{
    sql::Driver* driver;
    sql::Connection* con;
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    con->setSchema("phonebook");
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("DELETE FROM Users WHERE FIO = ?");
    pstmt->setString(1, a.FIO);
    pstmt->execute();
    delete pstmt;
}
void search_at_Db(User a)
{
    sql::Driver* driver;
    sql::Connection* con;
    sql::ResultSet* res;
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
    con->setSchema("phonebook");
    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("SELECT * FROM Users WHERE FIO = ?");
    pstmt->setString(1, a.FIO);
    res = pstmt->executeQuery();
    while (res->next())
    {
        std::cout << "ФИО - " << res->getString("FIO") << std::endl;
        std::cout << "Номер телефона - " << res->getString("Phone") << std::endl;
    }
    delete pstmt;
}