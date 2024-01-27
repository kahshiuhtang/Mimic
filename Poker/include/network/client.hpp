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

#include <pthread.h>
#include <memory>

#include <queue>
class Client
{
public:
    Client(int serverPort);
    Client(int serverPort, std::string sourceAddress);
    int createClient();
    int setupListeningPort(std::make_shared<Client> client);
    int sendMessage(char * message);
    int shutdown();

    pthread_cond_t thread_condition_var = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t mutex_lock;

private:
    int sock;
    int valread;
    int client_fd;
    struct sockaddr_in serv_addr;
    int SERVER_PORT;
    int PORT = 8089;
    int MAX_MESSAGE_LENGTH = 4096;

    int listenfd;
    struct sockaddr_in serverAddress;
    int SERVER_BACKLOG = 3;
    pthread_t threadPool[1];
    int THREAD_POOL_SIZE = 1;
    std::queue<int *> client_connections;
    

    std::string serverAddr;
};

#endif