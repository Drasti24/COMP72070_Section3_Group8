#include "pch.h"
#include "CppUnitTest.h"
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")


#include "../ServerBackend-ProjectIV/Packet.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ServerBackendProjectIVTest
{
    TEST_CLASS(socketTesting)
    {
    public:

        TEST_METHOD(TestSocketCreation)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }

        TEST_METHOD(TestSocketBinding)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Bind the socket
            sockaddr_in svrAddr;
            svrAddr.sin_family = AF_INET;
            svrAddr.sin_addr.s_addr = INADDR_ANY;
            svrAddr.sin_port = htons(27000);
            result = bind(serverSocket, (struct sockaddr*)&svrAddr, sizeof(svrAddr));
            Assert::AreEqual(result, 0, L"Socket binding failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }

        TEST_METHOD(TestSocketListening)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Bind the socket
            sockaddr_in svrAddr;
            svrAddr.sin_family = AF_INET;
            svrAddr.sin_addr.s_addr = INADDR_ANY;
            svrAddr.sin_port = htons(27000);
            result = bind(serverSocket, (struct sockaddr*)&svrAddr, sizeof(svrAddr));
            Assert::AreEqual(result, 0, L"Socket binding failed");

            // Listen on the socket
            result = listen(serverSocket, SOMAXCONN);
            Assert::AreEqual(result, 0, L"Socket listening failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }

        TEST_METHOD(TestSocketAccepting)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Accept a connection (this will fail because there's no client, but we're testing the function call)
            SOCKET connectionSocket = accept(serverSocket, NULL, NULL);
            Assert::IsTrue(connectionSocket == SOCKET_ERROR, L"Socket accepting failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }

        TEST_METHOD(TestSocketSending)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Send data (this will fail because there's no client, but we're testing the function call)
            const char* data = "test";
            result = send(serverSocket, data, strlen(data), 0);
            Assert::AreEqual(result, SOCKET_ERROR, L"Socket sending failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }

        TEST_METHOD(TestSocketReceiving)
        {
            // Initialize Windows DLLs;
            WSADATA wsaData;
            int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
            Assert::AreEqual(result, 0, L"WSAStartup failed");

            // Create a socket
            SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            Assert::IsTrue(serverSocket != INVALID_SOCKET, L"Socket creation failed");

            // Receive data (this will fail because there's no client, but we're testing the function call)
            char buffer[1024];
            result = recv(serverSocket, buffer, sizeof(buffer), 0);
            Assert::AreEqual(result, SOCKET_ERROR, L"Socket receiving failed");

            // Clean up
            closesocket(serverSocket);
            WSACleanup();
        }
    };

    TEST_CLASS(dataTesting)
    {
    public:

        TEST_METHOD(TestSerializeDataForLogin)
        {
            // Create a Packet object
            Packet packet("user1", "password");
            // Call the function to serialize the data
            unsigned int totalSize = 0;
            char* serializedData = packet.serializeDataForLogin(&totalSize);
            // Check the serialized data
            Assert::IsNotNull(serializedData, L"Serialized data is null");
            // Check the total size
            unsigned int expectedTotalSize = sizeof(Packet::packetHeader) + packet.pktHeader.lengthOfUsername + packet.pktHeader.lengthOfHashedPassword;
            Assert::AreEqual(totalSize, expectedTotalSize, L"Total size is incorrect");
            // Clean up
            delete[] serializedData;
        }

        //TEST_METHOD(TestDeserializeDataForPetInformation)
        //{
        //    // Create a petInformation object
        //    Packet::petInformation originalPet;
        //    originalPet.animalType = 1; // Set to a known value
        //    originalPet.vaccinationStatus = true; // Set to a known value
        //    originalPet.age = 5; // Set to a known value

        //    // Serialize the petInformation object into a buffer
        //    unsigned int totalSize = sizeof(originalPet.animalType) + sizeof(originalPet.vaccinationStatus) + sizeof(originalPet.age);
        //    char* serializedData = new char[totalSize];
        //    unsigned int offset = 0;
        //    memcpy(serializedData + offset, &originalPet.animalType, sizeof(originalPet.animalType));
        //    offset += sizeof(originalPet.animalType);
        //    memcpy(serializedData + offset, &originalPet.vaccinationStatus, sizeof(originalPet.vaccinationStatus));
        //    offset += sizeof(originalPet.vaccinationStatus);
        //    memcpy(serializedData + offset, &originalPet.age, sizeof(originalPet.age));

        //    // Call the function to deserialize the data
        //    Packet packet; // Create a Packet object
        //    offset = 0; // Reset offset
        //    Packet::petInformation deserializedPet = packet.deserializeDataForPetInformation(&serializedData);

        //    // Check the deserialized petInformation object
        //    Assert::AreEqual((int)originalPet.animalType, (int)deserializedPet.animalType, L"Animal type is incorrect");
        //    Assert::AreEqual(originalPet.vaccinationStatus, deserializedPet.vaccinationStatus, L"Vaccination status is incorrect");
        //    Assert::AreEqual((int)originalPet.age, (int)deserializedPet.age, L"Age is incorrect");

        //    // Clean up
        //    delete[] serializedData;
        //}

        TEST_METHOD(TestSerializeDataForLogUpAdopters)
        {
            // Initialize the Packet object with mock data
            Packet packet("Jane", "Doe", "janedoe", "hashedpassword123", "Bio of Jane Doe");

            // Call the function to serialize the logUpAdopters data
            unsigned int totalSize = 0;
            char* serializedData = packet.serializeDataForLogUpAdopters(&totalSize);

            // Check the serialized data is not null
            Assert::IsNotNull(serializedData, L"Serialized data is null");

            // Calculate the expected total size for comparison
            unsigned int expectedTotalSize = sizeof(Packet::packetHeader)
                + packet.pktHeader.lengthOfName
                + packet.pktHeader.lengthOfLastName
                + packet.pktHeader.lengthOfUsername
                + packet.pktHeader.lengthOfHashedPassword
                + packet.pktHeader.lengthOfAdopterBio;

            // Check the total size is as expected
            Assert::AreEqual(totalSize, expectedTotalSize, L"Total size is incorrect");

            // Clean up the dynamically allocated memory to prevent memory leak
            delete[] serializedData;
        }

        TEST_METHOD(TestSerializeDataForPetInformation)
        {
            // Initialize the Packet object with mock pet information
            unsigned int animalType = 1; // Assuming 1 represents a specific animal type, e.g., cat
            bool vaccinationStatus = true;
            unsigned int age = 5; // Assuming age in years

            Packet packet;
            packet.petInfo.animalType = animalType;
            packet.petInfo.vaccinationStatus = vaccinationStatus;
            packet.petInfo.age = age;

            // Mocking packet header details relevant to pet information
            packet.pktHeader.animalTypeParam = sizeof(animalType);
            packet.pktHeader.boolSize = sizeof(vaccinationStatus);
            packet.pktHeader.ageSize = sizeof(age);

            // Call the function to serialize the pet information data
            unsigned int totalSize = 0;
            char* serializedData = packet.serializeDataForPetInformation(&totalSize);

            // Check the serialized data is not null
            Assert::IsNotNull(serializedData, L"Serialized data is null");

            // Calculate the expected total size for comparison
            unsigned int expectedTotalSize = sizeof(Packet::packetHeader)
                + packet.pktHeader.animalTypeParam
                + packet.pktHeader.boolSize
                + packet.pktHeader.ageSize;

            // Check the total size is as expected
            Assert::AreEqual(totalSize, expectedTotalSize, L"Total size is incorrect");

            // Additional checks could be made here to verify the contents of the serialized data.
            // This would involve casting back to the respective types and comparing against the original values.
            // Example for animalType (and similarly for vaccinationStatus and age):
            unsigned int deserializedAnimalType;
            memcpy(&deserializedAnimalType, serializedData + sizeof(Packet::packetHeader), sizeof(animalType));
            Assert::AreEqual(animalType, deserializedAnimalType, L"Deserialized animal type is incorrect");

            // Clean up the dynamically allocated memory to prevent memory leaks
            delete[] serializedData;
        }

        TEST_METHOD(TestSerializeDataForLogUpSellers)
        {
            // Initialize the Packet object with mock logUpSellers data
            Packet packet(
                "John", // firstName
                "Doe", // lastName
                "johndoe", // username
                "hashedpassword123", // hashedPassword
                "123 Main St", // businessAddress
                "Ontario", // province
                "A1B2C3", // postalCode
                1234567890, // businessPhone
                123456, // licenseNumber
                1, // animalType
                true, // vaccinationStatus
                5 // age
            );

            // Setup packet header lengths based on the mock data
            packet.pktHeader.lengthOfName = strlen("John");
            packet.pktHeader.lengthOfLastName = strlen("Doe");
            packet.pktHeader.lengthOfUsername = strlen("johndoe");
            packet.pktHeader.lengthOfHashedPassword = strlen("hashedpassword123");
            packet.pktHeader.lengthOfBusinessAddress = strlen("123 Main St");
            packet.pktHeader.lengthOfProvince = strlen("Ontario");
            packet.pktHeader.lengthOfPostalCode = strlen("A1B2C3");
            packet.pktHeader.digitsInPhoneNumber = sizeof(unsigned long int); // Assuming size of phone number
            packet.pktHeader.licenseNumberSize = sizeof(unsigned int); // Assuming size of license number
            packet.pktHeader.animalTypeParam = sizeof(unsigned int);
            packet.pktHeader.boolSize = sizeof(bool);
            packet.pktHeader.ageSize = sizeof(unsigned int);

            // Call the function to serialize the logUpSellers data
            unsigned int totalSize = 0;
            char* serializedData = packet.serializeDataForLogUpSellers(&totalSize);

            // Check the serialized data is not null
            Assert::IsNotNull(serializedData, L"Serialized data is null");

            // Calculate the expected total size for comparison
            unsigned int expectedTotalSize = sizeof(Packet::packetHeader)
                + packet.pktHeader.lengthOfName
                + packet.pktHeader.lengthOfLastName
                + packet.pktHeader.lengthOfUsername
                + packet.pktHeader.lengthOfHashedPassword
                + packet.pktHeader.lengthOfBusinessAddress
                + packet.pktHeader.lengthOfProvince
                + packet.pktHeader.lengthOfPostalCode
                + packet.pktHeader.digitsInPhoneNumber
                + packet.pktHeader.licenseNumberSize
                + packet.pktHeader.animalTypeParam
                + packet.pktHeader.boolSize
                + packet.pktHeader.ageSize;

            // Check the total size is as expected
            Assert::AreEqual(totalSize, expectedTotalSize, L"Total size is incorrect");

            // Additional checks could be made here to verify the contents of the serialized data.

            // Clean up the dynamically allocated memory to prevent memory leaks
            delete[] serializedData;
        }

        TEST_METHOD(TestSerializeDataForPost)
        {
            // Arrange
            std::string title = "Test Post";
            std::string content = "This is a test post.";
            char imageBuffer[] = "FakeImageContent"; // Mock image content
            size_t imageSize = sizeof(imageBuffer);
            Packet packet(title, content, imageBuffer);
            unsigned int totalSize = 0;

            // Act
            char* serializedData = packet.serializeDataForPost(&totalSize);

            // Assert
            Assert::IsNotNull(serializedData);
            unsigned int expectedSize = sizeof(Packet::packetHeader) + title.length() + content.length() + imageSize;
            Assert::AreEqual(expectedSize, totalSize);

            // Verify specific content if necessary
            // For example, to check if the first part of the serialized data matches the post title
            std::string serializedTitle(serializedData + sizeof(Packet::packetHeader), title.length());
            Assert::AreEqual(title, serializedTitle);

            // Cleanup
            delete[] serializedData;
        }

        TEST_METHOD(MethodInitialize)
        {
            // This method runs before each test method
            // Ensure a clean environment, e.g., by deleting the test file if it exists
            std::remove("Data_Test.csv");
        }

        TEST_METHOD_CLEANUP(MethodCleanup)
        {
            // This method runs after each test method
            // Clean up any resources, files, etc., used during the tests
            std::remove("Data_Test.csv");
        }

        TEST_METHOD(DeserializeHeader)
        {
            // Mock data for packetHeader
            Packet::packetHeader mockHeader;
            mockHeader.sourceAddr = 1;
            mockHeader.destAddr = 2;
            mockHeader.reqType = LOGIN_SUCCESS;
            mockHeader.lengthOfUsername = 8; // Example length for "username"

            // Simulate receiving the data as a char array
            char* mockData = new char[sizeof(Packet::packetHeader)];
            memcpy(mockData, &mockHeader, sizeof(Packet::packetHeader));

            // Deserialize
            Packet packet;
            Packet::packetHeader deserializedHeader = packet.deserializeDataForHeader(&mockData);

            // Assert
            Assert::AreEqual((int)mockHeader.sourceAddr, (int)deserializedHeader.sourceAddr);
            Assert::AreEqual((int)mockHeader.destAddr, (int)deserializedHeader.destAddr);
            Assert::AreEqual((int)mockHeader.reqType, (int)deserializedHeader.reqType);
            Assert::AreEqual(mockHeader.lengthOfUsername, deserializedHeader.lengthOfUsername);

            delete[] mockData;
        }

        TEST_METHOD(DeserializePetInformation_TrueNegative)
        {
            Packet packet;
            Packet::petInformation originalPet;
            originalPet.animalType = 1; // Known correct value
            originalPet.vaccinationStatus = true; // Known correct value
            originalPet.age = 5; // Known correct value

            // Serialize correctly first
            unsigned int totalSize;
            char* serializedData = packet.serializeDataForPetInformation(&totalSize);

            // Intentionally corrupt the serialized data to simulate a failure scenario
            // Example: Alter the animalType in the serialized data to an unexpected value
            if (totalSize > sizeof(packet) + sizeof(originalPet.animalType)) {
                *(reinterpret_cast<unsigned int*>(serializedData + sizeof(packet))) = 999; // Incorrect animal type
            }

            // Attempt to deserialize the corrupted data
            Packet::petInformation deserializedPet;
            char* dataPointer = serializedData; // Assuming deserialization method starts reading from this pointer
            try {
                deserializedPet = packet.deserializeDataForPetInformation(&dataPointer);

                // Check if the deserialized data matches the corrupted value, which it shouldn't for a true negative test
                Assert::AreNotEqual(999, (int)deserializedPet.animalType, L"Deserialized incorrect animal type successfully, expected failure.");

            }
            catch (std::exception& e) {
                // If your deserialization method throws exceptions on failures, you can catch them here as a part of the true negative test
                Logger::WriteMessage(e.what()); // Log the error message
                // Pass the test if an exception is expected behavior for corrupted data
            }

            // Clean up
            delete[] serializedData;
        }


    };
}
