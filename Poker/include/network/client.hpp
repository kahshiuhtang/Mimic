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

class Client
{
public:
    Client(int serverPort);
    Client(int serverPort, std::string sourceAddress);
    int createClient();
    int sendMessage(char * message);
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