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

        TEST_METHOD(TestDeserializeDataForPetInformation)
        {
            // Create a petInformation object
            Packet::petInformation originalPet;
            originalPet.animalType = 1; // Set to a known value
            originalPet.vaccinationStatus = true; // Set to a known value
            originalPet.age = 5; // Set to a known value

            // Serialize the petInformation object into a buffer
            unsigned int totalSize = sizeof(originalPet.animalType) + sizeof(originalPet.vaccinationStatus) + sizeof(originalPet.age);
            char* serializedData = new char[totalSize];
            unsigned int offset = 0;
            memcpy(serializedData + offset, &originalPet.animalType, sizeof(originalPet.animalType));
            offset += sizeof(originalPet.animalType);
            memcpy(serializedData + offset, &originalPet.vaccinationStatus, sizeof(originalPet.vaccinationStatus));
            offset += sizeof(originalPet.vaccinationStatus);
            memcpy(serializedData + offset, &originalPet.age, sizeof(originalPet.age));

            // Call the function to deserialize the data
            Packet packet; // Create a Packet object
            offset = 0; // Reset offset
            Packet::petInformation deserializedPet = packet.deserializeDataForPetInformation(&serializedData);

            // Check the deserialized petInformation object
            Assert::AreEqual((int)originalPet.animalType, (int)deserializedPet.animalType, L"Animal type is incorrect");
            Assert::AreEqual(originalPet.vaccinationStatus, deserializedPet.vaccinationStatus, L"Vaccination status is incorrect");
            Assert::AreEqual((int)originalPet.age, (int)deserializedPet.age, L"Age is incorrect");

            // Clean up
            delete[] serializedData;
        }

    };
}
