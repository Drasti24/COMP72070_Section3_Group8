// All additional dependencies included within Packet header.
#include "Packet.h"


int main(void)
{
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
	connectionSocket = SOCKET_ERROR;

	// Accepting secondary client:
	SOCKET secondaryConnectionSocket;
	secondaryConnectionSocket = SOCKET_ERROR;
	
	if ((connectionSocket == accept(serverSocket, NULL, NULL)) == SOCKET_ERROR)
	{
		std::cout << "Cannot establish a connection with the client." << std::endl;
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}

	std::cout << "Primary client is connected. Waiting for secondary client." << std::endl;

	if ((secondaryConnectionSocket == accept(serverSocket, NULL, NULL)) == SOCKET_ERROR)
	{
		std::cout << "Cannot establish a connection with the client." << std::endl;
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}

	std::cout << "Second client has been successfully connected." << std::endl;

	std::cout << "Both clients are now properly connected." << std::endl;

	system("pause");

	char* RxBuffer = new char[1024];

	while (1)
	{
		/*
		* Sending and receiving code pending until creation
		* of packet has been completed.
		* 
		* Place send and receive calls here once packet is ready.
		*/
		recv(connectionSocket, RxBuffer, sizeof(RxBuffer), 0);
		enum requestType type = UNKNOWN;
		Packet receivedPacket;
		receivedPacket.deserializeDataForHeader(&RxBuffer);
		if (type == LOGIN_SUCCESS) {
			// function call.
		}
		else if (type == LOGIN_FAIL) {
			// function call.
		}
		else if (type == LOGIN_ACT) {
			
			receivedPacket.deserializeDataForLogin(&RxBuffer);
		}
		else if (type == LOGUP) {
			
			receivedPacket.deserializeDataForLogUp(&RxBuffer);
		}
		else if (type == POST) {
			receivedPacket.deserializeDataForPost(RxBuffer);
		}
	}
	closesocket(connectionSocket);
	closesocket(serverSocket);
	WSACleanup();

	return 0;
}