#include "UserProfile.h"
#include <stdexcept>

// Constructor
UserProfileViewer::UserProfileViewer() : isSeller(false) {}

// Setters implementation
void UserProfileViewer::setUsername(const std::string& username) {
    this->username = username;
}

void UserProfileViewer::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void UserProfileViewer::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void UserProfileViewer::setIsSeller(bool isSeller) {
    this->isSeller = isSeller;
}

void UserProfileViewer::setBusinessLocation(const std::string& businessLocation) {
    if (isSeller && businessLocation.empty()) {
        throw std::invalid_argument("Business location is required for sellers.");
    }
    this->businessLocation = businessLocation;
}

void UserProfileViewer::setProvince(const std::string& province) {
    if (isSeller && province.empty()) {
        throw std::invalid_argument("Province is required for sellers.");
    }
    this->province = province;
}

void UserProfileViewer::setPreferences(const std::string& preferences) {
    // Preferences might not require validation
    this->preferences = preferences;
}

// Getters implementation
std::string UserProfileViewer::getUsername() const {
    return username;
}

std::string UserProfileViewer::getFirstName() const {
    return firstName;
}

std::string UserProfileViewer::getLastName() const {
    return lastName;
}

bool UserProfileViewer::getIsSeller() const {
    return isSeller;
}

std::string UserProfileViewer::getBusinessLocation() const {
    return businessLocation;
}

std::string UserProfileViewer::getProvince() const {
    return province;
}

std::string UserProfileViewer::getPreferences() const {
    return preferences;
}
