#pragma once
#include <iostream>
#include <fstream>
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

enum requestType { LOGIN_SUCCESS, LOGIN_FAIL, LOGIN_ACT, LOGUP, POST, UNKNOWN };
// UNKNOWN is used in main to first assess the type of request received from the client.


/*
* "Global" variable used to define the size of a phone number.
* Most phone numbers are 10 digits long. Information will be stored
* in the packet header.
*/
#define MAX_PHONE_NUM_DIGITS		10

class Packet
{
public:
	struct packetHeader
	{
		/*
		* The header tells the client everything it needs to
		* know to interpret the data. Each of the required attributes
		* will be initialized in a constructor according to client's request.
		*/
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
	}pktHeader;

	struct loginInformation
	{
		std::string username;
		std::string hashedPassword;
	}loginInfo;

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
	}lUOwners;

	struct petInformation
	{
		unsigned int animnalType;
		/*
		* 1 - cat.
		* 2 - dog.
		* 3 - both.
		*
		* A boolean was originally chosen for this, but as its values
		* can only be 1 or 0, it was changed to an unsigned int instead.
		*/
		bool vaccinationStatus; // 0 - yes, 1 - no.
		unsigned int age;
	}petInfo;

	struct postParameters
	{
		std::string postTitle;
		std::string postContent;
		char* imageBuffer = nullptr;  /* Will be initialized in constructor. Set as nullptr for safe state. */
	}postParams;

	char* bufferOfReceivedData = nullptr; /* Will be looked into tomorrow. */
	char* dataToBeSent = nullptr; /* Initialized to nullptr for safe state. */
	/*
	* The enums will be used to specify which data will be serialized and
	* sent through the socket.
	*/

	/*
	* Each of these constructors are used to initialize
	* various struct objects depending on what request is issued
	* by the user. Each has the necessary information that the header
	* needs in order to relay to the client, and the actual data itself
	* to be serialized.
	*
	* A default constructor must also be provided.
	*/
	Packet()
	{

	}

	Packet(std::string username, std::string hashedPassword)
	{
		this->loginInfo.username = username;
		this->loginInfo.hashedPassword = hashedPassword;
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

		this->petInfo.animnalType = animalType;
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

		this->pktHeader.animalTypeParam = sizeof(petInfo.animnalType);
		this->pktHeader.boolSize = sizeof(petInfo.vaccinationStatus);
		this->pktHeader.ageSize = sizeof(petInfo.age);

	}
	/*
	* Only uncomment this constructor if an owners' pet information may be modified
	* after loging up. Else, the constructor above (for loging up) will suffice.
	* Discuss with team.
	*/
	/*Packet(unsigned int animalType, bool vaccinationStatus, unsigned int age)
	{
		this->petInfo.animnalType = animalType;
		this->petInfo.vaccinationStatus = vaccinationStatus;
		this->petInfo.age = age;

		this->pktHeader.animalTypeParam = sizeof(petInfo.animnalType);
		this->pktHeader.boolSize = sizeof(petInfo.vaccinationStatus);
		this->pktHeader.ageSize = sizeof(petInfo.age);
	}*/

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
	~Packet()
	{
		if (this->postParams.imageBuffer != nullptr)
		{
			delete[] this->postParams.imageBuffer;
		}
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

	char* serializeDataForLogin(unsigned int totalSize, const loginInformation& login_params)
	{
		/*
		* If the buffer has been used, empty it to
		* create a new buffer to return.
		*
		* Done to prevent memory leaks and segmentation
		* faults (buffer overflows).
		*/
		if (dataToBeSent != nullptr)
		{
			delete[] dataToBeSent;
		}

		totalSize = sizeof(packetHeader) + pktHeader.lengthOfUsername + pktHeader.lengthOfHashedPassword;

		dataToBeSent = new char[totalSize];

		// Copy the packet header into the buffer
		memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));

		// Calculate the offset for the username and hashed password
		unsigned int offset = sizeof(packetHeader);

		// Copy the username into the buffer
		memcpy(dataToBeSent + offset, login_params.username.c_str(), pktHeader.lengthOfUsername);
		offset += pktHeader.lengthOfUsername;

		// Copy the hashed password into the buffer
		memcpy(dataToBeSent + offset, login_params.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);

		return dataToBeSent;
	}


	char* serializeDataForLogUp(unsigned int totalSize, const logUpOwners& logup_params, const petInformation& pet_params)
	{
		/*
		* If the buffer has been used, empty it to
		* create a new buffer to return.
		*
		* Done to prevent memory leaks and segmentation
		* faults (buffer overflows).
		*/
		if (dataToBeSent != nullptr)
		{
			delete[] dataToBeSent;
		}
		/*
		* The totalSize attribute initialization has been split into
		* three lines for better clarity and readibility.
		*/
		totalSize = sizeof(packetHeader);
		totalSize += pktHeader.lengthOfName + pktHeader.lengthOfLastName + pktHeader.lengthOfUsername;
		totalSize += pktHeader.lengthOfHashedPassword + pktHeader.lengthOfBusinessAddress + pktHeader.lengthOfPostalCode;
		totalSize += pktHeader.digitsInPhoneNumber + pktHeader.licenseNumberSize;
		/*
		* totalSize now includes the information pertaining to users who want to sign up.
		* Now, it will be appended to the information needed to provide information
		* about a pet.
		*/
		totalSize += pktHeader.animalTypeParam + pktHeader.boolSize + pktHeader.ageSize;

		dataToBeSent = new char[totalSize];
		/*
		* Since we will need lots of copying into the buffer, the memory copy statements would be too long
		* to manually set the offset. Instead, a variable will be used to offset the data to its right
		* location in memory, and will be updated with each statement.
		*
		* Variable is initialized to 0 to avoid code smells.
		*/
		unsigned int offset = 0;
		memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
		offset += sizeof(packetHeader);

		memcpy(dataToBeSent + offset, logup_params.firstName.c_str(), pktHeader.lengthOfName);
		offset += pktHeader.lengthOfName;

		memcpy(dataToBeSent + offset, logup_params.lastName.c_str(), pktHeader.lengthOfLastName);
		offset += pktHeader.lengthOfLastName;

		memcpy(dataToBeSent + offset, logup_params.username.c_str(), pktHeader.lengthOfUsername);
		offset += pktHeader.lengthOfUsername;

		memcpy(dataToBeSent + offset, logup_params.hashedPassword.c_str(), pktHeader.lengthOfHashedPassword);
		offset += pktHeader.lengthOfHashedPassword;

		memcpy(dataToBeSent + offset, logup_params.businessAddress.c_str(), pktHeader.lengthOfBusinessAddress);
		offset += pktHeader.lengthOfBusinessAddress;

		memcpy(dataToBeSent + offset, logup_params.province.c_str(), pktHeader.lengthOfProvince);
		offset += pktHeader.lengthOfProvince;

		memcpy(dataToBeSent + offset, logup_params.postalCode.c_str(), pktHeader.lengthOfPostalCode);
		offset += pktHeader.lengthOfPostalCode;

		memcpy(dataToBeSent + offset, &logup_params.businessPhone, pktHeader.digitsInPhoneNumber);
		offset += pktHeader.digitsInPhoneNumber;

		memcpy(dataToBeSent + offset, &logup_params.licenseNumber, pktHeader.licenseNumberSize);
		offset += pktHeader.licenseNumberSize;

		memcpy(dataToBeSent + offset, &pet_params.animnalType, pktHeader.animalTypeParam);
		offset += pktHeader.animalTypeParam;

		memcpy(dataToBeSent + offset, &pet_params.vaccinationStatus, pktHeader.boolSize);
		offset += pktHeader.boolSize;

		memcpy(dataToBeSent + offset, &pet_params.age, pktHeader.ageSize);
		offset += pktHeader.ageSize;
		/*
		* This buffer now includes all necessary information for a user to sign up.
		* It complies with providing basic PII (Personally Identifiable Information),
		* plus the information needed for a pet.
		*/
		return dataToBeSent;
	}

	char* serializeDataForPost(unsigned int totalSize, const postParameters& post_params)
	{
		/*
		* If the buffer has been used, empty it to
		* create a new buffer to return.
		*
		* Done to prevent memory leaks and segmentation
		* faults (buffer overflows).
		*/
		if (dataToBeSent != nullptr)
		{
			delete[] dataToBeSent;
		}
		/*
		* The totalSize attribute initialization has been split into
		* three lines for better clarity and readibility.
		*/
		totalSize = sizeof(packetHeader) + pktHeader.lengthOfPostTitle + pktHeader.lengthOfPostContent;
		totalSize += pktHeader.sizeOfImageBuffer;

		dataToBeSent = new char[totalSize];

		unsigned int offset = 0;
		memcpy(dataToBeSent, &pktHeader, sizeof(packetHeader));
		offset += sizeof(packetHeader);

		memcpy(dataToBeSent + offset, post_params.postTitle.c_str(), pktHeader.lengthOfPostTitle);
		offset += pktHeader.lengthOfPostTitle;

		memcpy(dataToBeSent + offset, post_params.postContent.c_str(), pktHeader.lengthOfPostContent);
		offset += pktHeader.lengthOfPostContent;

		memcpy(dataToBeSent + offset, post_params.imageBuffer, pktHeader.sizeOfImageBuffer);
		offset += pktHeader.sizeOfImageBuffer;

		return dataToBeSent;
	}

	loginInformation& deserializeDataForLogin(char* receivedData)
	{
		/*
		* Data deserialization is the opposite of serialization.
		* For all structures of data that we serialized we must also
		* deserialize them for proper interpretation from both ends.
		*/
		loginInformation loginAttemptParams;
		/*
		* Just like in serialization, we must now copy the buffer of received data
		* into the struct object that we wish to create, then return back to the
		* calling (parent) function.
		*/
		unsigned int offset = sizeof(packetHeader);

		memcpy(&loginAttemptParams.username, receivedData + offset, pktHeader.lengthOfUsername);
		offset += pktHeader.lengthOfUsername;

		memcpy(&loginAttemptParams.hashedPassword, receivedData + offset, pktHeader.lengthOfHashedPassword);
		offset += pktHeader.lengthOfHashedPassword;
		/*
		* At this point, the structure of data has been created and the data has been
		* successfully retreived from the buffer. Now, we need to free the buffer's
		* memory to avoid segmentation faults (buffer overflows).
		*/
		delete[] receivedData;
		/*
		* Structure of data is returned back to its parent function.
		*/
		return loginAttemptParams;
	}

	logUpOwners& deserializeDataForLogUp(char* receivedData)
	{
		/*
		* Data deserialization is the opposite of serialization.
		* For all structures of data that we serialized we must also
		* deserialize them for proper interpretation from both ends.
		*/
		logUpOwners newOwner;
		/*
		* Just like in serialization, we must now copy the buffer of received data
		* into the struct object that we wish to create, then return back to the
		* calling (parent) function.
		*/
		unsigned int offset = sizeof(packetHeader);

		memcpy(&newOwner.firstName, receivedData + offset, pktHeader.lengthOfName);
		offset += pktHeader.lengthOfName;

		memcpy(&newOwner.lastName, receivedData + offset, pktHeader.lengthOfLastName);
		offset += pktHeader.lengthOfLastName;

		memcpy(&newOwner.username, receivedData + offset, pktHeader.lengthOfUsername);
		offset += pktHeader.lengthOfUsername;

		memcpy(&newOwner.hashedPassword, receivedData + offset, pktHeader.lengthOfHashedPassword);
		offset += pktHeader.lengthOfHashedPassword;

		memcpy(&newOwner.businessAddress, receivedData + offset, pktHeader.lengthOfBusinessAddress);
		offset += pktHeader.lengthOfBusinessAddress;

		memcpy(&newOwner.province, receivedData + offset, pktHeader.lengthOfProvince);
		offset += pktHeader.lengthOfProvince;

		memcpy(&newOwner.postalCode, receivedData + offset, pktHeader.lengthOfPostalCode);
		offset += pktHeader.lengthOfPostalCode;

		memcpy(&newOwner.businessPhone, receivedData + offset, pktHeader.digitsInPhoneNumber);
		offset += pktHeader.digitsInPhoneNumber;

		memcpy(&newOwner.licenseNumber, receivedData + offset, pktHeader.licenseNumberSize);
		offset += pktHeader.licenseNumberSize;
		/*
		* At this point, the structure of data has been created and the data has been
		* successfully retreived from the buffer. Now, we need to free the buffer's
		* memory to avoid segmentation faults (buffer overflows).
		*/
		delete[] receivedData;
		/*
		* Structure of data is returned back to its parent function.
		*/
		return newOwner;
	}


	postParameters& deserializeDataForPost(char* receivedData)
	{
		/*
		* Data deserialization is the opposite of serialization.
		* For all structures of data that we serialized we must also
		* deserialize them for proper interpretation from both ends.
		*/

		postParameters newPost;
		/*
		* Just like in serialization, we must now copy the buffer of received data
		* into the struct object that we wish to create, then return back to the
		* calling (parent) function.
		*/
		unsigned int offset = sizeof(packetHeader);
		/*
		* The offset is set to be equal to the packet header since we do not wish
		* to copy the header into the struct, so we need to offset starting from
		* the header, then make our way into the data, and copy it into the struct.
		*/
		memcpy(&newPost.postTitle, receivedData + offset, pktHeader.lengthOfPostTitle);
		/*  memcpy(&newPost.postTitle, receivedData + offset, pktHeader.lengthOfPostTitle); Ask about this approach. */
		offset += pktHeader.lengthOfPostTitle;

		memcpy(&newPost.postContent, receivedData + offset, pktHeader.lengthOfPostContent);
		offset += pktHeader.lengthOfPostContent;

		memcpy(&newPost.imageBuffer, receivedData + offset, pktHeader.sizeOfImageBuffer);
		/*
		* Space still remains in the buffer for pet information. The buffer cannot be freed
		* before that information is saved and deserialized, else the server would suffer from
		* data loss, and we do not need this.
		*
		* To mitigate, I chose to write a separate function that takes the buffer of remaining data,
		* and creates a struct "object" for pet information, returns it back to the calling function,
		* then subsequently frees the buffer.
		*
		* Nothing should remain inside it after this.
		*/
		deserializeDataForPetInformation(offset, receivedData);
		/*
		* At this point, the structure of data has been created and the data has been
		* successfully retreived from the buffer. Now, we need to free the buffer's
		* memory to avoid segmentation faults (buffer overflows).
		*/
		delete[] receivedData;
		/*
		* Structure of data is returned back to its parent function.
		*/
		return newPost;
	}

	petInformation& deserializeDataForPetInformation(unsigned int offset, char* receivedData)
	{
		/*
		* The purpose of this function is to deserialize the remainder
		* of data buffer (receivedData) after log up parameters have
		* been extracted.
		*
		* NOTE: The buffer is NOT freed in this function, since this function
		* is only called from the "parent" deserialize function, the buffer
		* is freed there.
		*
		* The remaining offset is passed to this function.
		*/

		petInformation myPet;

		memcpy(&myPet.animnalType, receivedData + offset, pktHeader.animalTypeParam);
		offset += pktHeader.animalTypeParam;

		memcpy(&myPet.vaccinationStatus, receivedData + offset, pktHeader.boolSize);
		offset += pktHeader.boolSize;

		memcpy(&myPet.age, receivedData + offset, pktHeader.ageSize);
		offset += pktHeader.ageSize;

		return myPet;
	}
};
