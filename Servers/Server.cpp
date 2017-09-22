//
// Created by luis on 29/08/17.
//

#include "Server.h"
#include <thread>

pthread_t threads[2] = {0};
int mainP,passiveP;
/**
 *Creates both the passive and the main server threads
 * @param ip for the main server
 * @param port for the main server
 * @param ipHA ip for the passive server
 * @param portHA port for the passive server
 */
Server::Server(char* ip, int port, char* ipHA, int portHA) {
    mainP = port;
    passiveP = portHA;
    srvPrts acpt = {port,ip};
    void* acpt1 = &acpt;
	std::thread t1(createMain,acpt1);
    t1.detach();
}
/**
 *Creates the main server handles all requests to it
 * and responds
 * @param portnip void pointer cointeaining the ip and port
 * @return
 */
void *Server::createMain(void* portnip) {
    //struct srvPrts* parts = static_cast<srvPrts *>(portnip);
    //int port = parts->port;
    //char* ip = parts->Ip;
    int MainS, recievingSocket;
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
    read( recievingSocket , buffer, 1024);
    std::cout<<buffer<<std::endl;
    return nullptr;
}
/**
 *creates the passive server, similar functionality to createMain
 * @param portHA port of the passive server
 * @param ipHa ip of the passive server
 */
void Server::createPass(int portHA, char *ipHa) {
    passiveP = portHA;
}
/**
 *Makes the request to add memory to the list
 * @param key the index of the memory
 * @param value the value of the memory
 * @param value_size the size of the value in the memory
 */
void Server::newMem(char *key, void *value, int value_size) {
    /**std::cout<<helo<<std::endl;
    void *ni = helo;
    int* ol = reinterpret_cast<int*>(ni);
    std::cout<<*ol<<std::endl;**/
    struct sockaddr_in address;
    int clientS;
    char msg[1024];
    char temp[4] = "1";
    std::string s = std::to_string(value_size);
    char const *pchar = s.c_str();
    *msg = "1";
    strcat(msg,temp);
    strcat(msg,pchar);
    char space[4]="'";
    strcat(msg,space);
    strcat(msg,key);
    strcat(msg,space);
    std::cout<<msg[0]<<std::endl;
    std::cout<<msg<<std::endl;
    char *hello = msg;
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

    if (connect(clientS, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout<<"Connection Failed"<<std::endl;
    }
    send(clientS, hello, strlen(hello), 0);
}
/**
 *deletes memory from the list
 * @param key the index to be deleted
 */
void Server::delMem(char *key) {
    struct sockaddr_in address;
    int clientS;
    char helo[1024]= {0};
    strcat(helo,key);
    std::cout<<helo<<std::endl;
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
        delMem(key);
    }

    if (connect(clientS, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout<<"Connection Failed"<<std::endl;
    }
    send(clientS, hello, strlen(hello), 0);
}
/**
 *gets memory requested
 * @param key the index of the requested memory
 */
void Server::getMem(char *key) {
    struct sockaddr_in address;
    int clientS;
    char helo[1024]= {0};
    strcat(helo,key);
    std::cout<<helo<<std::endl;
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
        delMem(key);
    }

    if (connect(clientS, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout<<"Connection Failed"<<std::endl;
    }
    send(clientS, hello, strlen(hello), 0);
}