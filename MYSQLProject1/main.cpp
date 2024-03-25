#include <cppconn/prepared_statement.h>  
#include <iostream>                      
#include <mysql_connection.h>            
#include <cppconn/driver.h>             
#include <cppconn/exception.h>           
#include <sstream>                      

#include "Packet.h"

using namespace std;

// Function to establish a connection to the MySQL database
sql::Connection* connectToDatabase() {
    sql::Driver* driver;
    sql::Connection* conn;

    try {
        driver = get_driver_instance();
        conn = driver->connect("tcp://localhost:3306", "username", "password");
        conn->setSchema("database");
    }
    catch (sql::SQLException& e) {
        cerr << "Error connecting to MySQL database: " << e.what() << endl;
        return nullptr;
    }

    return conn;
}

// Function to save login information to the database
void saveLoginData(Packet::loginInformation& login_params) {
    sql::Connection* conn = connectToDatabase();
    if (!conn) {
        return;
    }

    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO loginInformation (username, password) VALUES (?, ?)");
        pstmt->setString(1, login_params.username);
        pstmt->setString(2, login_params.hashedPassword);
        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        cerr << "Error executing SQL query: " << e.what() << endl;
    }

    delete conn;
}

// Function to save sign up information to the database
void saveSignUpData(Packet::logUpOwners& logup_params) {
    sql::Connection* conn = connectToDatabase();
    if (!conn) {
        return;
    }

    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO logUpOwners (firstName, lastName, username, password, businessAddress, province, postalCode, businessPhone, licenseNumber) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        pstmt->setString(1, logup_params.firstName);
        pstmt->setString(2, logup_params.lastName);
        pstmt->setString(3, logup_params.username);
        pstmt->setString(4, logup_params.hashedPassword);
        pstmt->setString(5, logup_params.businessAddress);
        pstmt->setString(6, logup_params.province);
        pstmt->setString(7, logup_params.postalCode);
        pstmt->setInt(8, logup_params.businessPhone);
        pstmt->setInt(9, logup_params.licenseNumber);
        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        cerr << "Error executing SQL query: " << e.what() << endl;
    }

    delete conn;
}

// Function to save pet information to the database
void savePetInformation(Packet::petInformation& pet_params) {
    sql::Connection* conn = connectToDatabase();
    if (!conn) {
        return;
    }

    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO petInformation (animalType, vaccinationStatus, ages) VALUES (?, ?, ?)");
        pstmt->setBoolean(2, pet_params.vaccinationStatus);
        pstmt->setInt(3, pet_params.age);
        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        cerr << "Error executing SQL query: " << e.what() << endl;
    }

    delete conn;
}

// Function to save post information to the database
void savePostData(Packet::postParameters& postParams)
{
    sql::Connection* conn = connectToDatabase();
    if (!conn) {
        return;
    }

    try {
        sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO posts (postTitle, postContent, imageBuffer) VALUES (?, ?, ?)");
        pstmt->setString(1, postParams.postTitle);
        pstmt->setString(2, postParams.postContent);

        // Convert imageBuffer to std::istream
        std::istringstream imageStream(postParams.imageBuffer);
        pstmt->setBlob(3, &imageStream);

        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e) {
        cerr << "Error executing SQL query: " << e.what() << endl;
    }

    delete conn;
}

