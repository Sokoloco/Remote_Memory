//
// Created by luis on 29/08/17.
//

#ifndef REMOTE_MEMORY_SERVER_H
#define REMOTE_MEMORY_SERVER_H


#include "../rmlib/rmlib.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

class Server {
private:
    struct srvPrts{
        int port;
        char* Ip;
    };

public:
    Server(char* ip, int port, char* ipHA, int portHA);
    static void* createMain(void* portnip);
    void createPass(int portHA, char*ipHa);
    void newMem(char *key, void *value, int value_size);
};


#endif //REMOTE_MEMORY_SERVER_H
