#include "PetPost.h"
#include <stdexcept>
// Default constructor
PetPost::PetPost() : id(0), petAge(0), isVaccinated(false) {}

// Implement setters
void PetPost::setId(int id) {
    this->id = id;
}

void PetPost::setSellerId(const std::string& sellerId) {
    if (sellerId.empty()) throw std::invalid_argument("Seller ID is required.");
    this->sellerId = sellerId;
}

void PetPost::setPetName(const std::string& petName) {
    if (petName.empty()) throw std::invalid_argument("Pet name is required.");
    this->petName = petName;
}

void PetPost::setPetAge(int petAge) {
    if (petAge < 0) throw std::invalid_argument("Pet age must be a non-negative number.");
    this->petAge = petAge;
}

void PetPost::setIsVaccinated(bool isVaccinated) {
    this->isVaccinated = isVaccinated;
}

void PetPost::setPetColor(const std::string& petColor) {
    if (petColor.empty()) throw std::invalid_argument("Pet color is required.");
    this->petColor = petColor;
}

void PetPost::setPetBreed(const std::string& petBreed) {
    if (petBreed.empty()) throw std::invalid_argument("Pet breed is required.");
    this->petBreed = petBreed;
}

void PetPost::setDescription(const std::string& description) {
    if (description.empty()) throw std::invalid_argument("Description is required.");
    this->description = description;
}

void PetPost::setImagePath(const std::string& imagePath) {
    if (imagePath.empty()) throw std::invalid_argument("Image path is required.");
    this->imagePath = imagePath;
}

// Implement getters
int PetPost::getId() const { return id; }
std::string PetPost::getSellerId() const { return sellerId; }
std::string PetPost::getPetName() const { return petName; }
int PetPost::getPetAge() const { return petAge; }
bool PetPost::getIsVaccinated() const { return isVaccinated; }
std::string PetPost::getPetColor() const { return petColor; }
std::string PetPost::getPetBreed() const { return petBreed; }
std::string PetPost::getDescription() const { return description; }
std::string PetPost::getImagePath() const { return imagePath; }
