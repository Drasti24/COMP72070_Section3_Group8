// All additional dependencies included within Packet header.
#include "Packet.h"
#include "Data.h"
#include "ServerLogs.h"


int main(void)
{
    /*
    * File must be validated
    * before the server starts, as it is
    * imperative to read/write to the "database".
    */
    csvFileCheck();

    /*
    * Server logs are always written to
    * when new events take place.
    * 
    * Need to perform file validation
    * before server starts, as it is
    * imperative to store these events.
    */

    logFileCheck();

 

    // Initializing Windows DLLs;
    WSADATA wsaData;
    if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        return -1;
    }

    // Initialize the necessary sockets.
    SOCKET serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        WSACleanup();
        return -1;
    }

    // Binding the socket:
    sockaddr_in svrAddr;
    svrAddr.sin_family = AF_INET;
    svrAddr.sin_addr.s_addr = INADDR_ANY;
    svrAddr.sin_port = htons(27000);
    if (bind(serverSocket, (struct sockaddr*)&svrAddr, sizeof(svrAddr)) == SOCKET_ERROR)
    {
        std::cout << "Cannot bind server socket." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    // Listen for incoming connections.
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "Error listening on server socket." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    std::cout << "Waiting for primary client connection." << std::endl;

    // Accepting client connection:
    SOCKET connectionSocket;
    connectionSocket = accept(serverSocket, NULL, NULL); // Corrected to remove redundant SOCKET_ERROR check

    if (connectionSocket == INVALID_SOCKET)
    {
        std::cout << "Cannot establish a connection with the client." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 0;
    }

    std::cout << "Primary client is connected." << std::endl;

    char* RxBuffer = new char[1024];

    // Used to assess whether credentials are right are wrong.
    bool logInState = false;

    unsigned int totalSize = 0;

    while (1)
    {
        size_t bytesReceived = recv(connectionSocket, RxBuffer, 1024, 0);

        Packet receivedPacket;
        receivedPacket.deserializeDataForHeader(&RxBuffer);
        enum requestType type = receivedPacket.getRequestType();
 
        if (type == LOGIN_ACT)
        {
            Packet::loginInformation loginInfo = receivedPacket.deserializeDataForLogin(&RxBuffer);
            writeLogInStats(loginInfo);
            // Check whether user exists, or credentials match.
            checkLogInParams(loginInfo, logInState);

            if (logInState == true)
            {
                Packet logInSuccess(logInState, LOGIN_SUCCESS);
                RxBuffer = logInSuccess.serializeDataForLogInState(&totalSize);
                send(connectionSocket, RxBuffer, totalSize, 0);
            }
            else
            {
                Packet logInFailure(logInState, LOGIN_FAIL);
                RxBuffer = logInFailure.serializeDataForLogInState(&totalSize);
                send(connectionSocket, RxBuffer, totalSize, 0);
            }
        }
        if (type == LOGUP_ADOPTER)
        {
            Packet::logUpAdopters logupAdoptersInfo = receivedPacket.deserializeDataForAdopters(&RxBuffer);

        }
        if (type == LOGUP_SELLER)
        {
            Packet::logUpOwners logUpOwnersInfo = receivedPacket.deserializeDataForLogUpSellers(&RxBuffer);
        }
        if (type == POST)
        {
            Packet::postParameters postParamsInfo = receivedPacket.deserializeDataForPost(&RxBuffer);
        }
    }

    delete[] RxBuffer;


    closesocket(connectionSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
