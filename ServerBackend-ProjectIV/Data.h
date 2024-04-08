#pragma once
#include "Packet.h"
#include <string>
/*
* Written by Salah Salame on Thursday, April 4th, 2024.
* "Data" will save data to a CSV file for recording usernames
* and passwords, along with user information.
* 
* It will also generate logs for system events, including
* sign in successes and failures.
*/

void csvFileCheck();
void writeLogInParams(Packet::loginInformation&);
void writeLogUpOwnersParams(Packet::logUpOwners&);
void writeLogUpAdoptersParams(Packet::logUpAdopters&);
void writeUserPosts(Packet::postParameters&);
void checkLoginparams(Packet::loginInformation&);

void checkLogInParams(Packet::loginInformation&, bool);