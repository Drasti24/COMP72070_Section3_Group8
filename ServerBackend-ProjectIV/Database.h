#pragma once
#include "Packet.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>             
#include <cppconn/exception.h>           
#include <sstream>   
#include <cppconn/prepared_statement.h>  

// Function definitions:

sql::Connection* connectToDatabase();
void saveLoginData(Packet::loginInformation&);
void saveSignUpData(Packet::logUpOwners&);
void savePetInformation(Packet::petInformation&);
void savePostData(Packet::postParameters&);

