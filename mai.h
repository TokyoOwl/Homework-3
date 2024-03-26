#include "test.h"
#include <conio.h>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
const std::string server = "tcp://127.0.0.1:3306";
const std::string username = "root";
const std::string password = "1234";
