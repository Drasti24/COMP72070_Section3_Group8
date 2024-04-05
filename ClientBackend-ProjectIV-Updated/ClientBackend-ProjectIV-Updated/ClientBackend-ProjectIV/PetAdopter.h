#ifndef PETADOPTER_H
#define PETADOPTER_H

#include <string>

class PetAdopter {
private:
    std::string firstName;
    std::string lastName;
    std::string username;
    std::string password; // Note: In a real application, passwords should be hashed

public:
    // Constructors
    PetAdopter() = default;
    PetAdopter(const std::string& firstName, const std::string& lastName, const std::string& username, const std::string& password);

    // Setters
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getUsername() const;
    std::string getPassword() const; // Be cautious with password handling
};

#endif // PETADOPTER_H
