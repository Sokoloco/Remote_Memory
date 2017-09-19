//
// Created by luis on 29/08/17.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include "Server.h"

struct sockaddr_in serv_addr1,serv_addr2,cli_addr;
pthread_t threads[2] = {0};

struct acptStrct{
    int* serv;
    socklen_t clen;
};

Server::Server(int port, int portHA, char* ip, char* ipHA){
    close(mainS);
    close(passiveS);
    mainIP = ip;
    mainP = port;
    passiveIP = ipHA;
    passiveP = portHA;
    createSocket(&mainS,mainP,mainIP,serv_addr1,0);
    createSocket(&passiveS,passiveP,passiveIP,serv_addr2,1);
}

void* Server::acceptR(void* acpt) {
    acptStrct *go = static_cast<acptStrct *>(acpt);
    int *server = go->serv;
    socklen_t clilen = go->clen;
    //std::cout<<"Server:"<<*server<<" clilen:"<<clilen<<std::endl;
    int newSocklin = accept(*server, (struct sockaddr *) &cli_addr, &clilen);
    if (newSocklin < 0) { std::cout << strerror(errno) << std::endl; }
    rmRef_h message;
    if (recvfrom(*server, &message, sizeof(rmRef_h),
                 MSG_PEEK, (struct sockaddr *) &cli_addr, &clilen) > 0) {
        printf("SRV catched something!\n");
    }
}


void Server::createSocket(int* server,int port, char* ip,sockaddr_in serv_addr, int threadNo){
    *server = socket(AF_INET,SOCK_STREAM,0);
    if(server <0){//std::cout<<"1";
        return createSocket(server,port,ip,serv_addr,threadNo);}
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    if (bind(*server, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {//std::cout<<"2"<<std::endl;
        return createSocket(server,port,ip,serv_addr,threadNo);}
    socklen_t clilen = sizeof(cli_addr);
    if(listen(*server,5)<0){
        std::cout<<strerror(errno)<<std::endl; return createSocket(server,port,ip,serv_addr,threadNo);
    }

    acptStrct acpt = {server,clilen};
    void* acpt1 = &acpt;

    //std::cout<<"Server:"<<*server<<" clilen:"<<clilen<<std::endl;
    //std::cout<<" hello"<<std::endl;
    pthread_create(&threads[threadNo],NULL,Server::acceptR,acpt1);
    pthread_detach(threads[threadNo]);
}

void Server::addMem(char *key, void *value, int value_size, int* client) {
    rmRef_h newMem = {key, value, value_size};
    //void* msg = &newMem;
    std::cout<<"tryina send"<<std::endl;
    if (send(*client, &newMem, sizeof(rmRef_h), 0) < 0) {
        connectClient(client);
        addMem(key, value, value_size, client);
    }


}

bool Server::connectClient(int *client) {
    *client = socket(AF_INET, SOCK_STREAM, 0);
    if (*client < 0){
        return false;
    }
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(mainP);
    if (connect(*client,(struct sockaddr *)&cli_addr, sizeof(cli_addr)) == 0){
        std::cout<<"first client works"<<std::endl;
        return true;
    }
    cli_addr.sin_port = htons(passiveP);
    if (connect(*client,(struct sockaddr *)&cli_addr, sizeof(cli_addr)) == 0){
        std::cout<<"second client works"<<std::endl;
        return true;
    }
    close(*client);
    return false;
}
