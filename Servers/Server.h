//
// Created by luis on 29/08/17.
//

#ifndef REMOTE_MEMORY_SERVER_H
#define REMOTE_MEMORY_SERVER_H

#include "../rmlib/rmlib.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <thread>
#include "Server.h"

class Server {
private:
    int mainS, mainP, passiveS, passiveP;
    char* mainIP, *passiveIP;
    char buffer[1025];
public:
    Server(int port, int portHA, char* ip, char* ipHA);
    bool connectClient(int* client);
    void addMem(char *key, void *value, int value_size, int *client);

    void createSocket(int *server, int port, char *ip, sockaddr_in serv_addr, int threadNo);


    static void* acceptR(void *acpt);
};


#endif //REMOTE_MEMORY_SERVER_H
