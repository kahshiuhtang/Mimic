#include "debug.hpp"
#include "poker/client.hpp"
#define PORT 8080

    Client::Client(int serverPort) : 
    SERVER_PORT{serverPort}{

    }
    Client::Client(int serverPort, std::string sourceAddress) : SERVER_PORT{serverPort}, serverAddr{sourceAddress}{

    }
    int Client::createClient(){

    }
    int Client::sendMessage(){

    }
    int Client::shutdown(){

    }
int main(int argc, char *argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    int SERVER_PORT;
    while (true)
    {
        int option_index = 0;
        static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"port", required_argument, 0, 'p'},
            {0, 0}};
        int c = getopt_long(argc, argv, "-hp:", long_options, &option_index);
        if (c == -1)
        {
            break;
        }
        switch (c)
        {
        case 'h':
            std::cout << "Poker Server Application: \n"
                      << "-h, --help: Displays HELP menu \n"
                      << "-p, --port: Port server is hosted on. Default:8080\n";
            return EXIT_SUCCESS;
        case 'p':
            if (!optarg)
            {
                std::cout << "Must enter a value" << std::endl;
                return EXIT_FAILURE;
            }
            std::cout << optarg;
            SERVER_PORT = atoi(optarg);
            if (SERVER_PORT <= 1024)
            {
                std::cout << "SERVER port must be greater than 1024!" << std::endl;
                std::cout << SERVER_PORT;
                return EXIT_FAILURE;
            }
            break;
        }
    }
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
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
    int x = 5;
    while (x > 0)
    {

        send(sock, hello, strlen(hello), 0);
        printf("Hello message sent\n");
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }

    // closing the connected socket
    close(client_fd);
    return 0;
}