#include "ServerLogs.h"

/*
* Written by Drasti Patel & Salah Salame.
*
* This is the implementation of "ServerLogs.h".
*/

void logFileCheck()
{
	std::ifstream myLogFile("Logs.txt");
	if (!myLogFile)
	{
		std::cout << "Log file non existant. Creating new log file." << std::endl;
		std::fstream myLogFileNew("Logs.txt");
	}
}

void writeLogInStats(Packet::loginInformation& login_params)
{
	std::ofstream myLogFile("Logs.txt", std::ios::app);

	myLogFile << "Attempted log in by user." << std::endl;
	myLogFile << "Username: " << login_params.username << std::endl;
	myLogFile << "Password: " << login_params.hashedPassword << std::endl;

}