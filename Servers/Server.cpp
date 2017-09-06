//
// Created by luis on 29/08/17.
//

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "Server.h"
#include <arpa/inet.h>



void Server::mainServer(int portNum, int iP){
    int opt = 1,new_socket, addrlen, buffsize = 1024;
    char buffer[buffsize] = {0},*data;
    int sockt = socket(AF_INET,SOCK_STREAM,0);
    if(sockt < 0)
        std::cout<<"Server has encountered an error during creation"<<std::endl;
    if (setsockopt(sockt, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        std::cout<<"setsockopt"<<std::endl;
    struct sockaddr_in server_addr;

    socklen_t size;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
    addrlen = sizeof(server_addr);
    if ((bind(sockt, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
        std::cout << "Error binding connection (the socket has already been established)" << std::endl;
    if(listen(sockt , 15) < 0)
        std::cout<<"error listening"<<std::endl;
    if ((new_socket = accept(sockt, (struct sockaddr *)&server_addr,
                             (socklen_t*)&server_addr))<0)
        std::cout<<"error accepting"<<std::endl;
    read(new_socket,buffer,buffsize);
    while(buffer > 0){

    }
    send(new_socket,data,strlen(data),0);
}
void Server::pasiveServer(int portNum, int iP) {

}

void Server::createClient(int portNum, char* iP){
    struct sockaddr_in address;
    int sock = 0,buffsize = 1024;
    struct sockaddr_in serv_addr;
    char buffer[buffsize] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        std::cout<<"Socket creation error"<<std::endl;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNum);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, iP, &serv_addr.sin_addr)<=0)
        std::cout<<"Invalid address/ Address not supported"<<std::endl;
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        std::cout<<"Connection Failed"<<std::endl;
    //send(sock , hello , strlen(hello) , 0 );
    read( sock , buffer, buffsize);

}