#include "PetAdopter.h"
#include <stdexcept>
// Constructor with parameters
PetAdopter::PetAdopter(const std::string& firstName, const std::string& lastName, const std::string& username, const std::string& password)
    : firstName(firstName), lastName(lastName), username(username), password(password) {}

// Set the first name
void PetAdopter::setFirstName(const std::string& firstName) {
    if (firstName.empty() || firstName.length() > 50) {
        throw std::invalid_argument("First name is required and cannot be longer than 50 characters.");
    }
    this->firstName = firstName;
}

// Set the last name
void PetAdopter::setLastName(const std::string& lastName) {
    if (lastName.empty() || lastName.length() > 50) {
        throw std::invalid_argument("Last name is required and cannot be longer than 50 characters.");
    }
    this->lastName = lastName;
}

// Set the username
void PetAdopter::setUsername(const std::string& username) {
    if (username.empty() || username.length() > 50) {
        throw std::invalid_argument("Username is required and cannot be longer than 50 characters.");
    }
    this->username = username;
}

// Set the password
void PetAdopter::setPassword(const std::string& password) {
    if (password.empty() || password.length() < 6 || password.length() > 100) {
        throw std::invalid_argument("Password is required and must be between 6 and 100 characters.");
    }
    this->password = password;
}

// Get the first name
std::string PetAdopter::getFirstName() const {
    return firstName;
}

// Get the last name
std::string PetAdopter::getLastName() const {
    return lastName;
}

// Get the username
std::string PetAdopter::getUsername() const {
    return username;
}

// Get the password
std::string PetAdopter::getPassword() const {
    return password;
}

