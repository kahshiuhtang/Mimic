#include "debug.hpp"
#include "poker/client.hpp"
// #define PORT 8080

Client::Client(int serverPort) : 
SERVER_PORT{serverPort}{

}
Client::Client(int serverPort, std::string sourceAddress) : SERVER_PORT{serverPort}, serverAddr{sourceAddress}{

}
int Client::createClient(){
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        debug("[MPoker]: Error creating socket");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

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
int Client::sendMessage(char * message){
    send(sock, message, strlen(message), 0);
    //valread = read(sock, buffer, 1024);
    //printf("%s\n", buffer);
    return 1;
}
int Client::shutdown(){
    return close(client_fd);
}