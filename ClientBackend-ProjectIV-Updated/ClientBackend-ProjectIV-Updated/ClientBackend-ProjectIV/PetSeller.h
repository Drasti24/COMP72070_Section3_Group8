#ifndef PETSELLER_H
#define PETSELLER_H

#include <string>
#include <regex>

class PetSeller {
private:
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string password; // Consider hashing for actual implementation
    std::string businessLocation;
    std::string province;
    std::string postalCode;
    std::string phoneNumber;

    // Utility functions for validation
    void validateStringLength(const std::string& str, size_t max_length, const std::string& field_name);
    void validateRegexMatch(const std::string& str, const std::regex& pattern, const std::string& error_message);

public:
    // Constructor
    PetSeller() = default;
    PetSeller(const std::string& firstName, const std::string& lastName, const std::string& username,
              const std::string& password, const std::string& businessLocation, const std::string& province,
              const std::string& postalCode, const std::string& phoneNumber);
    // Setters
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setUsername(const std::string& uName);
    void setPassword(const std::string& pwd);
    void setBusinessLocation(const std::string& location);
    void setProvince(const std::string& prov);
    void setPostalCode(const std::string& pCode);
    void setPhoneNumber(const std::string& phone);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getBusinessLocation() const;
    std::string getProvince() const;
    std::string getPostalCode() const;
    std::string getPhoneNumber() const;
};

#endif // PETSELLER_H
