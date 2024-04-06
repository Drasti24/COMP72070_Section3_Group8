// #include "ClientNetworking.h"
// #include <qglobal.h>
// #include <cstring> // For std::memcpy
// #ifdef Q_OS_WIN // Check if compiling for Windows
// #include <windows.networking.sockets.h>
// #endif
// #pragma comment(lib, "Ws2_32.lib")

// Packet::Packet() : bufferOfReceivedData(nullptr), dataToBeSent(nullptr) {
//     // Initialize your Packet class as needed
// }

// Packet::~Packet() {
//     delete[] dataToBeSent;
//     delete[] bufferOfReceivedData;
// }

// char* Packet::serializeDataForLogin(unsigned int totalSize, struct loginInformation& login_params) {
//     // Calculate the total size
//     totalSize = sizeof(packetHeader) + login_params.username.size() + login_params.hashedPassword.size();

//     delete[] dataToBeSent;
//     dataToBeSent = new char[totalSize];

//     unsigned int offset = 0;

//     // Start with the packet header
//     std::memcpy(dataToBeSent + offset, &pktHeader, sizeof(packetHeader));
//     offset += sizeof(packetHeader);

//     // Copy username
//     std::memcpy(dataToBeSent + offset, login_params.username.c_str(), login_params.username.size());
//     offset += login_params.username.size();

//     // Copy hashed password
//     std::memcpy(dataToBeSent + offset, login_params.hashedPassword.c_str(), login_params.hashedPassword.size());
//     offset += login_params.hashedPassword.size();

//     return dataToBeSent;
// }

// char* Packet::serializeDataForLogUp(unsigned int totalSize, const logUpOwners& logup_params, const petInformation& pet_params) {
//     // Properly calculate totalSize based on the content lengths
//     totalSize = sizeof(packetHeader) +
//                 logup_params.firstName.size() +
//                 logup_params.lastName.size() +
//                 logup_params.username.size() +
//                 logup_params.hashedPassword.size() +
//                 logup_params.businessAddress.size() +
//                 logup_params.province.size() +
//                 logup_params.postalCode.size() +
//                 sizeof(logup_params.businessPhone) +
//                 sizeof(logup_params.licenseNumber) +
//                 sizeof(pet_params.animnalType) +
//                 sizeof(pet_params.vaccinationStatus) +
//                 sizeof(pet_params.age);

//     delete[] dataToBeSent;
//     dataToBeSent = new char[totalSize];

//     unsigned int offset = 0;

//     std::memcpy(dataToBeSent + offset, &pktHeader, sizeof(packetHeader));
//     offset += sizeof(packetHeader);

//     // Copy the rest of the data in the same manner as shown in serializeDataForLogin
//     // ...

//     return dataToBeSent;
// }

// char* Packet::serializeDataForPost(unsigned int totalSize, const postParameters& post_params) {
//     // Calculate totalSize based on the sizes of the strings and the image buffer
//     totalSize = sizeof(packetHeader) +
//                 post_params.postTitle.size() +
//                 post_params.postContent.size() +
//                 pktHeader.sizeOfImageBuffer; // Assuming this is the correct size of the image buffer

//     delete[] dataToBeSent;
//     dataToBeSent = new char[totalSize];

//     unsigned int offset = 0;

//     std::memcpy(dataToBeSent + offset, &pktHeader, sizeof(packetHeader));
//     offset += sizeof(packetHeader);

//     // Copy the post title and content in the same manner
//     // ...

//     // Copy the image buffer if it's not null
//     if (post_params.imageBuffer != nullptr) {
//         std::memcpy(dataToBeSent + offset, post_params.imageBuffer, pktHeader.sizeOfImageBuffer);
//         offset += pktHeader.sizeOfImageBuffer;
//     }

//     return dataToBeSent;
// }
