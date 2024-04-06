#include "PetSeller.h"
#include <stdexcept>

// Utility function to validate string length
void PetSeller::validateStringLength(const std::string& str, size_t max_length, const std::string& field_name) {
    if (str.empty() || str.length() > max_length) {
        throw std::invalid_argument("The " + field_name + " must be between 1 and " + std::to_string(max_length) + " characters long.");
    }
}

// Utility function to validate string with regex
void PetSeller::validateRegexMatch(const std::string& str, const std::regex& pattern, const std::string& error_message) {
    if (!std::regex_match(str, pattern)) {
        throw std::invalid_argument(error_message);
    }
}

// Implement setters, with validation
void PetSeller::setFirstName(const std::string& fName) {
    validateStringLength(fName, 50, "first name");
    this->firstName = fName;
}

void PetSeller::setLastName(const std::string& lName) {
    validateStringLength(lName, 50, "last name");
    this->lastName = lName;
}

void PetSeller::setUsername(const std::string& uName) {
    validateStringLength(uName, 50, "username");
    this->username = uName;
}

void PetSeller::setPassword(const std::string& pwd) {
    if (pwd.empty() || pwd.length() < 6 || pwd.length() > 100) {
        throw std::invalid_argument("Password must be between 6 and 100 characters long.");
    }
    this->password = pwd;
}

PetSeller::PetSeller(const std::string& firstName, const std::string& lastName, const std::string& username,
                     const std::string& password, const std::string& businessLocation, const std::string& province,
                     const std::string& postalCode, const std::string& phoneNumber)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->username = username;
    this->password = password;
    this->businessLocation = businessLocation;
    this->province = province;
    this->postalCode = postalCode;
    this->phoneNumber = phoneNumber;
}

void PetSeller::setBusinessLocation(const std::string& location) {
    validateStringLength(location, 100, "business location");
    this->businessLocation = location;
}

void PetSeller::setProvince(const std::string& prov) {
    std::regex provincePattern("^(AB|BC|MB|NB|NL|NT|NS|NU|ON|PE|QC|SK|YT)$");
    validateRegexMatch(prov, provincePattern, "Invalid province abbreviation.");
    this->province = prov;
}

void PetSeller::setPostalCode(const std::string& pCode) {
    std::regex postalCodePattern("[A-Za-z]\\d[A-Za-z] ?\\d[A-Za-z]\\d");
    validateRegexMatch(pCode, postalCodePattern, "Invalid postal code format.");
    this->postalCode = pCode;
}

void PetSeller::setPhoneNumber(const std::string& phone) {
    std::regex phonePattern("\\d{10}");
    validateRegexMatch(phone, phonePattern, "Phone number must be 10 digits long.");
    this->phoneNumber = phone;
}

// Implement getters
std::string PetSeller::getFirstName() const { return firstName; }
std::string PetSeller::getLastName() const { return lastName; }
std::string PetSeller::getUsername() const { return username; }
std::string PetSeller::getPassword() const { return password; }
std::string PetSeller::getBusinessLocation() const { return businessLocation; }
std::string PetSeller::getProvince() const { return province; }
std::string PetSeller::getPostalCode() const { return postalCode; }
std::string PetSeller::getPhoneNumber() const { return phoneNumber; }
