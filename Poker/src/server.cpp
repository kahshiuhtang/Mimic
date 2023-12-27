#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <pthread.h>

#include "debug.hpp"

#define THREAD_POOL_SIZE 20
#define SERVER_BACKLOG 3
#define MAX_LENGTH 4096

pthread_t thread_pool[THREAD_POOL_SIZE];
pthread_mutex_t mutex_lock;
pthread_cond_t thread_condition_var = PTHREAD_COND_INITIALIZER;

void *thread_function(void *arg);

int main()
{
    int listenfd, connfd, n, client_socket;
    struct sockaddr_in server_address;
    int SERVER_PORT = 8080;
    for (int i = 0; i < THREAD_POOL_SIZE; i++)
    {
        if (pthread_create(&thread_pool[i], NULL, &thread_function, NULL) != 0)
        {
            error("Failed to create pthread.");
        }
    }

    if (pthread_mutex_init(&mutex_lock, NULL) != 0)
    {
        error("Failed to initialize PTHREAD mutex.");
    }
    if (pthread_cond_init(&thread_condition_var, NULL) != 0)
    {
        error("Failed to initialize condition variable.");
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error("Failed to create socket.");
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // i.e we are responding to anything
    server_address.sin_port = htons(SERVER_PORT);

    // tell operating system that this socket will run on this port
    if (bind(listenfd, (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0)
    {
        error("Failure to bind socket to port");
    }

    if (listen(listenfd, SERVER_BACKLOG) < 0)
    {
        error("Listening error");
    }
    for (;;)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len;
        char client_address[MAX_LENGTH + 1];
        printf("Server is runnning on PORT : %d\n", SERVER_PORT);

        fflush(stdout);
        client_socket = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len);
        printf("\nclient connection : %s\n", client_address);
        int *ptr = &client_socket;
    }
    shutdown(listenfd, SHUT_RDWR);
    pthread_mutex_destroy(&mutex_lock);
    pthread_cond_destroy(&thread_condition_var);
    return 0;
}

void *thread_function(void *arg)
{

    // following will burn the cpu power caz although there is no any new connection
    // for the thread still ask if there any continuosl. To handle this problem we have to introduce condition variables.

    while (true)
    {

        int *front_client;
        bool found = false;

        pthread_mutex_lock(&mutex_lock);

        pthread_cond_wait(&thread_condition_var, &mutex_lock);
        // here we passed the lock since since condition varables and lock work closely. asa thread wait
        // it will releases the lock
        pthread_mutex_unlock(&mutex_lock);

        if (found)
        {
            printf("front_client :  %d\n", *front_client);
            // handle_connection(front_client);
        }
    }
}
