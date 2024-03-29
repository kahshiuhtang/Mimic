       #include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <sys/socket.h>
#include <unistd.h>
#include <getopt.h>

#include <pthread.h>
#include <queue>
#include <cstddef>

#include <memory>

#include "debug.hpp"

class Server{
public:
    Server();
    int createServer(std::shared_ptr<Server>);
    int startServer();
    int killServer();
    int sendMessage(char *message);
    pthread_cond_t thread_condition_var = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t mutex_lock;
    uint8_t buff[4096 + 1];
    int MAX_MESSAGE_LENGTH = 4096;
    int *popOutClient();
    std::queue<int *> client_connections;

private:
    int listenfd;
    int connfd;
    int client_socket;
    struct sockaddr_in serverAddress;
    int SERVER_PORT = 8080;
    int THREAD_POOL_SIZE = 20;
    int SERVER_BACKLOG = 3;

    bool isServerCreated = false;
    pthread_t thread_pool[20];

    int CLIENT_PORT =8089;
    int client_fd;
    int client_sock;
    struct sockaddr_in client_addr;
};