//
// Created by luis on 17/09/17.
//

#ifndef REMOTE_MEMORY_CLIENT_H
#define REMOTE_MEMORY_CLIENT_H


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

class client{
private:
public:
    bool connectClient(int* client,int mainP, int passiveP) {
        *client = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        if (*client < 0){
            return false;
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(mainP);

        if (connect(*client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
            return true;

        server_addr.sin_port = htons(passiveP);
        if (connect(*client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
            return true;

        close(*client);
        return false;
    }
};
#endif //REMOTE_MEMORY_CLIENT_H
