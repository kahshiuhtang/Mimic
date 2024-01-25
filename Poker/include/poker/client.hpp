#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <getopt.h>
#include <iostream>
#include <cstdlib>
int Client::createClient(){
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        debug("[MPoker]: Error creating socket");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr,
                             sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    return 0;
};
class Client
{
public:
    Client(int serverPort);
    Client(int serverPort, std::string sourceAddress);
    int createClient();
    int sendMessage();
    int shutdown();
private:
    int sock;
    int valread;
    int client_fd;
    struct sockaddr_in serv_addr;
    int SERVER_PORT;
    int PORT;

    std::string serverAddr;
};

#endif