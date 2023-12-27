#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <unistd.h>

#include <pthread.h>

#define THREAD_POOL_SIZE 20
pthread_t thread_pool[THREAD_POOL_SIZE];
pthread_mutex_t mutex_lock;

int main()
{
    return 0;
}