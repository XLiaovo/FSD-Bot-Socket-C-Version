"""
Software Name: FSD-Bot-Socket
Version: 1.0.0
Author: XLiao
Copyright (c) 2023 by XLiao ❤
License: This software is licensed under the MIT License.
"""
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <winsock2.h>

class FsdSocketClient {
public:
    FsdSocketClient(const std::string& hostName, int port, const std::string& userCall, const std::string& userName, const std::string& userPwd);
    void FsdBot();

private:
    std::string hostName;
    int port;
    std::string userCall;
    std::string userName;
    std::string userPwd;

    void ProcessMessage(const std::string& message);
};

FsdSocketClient::FsdSocketClient(const std::string& hostName, int port, const std::string& userCall, const std::string& userName, const std::string& userPwd)
    : hostName(hostName), port(port), userCall(userCall), userName(userName), userPwd(userPwd) {}

void FsdSocketClient::FsdBot() {
    std::cout << "Software Name: FSD-Bot-Socket" << std::endl;
    std::cout << "Version: 1.0.0" << std::endl;
    std::cout << "Author: XLiao" << std::endl;
    std::cout << "License: This software is licensed under the MIT License." << std::endl;
    std::cout << "If customization is needed, please contact XLiao (QQ: 2456666787)" << std::endl;

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return;
    }

    SOCKET socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (socketClient == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(hostName.c_str());

    if (connect(socketClient, reinterpret_cast<SOCKADDR*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to the server." << std::endl;
        closesocket(socketClient);
        WSACleanup();
        return;
    }

    time_t currentTime = time(nullptr);
    std::string timestamp = std::ctime(&currentTime);
    timestamp.pop_back(); // Remove the newline character from the timestamp

    std::cout << timestamp << " Successfully established a connection with the server!" << std::endl;

    // Implement the rest of the logic here

    closesocket(socketClient);
    WSACleanup();
}

void FsdSocketClient::ProcessMessage(const std::string& message) {
    // Process the received message
    // Implement the message processing logic based on message type
}

int main() {
    std::string hostName = ""; // Host name or IP
    int port = 6809;
    std::string userCall = ""; // User name
    std::string userName = ""; // Position name
    std::string userPwd = ""; // User password

    FsdSocketClient fsdSocketClient(hostName, port, userCall, userName, userPwd);
    fsdSocketClient.FsdBot();

    return 0;
}
