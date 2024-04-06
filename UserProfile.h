#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <string>

class UserProfileViewer {
private:
    std::string username;
    std::string firstName;
    std::string lastName;
    bool isSeller;
    std::string businessLocation;
    std::string province;
    std::string preferences; // Preferences for adopters

public:
    // Constructor
    UserProfileViewer();

    // Setters
    void setUsername(const std::string& username);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setIsSeller(bool isSeller);
    void setBusinessLocation(const std::string& businessLocation);
    void setProvince(const std::string& province);
    void setPreferences(const std::string& preferences);

    // Getters
    std::string getUsername() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    bool getIsSeller() const;
    std::string getBusinessLocation() const;
    std::string getProvince() const;
    std::string getPreferences() const;
};

#endif // USERPROFILEVIEWER_H
