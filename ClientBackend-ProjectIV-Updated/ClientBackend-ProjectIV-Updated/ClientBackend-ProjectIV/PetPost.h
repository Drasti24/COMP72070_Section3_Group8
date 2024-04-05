#ifndef PETPOST_H
#define PETPOST_H

#include <string>


class PetPost {
private:
    int id;
    std::string sellerId; // Identifier for the seller creating the post
    std::string petName;
    int petAge;
    bool isVaccinated;
    std::string petColor;
    std::string petBreed;
    std::string description; // A brief description of the pet
    std::string imagePath; // Path to an image of the pet

public:
    // Constructors
    PetPost();
    // Additional constructors as needed

    // Setters
    void setId(int id);
    void setSellerId(const std::string& sellerId);
    void setPetName(const std::string& petName);
    void setPetAge(int petAge);
    void setIsVaccinated(bool isVaccinated);
    void setPetColor(const std::string& petColor);
    void setPetBreed(const std::string& petBreed);
    void setDescription(const std::string& description);
    void setImagePath(const std::string& imagePath);

    // Getters
    int getId() const;
    std::string getSellerId() const;
    std::string getPetName() const;
    int getPetAge() const;
    bool getIsVaccinated() const;
    std::string getPetColor() const;
    std::string getPetBreed() const;
    std::string getDescription() const;
    std::string getImagePath() const;
};

#endif // PETPOST_H
