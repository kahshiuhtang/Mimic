#include "network/server.hpp"
int Server::createServer(){
    if(isServerCreated){
        return 1;
    }
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
    bzero(serverAddress, sizeof(*serverAddress));
    serverAddress->sin_family = AF_INET;
    serverAddress->sin_addr.s_addr = htonl(INADDR_ANY); // i.e we are responding to anything
    serverAddress->sin_port = htons(SERVER_PORT);

    // tell operating system that this socket will run on this port
    if (bind(listenfd, (struct sockaddr *)&serverAddress,
             sizeof(*serverAddress)) < 0)
    {
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
    server->client_connections.pop();
    return client;
}
void * thread_function(void *arg, Server *server)
{

    // following will burn the cpu power caz although there is no any new connection
    // for the thread still ask if there any continuosl. To handle this problem we have to introduce condition variables.

    while (true)
    {
        pthread_mutex_lock(&server->mutex_lock);
        pthread_cond_wait(&server->thread_condition_var, &server->mutex_lock);
        // here we passed the lock since since condition varables and lock work closely. asa thread wait
        // it will releases the lock
        int *front_client;
        bool found = false;
        if (server->client_connections.size() > 0)
        {
            front_client = server->popOutClient();
            found = true;
        }
        pthread_mutex_unlock(&server->mutex_lock);
        if (found)
        {
            printf("front_client :  %d\n", *front_client);
            handle_connection(front_client);
        }
    }
}
void * handle_connection(int *ptr_connfd, Server *server)
{
    int connfd = *(ptr_connfd);

    printf("in handle connection connfd %d\n", connfd);
    memset(server->recvline, 0, server->MAX_MESSAGE_LENGTH);

    // now read the client's message

    int n = read(connfd, server->recvline, server->MAX_MESSAGE_LENGTH - 1);
    if (n < 0)
    {
        error("Unable to read input");
        return NULL;
    }

    printf("below is from client--------------\n\n");
    printf("%s\n", server->recvline);
    // sending the response now

    // sleep(5) ;

    // write(connfd, (char *)buff, strlen((char *)buff));
    // send(connfd, response.c_str(), response.size(), 0);
    close(connfd);
    printf("\nclosing connection!\n");
    return NULL;
}
