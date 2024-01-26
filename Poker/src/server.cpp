#include "network/server.hpp"

#include "errno.h"

typedef struct {
    pthread_cond_t thread_condition_var;
    pthread_mutex_t mutex_lock;
    std::queue<int *> *client_connections;
    int MAX_MESSAGE_LENGTH;
} ThreadedArgs;

void * handle_connection(int *ptr_connfd, ThreadedArgs *server);
void * thread_function(void *arg);

Server::Server(){
    memset(&serverAddress, '\0', sizeof(serverAddress));
}

int Server::createServer(std::shared_ptr<Server> server){
    if(isServerCreated){
        return 1;
    }
    ThreadedArgs *args = new ThreadedArgs;
    args->thread_condition_var = server->thread_condition_var;
    args->mutex_lock = server->mutex_lock;
    args->client_connections = &server->client_connections;
    args->MAX_MESSAGE_LENGTH = server->MAX_MESSAGE_LENGTH;
     for (int i = 0; i < THREAD_POOL_SIZE; i++)
    {
        if (pthread_create(&thread_pool[i], NULL, &thread_function, args) != 0)
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
    //bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // i.e we are responding to anything
    serverAddress.sin_port = htons(SERVER_PORT);

    // tell operating system that this socket will run on this port
    if (bind(listenfd, (struct sockaddr *) &serverAddress,
             sizeof(serverAddress)) < 0)
    {
        printf("fopen failed(): %s\n", strerror(errno));
        error("Failure to bind socket to port");
    }

    if (listen(listenfd, SERVER_BACKLOG) < 0)
    {
        error("Listening error");
    }
    isServerCreated = true;
    return 0;
}

int Server::startServer(){
    for (;;)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len;
        char client_address[MAX_MESSAGE_LENGTH + 1];
        printf("Server is runnning on PORT : %d\n", SERVER_PORT);

        fflush(stdout);
        client_socket = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_len);

        inet_ntop(AF_INET, &client_addr, client_address, MAX_MESSAGE_LENGTH);
        printf("\nclient connection : %s\n", client_address);
        pthread_mutex_lock(&mutex_lock);
        int *pclient = new int();
        *pclient = client_socket;
        client_connections.push(pclient);
        pthread_mutex_unlock(&mutex_lock);
        pthread_cond_signal(&thread_condition_var);
    }
    Server::killServer();
};
int Server::killServer(){
shutdown(listenfd, SHUT_RDWR);
    pthread_mutex_destroy(&mutex_lock);
    pthread_cond_destroy(&thread_condition_var);
    return 0;
}
int * Server::popOutClient(){
    int *client = client_connections.front();
    client_connections.pop();
    return client;
}

void * thread_function(void *args)
{

    // following will burn the cpu power caz although there is no any new connection
    // for the thread still ask if there any continuosl. To handle this problem we have to introduce condition variables.
    ThreadedArgs *server = (ThreadedArgs *) args;
    while (true)
    {
        pthread_mutex_lock(&server->mutex_lock);
        pthread_cond_wait(&server->thread_condition_var, &server->mutex_lock);
        // here we passed the lock since since condition varables and lock work closely. asa thread wait
        // it will releases the lock
        int *front_client;
        bool found = false;
        if (server->client_connections->size() > 0)
        {
            front_client = server->client_connections->front();
            server->client_connections->pop();
            found = true;
        }
        pthread_mutex_unlock(&server->mutex_lock);
        if (found)
        {
            printf("front_client :  %d\n", *front_client);
            handle_connection(front_client, server);
        }
    }
    return NULL;
}
void * handle_connection(int *ptr_connfd, ThreadedArgs *server)
{
    int connfd = *(ptr_connfd);
    uint8_t recvline[4096 + 1];

    printf("in handle connection connfd %d\n", connfd);
    memset(recvline, 0, server->MAX_MESSAGE_LENGTH);

    // now read the client's message

    int n = read(connfd, recvline, server->MAX_MESSAGE_LENGTH - 1);
    if (n < 0)
    {
        error("Unable to read input");
        return NULL;
    }

    printf("below is from client--------------\n\n");
    printf("%s\n", recvline);
    // sending the response now

    // sleep(5) ;

    // write(connfd, (char *)buff, strlen((char *)buff));
    // send(connfd, response.c_str(), response.size(), 0);
    close(connfd);
    printf("\nclosing connection!\n");
    return NULL;
}
