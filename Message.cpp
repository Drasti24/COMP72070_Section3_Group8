#include "Message.h"

// Default constructor
Message::Message()
    : id(0), sentAt(std::time(nullptr)), readAt(std::nullopt) {}

// Set the message ID
void Message::setId(int id) {
    this->id = id;
}

// Set the sender ID
void Message::setSenderId(const std::string& senderId) {
    this->senderId = senderId;
}

// Set the receiver ID
void Message::setReceiverId(const std::string& receiverId) {
    this->receiverId = receiverId;
}

// Set the content of the message
void Message::setContent(const std::string& content) {
    this->content = content;
}

// Set when the message was sent
void Message::setSentAt(std::time_t sentAt) {
    this->sentAt = sentAt;
}

// Set when the message was read
void Message::setReadAt(const std::optional<std::time_t>& readAt) {
    this->readAt = readAt;
}

// Get the message ID
int Message::getId() const {
    return id;
}

// Get the sender ID
std::string Message::getSenderId() const {
    return senderId;
}

// Get the receiver ID
std::string Message::getReceiverId() const {
    return receiverId;
}

// Get the content of the message
std::string Message::getContent() const {
    return content;
}

// Get when the message was sent
std::time_t Message::getSentAt() const {
    return sentAt;
}

// Get when the message was read
std::optional<std::time_t> Message::getReadAt() const {
    return readAt;
}
