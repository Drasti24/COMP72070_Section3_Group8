#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")



/*
* The enumerations are used to specify the type of
* request the client/server are expecting.
* 
* The header is deserialized when a packet is received, and is then
* evaluated in the main function.
* 
* Enumerations are defined as project specific and tell the client/server
* what action is being done by the user.
*/
enum requestType { LOGIN_SUCCESS, LOGIN_FAIL, LOGIN_ACT, LOGUP_ADOPTER, LOGUP_SELLER, POST, UNKNOWN };

class Packet
{
public:
    /*
    * The header tells the receiving end everything it needs to know
    * to decipher the data. It includes attributes for all parameters
    * (the data sent within each struct).
    */
    struct packetHeader
    {
        unsigned char sourceAddr;
        unsigned char destAddr;
        enum requestType reqType;
        unsigned int lengthOfName;
        unsigned int lengthOfLastName;
        unsigned int lengthOfUsername;
        unsigned int lengthOfHashedPassword;
        unsigned int lengthOfAdopterBio;
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
    /*
    * Structure holding the sign up
    * information of user bio.
    */
    struct logUpAdopters
    {
        std::string firstName;
        std::string lastName;
        std::string username;
        std::string hashedPassword;
        std::string userBio;
    }lUAdopters;

    struct petInformation
    {
        /*
        * 0 - dog.
        * 1 - cat.
        * 2 - both.
        *
        * A boolean was originally chosen for this, but as its values
        * can only be 1 or 0, it was changed to an unsigned int instead.
        */
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

    struct loginState
    {
        bool logInStatus;
    } lnState;

    char* bufferOfReceivedData = nullptr;
    char* dataToBeSent = nullptr;

    /*
    * Each of these constructors are used to initialize
    * various struct objects depending on what request is issued
    * by the user. Each has the necessary information that the header
    * needs in order to relay to the client, and the actual data itself
    * to be serialized.
    *
    * A default constructor must also be provided.
    */

    // Default constructor to be used for non-parameterized constructors.
    Packet() {};


    Packet(std::string username, std::string hashedPassword)
    {
        this->loginInfo.username = username;
        // this->loginInfo.username += '\0';
        this->loginInfo.hashedPassword = hashedPassword;
        // this->loginInfo.hashedPassword += '\0';
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

        this->pktHeader.reqType = LOGUP_SELLER;
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

    Packet(std::string firstName, std::string lastName, std::string username, std::string hashedPassword,
        std::string userBio)
    {
        this->lUAdopters.firstName = firstName;
        this->lUAdopters.lastName = lastName;
        this->lUAdopters.username = username;
        this->lUAdopters.hashedPassword = hashedPassword;
        this->lUAdopters.userBio = userBio;

        /*
        * Just like with the rest of the constructors,
        * these attributes tell the receiving end everything
        * it needs to know to deserialize data by filling in
        * needed parameters within the packet header.
        */
        this->pktHeader.reqType = LOGUP_ADOPTER;
        this->pktHeader.lengthOfUsername = username.length();
        this->pktHeader.lengthOfHashedPassword = hashedPassword.length();
        this->pktHeader.lengthOfAdopterBio = userBio.length();
    }

    Packet(std::string postTitle, std::string postContent, char* imageBuffer)
    {
        this->postParams.postTitle = postTitle;
        this->postParams.postContent = postContent;
        this->pktHeader.sizeOfImageBuffer = imageData(imageBuffer);
        this->postParams.imageBuffer = new char[this->pktHeader.sizeOfImageBuffer];
        std::memcpy(this->postParams.imageBuffer, imageBuffer, this->pktHeader.sizeOfImageBuffer);

        this->pktHeader.reqType = POST;
        this->pktHeader.lengthOfPostTitle = postTitle.length();
        this->pktHeader.lengthOfPostContent = postContent.length();
    }

    Packet(bool logInResult, requestType login_state)
    {
        this->lnState.logInStatus = logInResult;

        this->pktHeader.reqType = login_state;
        this->pktHeader.boolSize = sizeof(lnState.logInStatus);
    }

    /*
    * This function is to be used by the client.
    * The client Must tell the server what the size of the image is.
    * 
    * Call this function before creating an instance of a packet
    * and serializing data for a post.
    * 
    * IMPORTANT: Remember to clean memory after serializing/deserializing!
    */
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

    bool convertBinaryToImage(const char* buffer, size_t bufferSize, const std::string& outputPath)
    {
        std::ofstream outputFile(outputPath, std::ios::binary);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file" << std::endl;
            return false;
        }

        outputFile.write(buffer, bufferSize); // Write the binary data to the output file
        outputFile.close();

        return true;
    }
    /*
    * These two functions convert from an image file.
    * to binary, then from binary back to an image.
    */

    enum requestType getRequestType()
    {
        return this->pktHeader.reqType;
    }

    char* convertImageToBinary(const std::string& imagePath, size_t& imageSize)
    {
        std::ifstream imageFile(imagePath, std::ios::binary | std::ios::ate);
        if (!imageFile.is_open()) {
            std::cerr << "Error opening image file" << std::endl;
            return nullptr;
        }

        imageSize = imageFile.tellg(); // Get the size of the image file
        imageFile.seekg(0, std::ios::beg); // Move back to the beginning of the file

        char* buffer = new char[imageSize];
        imageFile.read(buffer, imageSize); // Read the entire file into the buffer
        imageFile.close();

        return buffer;
    }

    /*
    * All of these functions serialize and deserialize data. The way they work is
    * by copying data back and forth from memory. When serializing, we are copying into
    * a buffer.
    *
    * When deserializing, we are retreiving data from a buffer to a struct object
    * that is subsequently saved in a database.
    */

    char* serializeDataForLogin(unsigned int* totalSize)
    {
    /*
    * If the buffer has been used, empty it to
    * create a new buffer to return.
    *
    * Done to prevent memory leaks and segmentation
    * faults (buffer overflows).
    */
        if (this->dataToBeSent) {
            delete this->dataToBeSent;
        }

        *totalSize = sizeof(packetHeader) + pktHeader.lengthOfUsername + pktHeader.lengthOfHashedPassword;
        dataToBeSent = new char[*totalSize];
        /*
        * initializes other values in memory to 0 to avoid
        * garbage values. Useful for debugging.
        */
        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));

        unsigned int offset = sizeof(packetHeader);
        memcpy(dataToBeSent + offset, loginInfo.username.c_str(), pktHeader.lengthOfUsername);
        offset += loginInfo.username.length();
        memcpy(dataToBeSent + offset, loginInfo.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);

        return dataToBeSent;
    }

    char* serializeDataForLogInState(unsigned int* totalSize)
    {
        if (this->dataToBeSent) {
            delete this->dataToBeSent;
        }

        *totalSize = sizeof(packetHeader) + pktHeader.boolSize;

        dataToBeSent = new char[*totalSize];

        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
        unsigned int offset = sizeof(packetHeader);

        memcpy(dataToBeSent + offset, &lnState.logInStatus, pktHeader.boolSize);
        offset += pktHeader.boolSize;

        return dataToBeSent;

    }

    char* serializeDataForLogUpAdopters(unsigned int* totalSize)
    {
        if (this->dataToBeSent) {
            delete this->dataToBeSent;
        }

        *totalSize = sizeof(packetHeader) + pktHeader.lengthOfName, pktHeader.lengthOfLastName;
        *totalSize += pktHeader.lengthOfUsername + pktHeader.lengthOfHashedPassword + pktHeader.lengthOfAdopterBio;

        dataToBeSent = new char[*totalSize];

        memset(dataToBeSent, 0, *totalSize);

        memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
        unsigned int offset = sizeof(packetHeader);

        memcpy(dataToBeSent + offset, lUAdopters.firstName.c_str(), pktHeader.lengthOfName);
        offset += pktHeader.lengthOfName;

        memcpy(dataToBeSent + offset, lUAdopters.lastName.c_str(), pktHeader.lengthOfLastName);
        offset += pktHeader.lengthOfLastName;

        memcpy(dataToBeSent + offset, lUAdopters.username.c_str(), pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;

        memcpy(dataToBeSent + offset, lUAdopters.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);
        offset += pktHeader.lengthOfHashedPassword;

        memcpy(dataToBeSent + offset, lUAdopters.userBio.c_str(), pktHeader.lengthOfAdopterBio);
        offset += pktHeader.lengthOfAdopterBio;

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

    char* serializeDataForLogUpSellers(unsigned int* totalSize)
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

    /*
    * IMPORTANT: Call this function on both client and server to know what the receiving end
    * will be processing (what action the user wants to take). Failure to call this function
    * will result in enumeration issues with the packet header.
    */
    packetHeader deserializeDataForHeader(char** receivedData)
    {
        memcpy(&pktHeader, *receivedData, sizeof(packetHeader));

        return pktHeader;
    }

    loginInformation deserializeDataForLogin(char** receivedData)
    {
        /*
        * Below is an example of what I mean, you cannot deserialize the contents
        * of the packet without first revealing the necessary attributes from the
        * header to the program.
        * 
        * Remember to call this function and pass the parameter appropriately
        * for each use case, this will prevent many issues!
        */
        // Header is being deserialized in main.
        // deserializeDataForHeader(*(&receivedData));

        unsigned int offset = sizeof(packetHeader);
        loginInfo.username = std::string(*receivedData + offset, pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;
        loginInfo.hashedPassword = std::string(*receivedData + offset, pktHeader.lengthOfHashedPassword);

        return loginInfo;
    }

    logUpOwners deserializeDataForLogUpSellers(char** receivedData)
    {
        deserializeDataForHeader(*(&receivedData));

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

    logUpAdopters deserializeDataForAdopters(char** receivedData)
    {
        deserializeDataForHeader(*(&receivedData));

        unsigned int offset = sizeof(packetHeader);

        lUAdopters.firstName  = std::string(*receivedData + offset, pktHeader.lengthOfName);
        offset += pktHeader.lengthOfName;

        lUAdopters.lastName = std::string(*receivedData + offset, pktHeader.lengthOfLastName);
        offset += pktHeader.lengthOfLastName;

        lUAdopters.username = std::string(*receivedData + offset, pktHeader.lengthOfUsername);
        offset += pktHeader.lengthOfUsername;

        lUAdopters.hashedPassword = std::string(*receivedData + offset, pktHeader.lengthOfHashedPassword);
        offset += pktHeader.lengthOfHashedPassword;

        lUAdopters.userBio = std::string(*receivedData + offset, pktHeader.lengthOfAdopterBio);
        offset += pktHeader.lengthOfAdopterBio;

        return lUAdopters;
    }

    postParameters deserializeDataForPost(char** receivedData)
    {
        unsigned int offset = sizeof(packetHeader);
        postParams.postTitle = std::string(*receivedData + offset, pktHeader.lengthOfPostTitle);
        offset += pktHeader.lengthOfPostTitle;

        postParams.postContent = std::string(*receivedData + offset, pktHeader.lengthOfPostContent);
        offset += pktHeader.lengthOfPostContent;

        memcpy(postParams.imageBuffer, *receivedData + offset, pktHeader.sizeOfImageBuffer);

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
