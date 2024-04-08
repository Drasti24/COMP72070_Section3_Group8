#include "Data.h"
/*
* Written by Salah Salame on Thursday, April 4th, 2024.
* 
* This is the implementation of "Data.h".
*/

void csvFileCheck()
{
	std::ifstream myFile("Data.csv");
	if (!myFile) 
	{ 
		std::cout << "Cannot open the file." << std::endl;
		std::fstream myFile("Data.csv");
	}

	std::cout << "File loaded successfully." << std::endl;
	myFile.close();
}

void writeLogInParams(Packet::loginInformation& loginParams)
{
	std::ofstream myFile("Data.csv", std::ios::app); /* File needs to be opened in append mode. */

	myFile << ",,";

	myFile << loginParams.username << ',' << loginParams.hashedPassword << std::endl;

	myFile.close();

}

void writeLogUpOwnersParams(Packet::logUpOwners& lUOwnersParams)
{
	std::ofstream myFile("Data.csv", std::ios::app);

	myFile << lUOwnersParams.firstName << ',' << lUOwnersParams.lastName << ',';
	myFile << lUOwnersParams.username << ',' << lUOwnersParams.hashedPassword << ',';
	myFile << lUOwnersParams.businessAddress << ',' << lUOwnersParams.province << ',';
	myFile << lUOwnersParams.postalCode << ',' << lUOwnersParams.businessPhone << ',';
	myFile << lUOwnersParams.licenseNumber;

	myFile.close();
}

void writeLogUpAdoptersParams(Packet::logUpAdopters& lUAdoptersParams)
{
	std::ofstream myFile("Data.csv", std::ios::app);

	myFile << lUAdoptersParams.firstName << ',' << lUAdoptersParams.lastName << ',';
	myFile << lUAdoptersParams.username << ',' << lUAdoptersParams.hashedPassword << ',';
	myFile << lUAdoptersParams.userBio << ',';

	myFile.close();
}

void writeUserPosts(Packet::postParameters& postParams)
{
	std::ofstream myFile("Data.csv", std::ios::app);

	myFile << postParams.postTitle << ',' << postParams.postContent << ',';
	myFile << postParams.imageBuffer << ',';

	myFile.close();

}

void checkLogInParams(Packet::loginInformation& loginParams, bool logInState)
{
	std::ifstream myFile("Data.csv");
	std::string line;

	while (std::getline(myFile, line, ','))
	{
		if (strcmp(line.c_str(), loginParams.username.c_str()))
		{
			std::getline(myFile, line, ',');
			/*
			* If the username exists, it should go to the
			* next column to see if the password stored
			* next to it matches.
			* 
			* This is what this logic is supposed to do.
			*/
			if (strcmp(line.c_str(), loginParams.hashedPassword.c_str()))
			{
				logInState = true;

				std::cout << "Credentials match!" << std::endl;
				break;
			}
		}
		else
		{
			/*
			* Whether or not the user credentials match,
			* the header will contain result from
			* evaluation.
			*/
			std::cout << "Credentials don't match/exist!" << std::endl;
			break;
		}
	}
}

