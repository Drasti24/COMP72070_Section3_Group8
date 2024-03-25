#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

enum requestType { LOGIN_SUCCESS, LOGIN_FAIL, LOGIN_ACT, LOGUP, POST, UNKNOWN };

class Packet
{
public:
    struct packetHeader
    {
        unsigned char sourceAddr;
        unsigned char destAddr;
        enum requestType reqType;
        unsigned int lengthOfName;
        unsigned int lengthOfLastName;
        unsigned int lengthOfUsername;
        unsigned int lengthOfHashedPassword;
        unsigned int lengthOfBusinessAddress;
        unsigned int lengthOfProvince;
        unsigned int lengthOfPostalCode;
        unsigned int lengthOfPostTitle;
        unsigned int lengthOfPostContent;
        unsigned int digitsInPhoneNumber;
        unsigned int licenseNumberSize;
        unsigned int animalTypeParam;
        unsigned int boolSize;
        unsigned int ageSize;
        size_t sizeOfImageBuffer;
    } pktHeader;

    struct loginInformation
    {
        std::string username;
        std::string hashedPassword;
    } loginInfo;

    struct logUpOwners
    {
        std::string firstName;
        std::string lastName;
        std::string username;
        std::string hashedPassword;
        std::string businessAddress;
        std::string province;
        std::string postalCode;
        unsigned long int businessPhone;
        unsigned int licenseNumber;
    } lUOwners;

    struct petInformation
    {
        unsigned int animalType;
        bool vaccinationStatus;
        unsigned int age;
    } petInfo;

    struct postParameters
    {
        std::string postTitle;
        std::string postContent;
        char* imageBuffer = nullptr;
    } postParams;

    char* bufferOfReceivedData = nullptr;
    char* dataToBeSent = nullptr;

    Packet() {};


    Packet(std::string username, std::string hashedPassword)
    {
        this->loginInfo.username = username;
        this->loginInfo.username += '\0';
        this->loginInfo.hashedPassword = hashedPassword;
        this->loginInfo.hashedPassword += '\0';
        /*
        * After setting the attributes from received object data,
        * we must tell the header what the sizes of each data type is.
        *
        * This is imperative as it will be used to serialize data down the
        * line.
        */
        this->pktHeader.reqType = LOGIN_ACT;
        this->pktHeader.lengthOfUsername = username.length();
        this->pktHeader.lengthOfHashedPassword = hashedPassword.length();

    }

    Packet(std::string firstName, std::string lastName, std::string username, std::string hashedPassword,
        std::string businessAddress, std::string province, std::string postalCode, unsigned long int businessPhone,
        unsigned int licenseNumber, unsigned int animalType, bool vaccinationStatus, unsigned int age)
    {
        this->lUOwners.firstName = firstName;
        this->lUOwners.lastName = lastName;
        this->lUOwners.username = username;
        this->lUOwners.hashedPassword = hashedPassword;
        this->lUOwners.businessAddress = businessAddress;
        this->lUOwners.province = province;
        this->lUOwners.postalCode = postalCode;
        this->lUOwners.businessPhone = businessPhone;
        this->lUOwners.licenseNumber = licenseNumber;

        this->petInfo.animalType = animalType;
        this->petInfo.vaccinationStatus = vaccinationStatus;
        this->petInfo.age = age;

        this->pktHeader.reqType = LOGUP;
        this->pktHeader.lengthOfName = firstName.length();
        this->pktHeader.lengthOfLastName = lastName.length();
        this->pktHeader.lengthOfUsername = username.length();
        this->pktHeader.lengthOfHashedPassword = hashedPassword.length();
        this->pktHeader.lengthOfProvince = province.length();
        this->pktHeader.lengthOfPostalCode = postalCode.length();
        this->pktHeader.lengthOfBusinessAddress = businessAddress.length();
        this->pktHeader.licenseNumberSize = sizeof(lUOwners.licenseNumber);

        this->pktHeader.animalTypeParam = sizeof(petInfo.animalType);
        this->pktHeader.boolSize = sizeof(petInfo.vaccinationStatus);
        this->pktHeader.ageSize = sizeof(petInfo.age);

    }

    size_t imageData(char* imageBuffer)
    {
        std::ifstream imageFile(imageBuffer, std::ios::binary | std::ios::ate);
        if (!imageFile.is_open()) {
            std::cerr << "Error opening image file" << std::endl;
            return 0;
        }

        size_t fileSize = imageFile.tellg();
        imageFile.close();

        return fileSize;
    }

    Packet(std::string postTitle, std::string postContent, char* imageBuffer)
    {
        this->postParams.postTitle = postTitle;
        this->postParams.postContent = postContent;
        this->pktHeader.sizeOfImageBuffer = imageData(imageBuffer);
        this->postParams.imageBuffer = new char[this->pktHeader.sizeOfImageBuffer];

        this->pktHeader.reqType = POST;
        this->pktHeader.lengthOfPostTitle = postTitle.length();
        this->pktHeader.lengthOfPostContent = postContent.length();
    }



    char* serializeDataForLogin(unsigned int* totalSize)
    {
        if (this->dataToBeSent) {
            delete this->dataToBeSent;
        }

        *totalSize = sizeof(packetHeader) + pktHeader.lengthOfUsername + pktHeader.lengthOfHashedPassword;
        dataToBeSent = new char[*totalSize];

        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));

        unsigned int offset = sizeof(packetHeader);
        memcpy(dataToBeSent + offset, loginInfo.username.c_str(), pktHeader.lengthOfUsername);
        offset += loginInfo.username.length();
        memcpy(dataToBeSent + offset, loginInfo.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);

        return dataToBeSent;
    }

    char* serializeDataForPetInformation(unsigned int* totalSize)
    {
        if (this->dataToBeSent) {
            delete this->dataToBeSent;
        }
        *totalSize = sizeof(packetHeader) + pktHeader.animalTypeParam + pktHeader.boolSize + pktHeader.ageSize;
        dataToBeSent = new char[*totalSize];

        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
        unsigned int offset = sizeof(packetHeader);
        memcpy(dataToBeSent + offset, &petInfo.animalType, pktHeader.animalTypeParam);
        offset += pktHeader.animalTypeParam;
        memcpy(dataToBeSent + offset, &petInfo.vaccinationStatus, pktHeader.boolSize);
        offset += pktHeader.boolSize;
        memcpy(dataToBeSent + offset, &petInfo.age, pktHeader.ageSize);
        offset += pktHeader.ageSize;

        return dataToBeSent;
    }

    loginInformation deserializeDataForLogin(char** receivedData)
    {
        memcpy(&pktHeader, *receivedData, sizeof(packetHeader));

        unsigned int offset = sizeof(packetHeader);
        loginInfo.username = std::string(*receivedData + offset, pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;
        loginInfo.hashedPassword = std::string(*receivedData + offset, pktHeader.lengthOfHashedPassword);

        return loginInfo;
    }

    packetHeader deserializeDataForHeader(char** receivedData)
    {
        memcpy(&pktHeader, *receivedData, sizeof(packetHeader));

        return pktHeader;
    }

    char* serializeDataForLogUp(unsigned int* totalSize)
    {
        *totalSize = sizeof(packetHeader);
        *totalSize += pktHeader.lengthOfName + pktHeader.lengthOfLastName + pktHeader.lengthOfUsername;
        *totalSize += pktHeader.lengthOfHashedPassword + pktHeader.lengthOfBusinessAddress + pktHeader.lengthOfPostalCode;
        *totalSize += pktHeader.digitsInPhoneNumber + pktHeader.licenseNumberSize;

        dataToBeSent = new char[*totalSize];

        memset(dataToBeSent, 0, *totalSize);

        unsigned int offset = 0;
        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
        offset += sizeof(packetHeader);

        memcpy(dataToBeSent + offset, lUOwners.firstName.c_str(), pktHeader.lengthOfName);
        offset += pktHeader.lengthOfName;

        memcpy(dataToBeSent + offset, lUOwners.lastName.c_str(), pktHeader.lengthOfLastName);
        offset += pktHeader.lengthOfLastName;

        memcpy(dataToBeSent + offset, lUOwners.username.c_str(), pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;

        memcpy(dataToBeSent + offset, lUOwners.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);
        offset += pktHeader.lengthOfHashedPassword;

        memcpy(dataToBeSent + offset, lUOwners.businessAddress.c_str(), pktHeader.lengthOfBusinessAddress);
        offset += pktHeader.lengthOfBusinessAddress;

        memcpy(dataToBeSent + offset, lUOwners.province.c_str(), pktHeader.lengthOfProvince);
        offset += pktHeader.lengthOfProvince;

        memcpy(dataToBeSent + offset, lUOwners.postalCode.c_str(), pktHeader.lengthOfPostalCode);
        offset += pktHeader.lengthOfPostalCode;

        memcpy(dataToBeSent + offset, &lUOwners.businessPhone, pktHeader.digitsInPhoneNumber);
        offset += pktHeader.digitsInPhoneNumber;

        memcpy(dataToBeSent + offset, &lUOwners.licenseNumber, pktHeader.licenseNumberSize);
        offset += pktHeader.licenseNumberSize;

        memcpy(dataToBeSent + offset, &petInfo.animalType, pktHeader.animalTypeParam);
        offset += pktHeader.animalTypeParam;

        memcpy(dataToBeSent + offset, &petInfo.vaccinationStatus, pktHeader.boolSize);
        offset += pktHeader.boolSize;

        memcpy(dataToBeSent + offset, &petInfo.age, pktHeader.ageSize);
        offset += pktHeader.ageSize;

        return dataToBeSent;
    }

    logUpOwners deserializeDataForLogUp(char** receivedData)
    {

        unsigned int offset = sizeof(packetHeader);
        lUOwners.firstName = std::string(*receivedData + offset, pktHeader.lengthOfName);
        offset += pktHeader.lengthOfName;

        lUOwners.lastName = std::string(*receivedData + offset, pktHeader.lengthOfLastName);
        offset += pktHeader.lengthOfLastName;

        lUOwners.username = std::string(*receivedData + offset, pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;

        lUOwners.hashedPassword = std::string(*receivedData + offset, pktHeader.lengthOfHashedPassword);
        offset += pktHeader.lengthOfHashedPassword;

        lUOwners.businessAddress = std::string(*receivedData + offset, pktHeader.lengthOfBusinessAddress);
        offset += pktHeader.lengthOfBusinessAddress;

        lUOwners.province = std::string(*receivedData + offset, pktHeader.lengthOfProvince);
        offset += pktHeader.lengthOfProvince;

        lUOwners.postalCode = std::string(*receivedData + offset, pktHeader.lengthOfPostalCode);
        offset += pktHeader.lengthOfPostalCode;

        memcpy(&lUOwners.businessPhone, *receivedData + offset, sizeof(pktHeader.digitsInPhoneNumber));
        offset += sizeof(pktHeader.digitsInPhoneNumber);

        memcpy(&lUOwners.licenseNumber, *receivedData + offset, sizeof(lUOwners.licenseNumber));

        // Not needed.
        // deserializeDataForPetInformation(offset, &(*receivedData));

        return lUOwners;
    }


    char* serializeDataForPost(unsigned int* totalSize)
    {
        *totalSize = sizeof(packetHeader) + pktHeader.lengthOfPostTitle + pktHeader.lengthOfPostContent;
        dataToBeSent = new char[*totalSize];
        unsigned int offset = 0;

        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
        offset += sizeof(packetHeader);

        memcpy(dataToBeSent + offset, postParams.postTitle.c_str(), pktHeader.lengthOfPostTitle);
        offset += pktHeader.lengthOfPostTitle;

        memcpy(dataToBeSent + offset, postParams.postContent.c_str(), pktHeader.lengthOfPostContent);
        offset += pktHeader.lengthOfPostContent;

        memcpy(dataToBeSent + offset, postParams.imageBuffer, pktHeader.sizeOfImageBuffer);

        return dataToBeSent;
    }

    postParameters deserializeDataForPost(const char* receivedData)
    {
        unsigned int offset = sizeof(packetHeader);
        postParams.postTitle = std::string(receivedData + offset, pktHeader.lengthOfPostTitle);
        offset += pktHeader.lengthOfPostTitle;

        postParams.postContent = std::string(receivedData + offset, pktHeader.lengthOfPostContent);
        offset += pktHeader.lengthOfPostContent;

        memcpy(postParams.imageBuffer, receivedData + offset, pktHeader.sizeOfImageBuffer);

        return postParams;
    }

    petInformation deserializeDataForPetInformation(char** receivedData)
    {
        memcpy(&pktHeader, *receivedData, sizeof(packetHeader));
        unsigned int offset = sizeof(packetHeader);

        memcpy(&petInfo.animalType, *receivedData + offset, pktHeader.animalTypeParam);
        offset += pktHeader.animalTypeParam;

        memcpy(&petInfo.vaccinationStatus, *receivedData + offset, pktHeader.boolSize);
        offset += pktHeader.boolSize;

        memcpy(&petInfo.age, *receivedData + offset, pktHeader.ageSize);
        offset += pktHeader.ageSize;

        return petInfo;
    }

};