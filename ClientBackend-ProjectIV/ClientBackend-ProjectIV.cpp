#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <string>
#include "Packet.h"

int main(int argc, char* argv[])
{

	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return -1;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return -1;
	}

	std::cout << "Attempting connection..." << std::endl;

	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address

	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		std::cout << "Cannot connect to the server." << std::endl;
		closesocket(ClientSocket);
		WSACleanup();
		return 0;
	}

	std::cout << "Connection to server established." << std::endl;

	Packet loginParams("user1", "dba2");

	unsigned int totalSize = 0;
	char* TxBuffer = loginParams.serializeDataForLogin(&totalSize);

	int sendSize = send(ClientSocket, TxBuffer, totalSize, 0);

	// std::cout << sendSize << std::endl; Added for debugging.

	// Remember to free memory after use
	// delete[] TxBuffer;

	closesocket(ClientSocket);
	WSACleanup();


	return 1;
}
