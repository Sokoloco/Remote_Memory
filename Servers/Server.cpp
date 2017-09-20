//
// Created by luis on 29/08/17.
//

#include "Server.h"
#include <thread>

pthread_t threads[2] = {0};
int mainP,passiveP;

Server::Server(char* ip, int port, char* ipHA, int portHA) {
    mainP = port;
    passiveP = portHA;
    srvPrts acpt = {port,ip};
    void* acpt1 = &acpt;
	std::thread t1(createMain,acpt1);
    t1.detach();
    //pthread_create(&threads[0], NULL, Server::createMain, acpt1);
    //pthread_detach(threads[0]);
}

void *Server::createMain(void* portnip) {
    //struct srvPrts* parts = static_cast<srvPrts *>(portnip);
    //int port = parts->port;
    //char* ip = parts->Ip;
    int MainS, recievingSocket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    if ((MainS = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
    }

    if (setsockopt(MainS, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(2015);

    if (bind(MainS, (struct sockaddr *)&address,
             sizeof(address))<0) {
        perror("bind failed");
    }
    if (listen(MainS, 3) < 0) {
        perror("listen");
    }
    if ((recievingSocket = accept(MainS, (struct sockaddr *)&address,
                                  (socklen_t*)&addrlen))<0) {
        perror("accept");
    }
    valread = read( recievingSocket , buffer, 1024);
    std::cout<<buffer<<std::endl;
    return nullptr;
}

void Server::createPass(int portHA, char *ipHa) {
    passiveP = portHA;
}

void Server::newMem(char *key, void *value, int value_size) {
    struct sockaddr_in address;
    int clientS, valread;
    char helo[30] = "Hello from client";
    char *hello = helo;
    struct sockaddr_in serv_addr;
    if ((clientS = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(mainP);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        newMem(key,value,value_size);
    }

    if (connect(clientS, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    send(clientS, hello, strlen(hello), 0);


}

