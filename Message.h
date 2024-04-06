#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <optional>

class Message {
private:
    int id;
    std::string senderId; // User ID of the sender
    std::string receiverId; // User ID of the receiver
    std::string content; // The message content
    std::time_t sentAt; // When the message was sent
    std::optional<std::time_t> readAt; // When the message was read, std::nullopt if unread

public:
    Message(); // Default constructor

    // Setters
    void setId(int id);
    void setSenderId(const std::string& senderId);
    void setReceiverId(const std::string& receiverId);
    void setContent(const std::string& content);
    void setSentAt(std::time_t sentAt);
    void setReadAt(const std::optional<std::time_t>& readAt);

    // Getters
    int getId() const;
    std::string getSenderId() const;
    std::string getReceiverId() const;
    std::string getContent() const;
    std::time_t getSentAt() const;
    std::optional<std::time_t> getReadAt() const;
};

#endif // MESSAGE_H
