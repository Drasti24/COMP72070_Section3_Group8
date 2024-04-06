#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login {
private:
    std::string username;
    std::string password;

public:
    // Constructors
    Login() = default;
    Login(const std::string& username, const std::string& password);

    // Setters
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;

    // Function to simulate login attempt
    bool attemptLogin() const;
};

#endif // LOGIN_H
