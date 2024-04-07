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

	std::cout << "Waiting for client connection." << std::endl;


	SOCKET connectionSocket;
	connectionSocket = SOCKET_ERROR;

	// Accepting client connection:
	if ((connectionSocket = accept(serverSocket, NULL, NULL)) == SOCKET_ERROR)
	{
		std::cout << "Cannot establish a connection with the client." << std::endl;
		std::cout << "Error code: " << WSAGetLastError() << std::endl; // Add this line for debugging
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}
	std::cout << "Client connected." << std::endl;

	// Assuming a maximum buffer size of 1024 bytes
	char* RxBuffer = new char[1024];

	memset(RxBuffer, 0, 1024);

	// Receive data from the client
	int bytesReceived = recv(connectionSocket, RxBuffer, 1024, 0);
	if (bytesReceived == SOCKET_ERROR)
	{
		std::cout << "Error receiving data from client." << std::endl;
		closesocket(connectionSocket);
		closesocket(serverSocket);
		WSACleanup();
		delete[] RxBuffer; // Free the memory allocated for RxBuffer
		return 0;
	}

	Packet::loginInformation login_params;

	Packet packet;

	login_params = packet.deserializeDataForLogin(&RxBuffer);

	std::cout << login_params.username << std::endl;
	std::cout << login_params.hashedPassword << std::endl;

	delete[] RxBuffer; // Free the memory allocated for RxBuffer


	return 0;
}