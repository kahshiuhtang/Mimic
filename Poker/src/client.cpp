#include "debug.hpp"
#include "network/client.hpp"
// #define PORT 8080
typedef struct {
    pthread_cond_t *thread_condition_var;
    pthread_mutex_t *mutex_lock;
    std::queue<int *> *client_connections;
    int MAX_MESSAGE_LENGTH;
} PThreadArgs;
void  *threadFunction(void * args);
void * handle_connection(int *ptr_connfd, PThreadArgs *client);
Client::Client(int serverPort) : 
SERVER_PORT{serverPort}{
    memset(&serv_addr, '\0', sizeof(serv_addr));
    memset(&serverAddress, '\0', sizeof(serverAddress));
}
Client::Client(int serverPort, std::string sourceAddress) : SERVER_PORT{serverPort}, serverAddr{sourceAddress}{
    memset(&serv_addr, '\0', sizeof(serv_addr));
    memset(&serverAddress, '\0', sizeof(serverAddress));
}
int Client::createClient(){
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        debug("[MPoker]: Error creating socket");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    //need to change to serverAddr
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

int Client::setupListeningPort(std::shared_ptr<Client> client){
    PThreadArgs *args = new PThreadArgs;
    args->thread_condition_var = &(client->thread_condition_var);
    args->mutex_lock = &(client->mutex_lock);
    args->client_connections = &client->client_connections;
    args->MAX_MESSAGE_LENGTH = client->MAX_MESSAGE_LENGTH;
    for (int i = 0; i < THREAD_POOL_SIZE; i++)
    {
        if (pthread_create(&threadPool[i], NULL, &threadFunction, args) != 0)
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
        char client_address[MAX_MESSAGE_LENGTH + 1];
        printf("Listening on PORT : %d\n", PORT);

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

    return -0;
}
int Client::sendMessage(char * message){
    send(sock, message, strlen(message), 0);
    //valread = read(sock, buffer, 1024);
    //printf("%s\n", buffer);
    return 1;
}
int Client::shutdown(){
    return close(client_fd);
}

void  *threadFunction(void * args){
    PThreadArgs *client = (PThreadArgs *) args;
    while (true)
    {
        pthread_mutex_lock(client->mutex_lock);
        pthread_cond_wait(client->thread_condition_var, client->mutex_lock);
        // here we passed the lock since since condition varables and lock work closely. asa thread wait
        // it will releases the lock
        int *front_client;
        bool found = false;
        if (client->client_connections->size() > 0)
        {
            front_client = client->client_connections->front();
            client->client_connections->pop();
            found = true;
        }
        pthread_mutex_unlock(client->mutex_lock);
        if (found)
        {
            printf("front_client :  %d\n", *front_client);
            handle_connection(front_client, client);
        }
    }
    return NULL;
}

void * handle_connection(int *ptr_connfd, PThreadArgs *client)
{
    int connfd = *(ptr_connfd);
    uint8_t recvline[client->MAX_MESSAGE_LENGTH + 1];

    printf("in handle connection connfd %d\n", connfd);
    memset(recvline, 0, client->MAX_MESSAGE_LENGTH);

    // now read the client's message

    int n = read(connfd, recvline, client->MAX_MESSAGE_LENGTH - 1);
    if (n < 0)
    {
        error("Unable to read input");
        return NULL;
    }

    printf("below is from server --------------\n\n");
    printf("%s\n", recvline);
    // sending the response now

    // sleep(5) ;

    // write(connfd, (char *)buff, strlen((char *)buff));
    // send(connfd, response.c_str(), response.size(), 0);
    close(connfd);
    printf("\nclosing connection!\n");
    return NULL;
}