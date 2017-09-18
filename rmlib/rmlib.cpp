//
// Created by luis on 11/09/17.
//

#include <cstring>
#include "rmlib.h"
#include <iostream>


#include <typeinfo>

Server* ok;
int client;

void rmlib::rm_init(char* ip, int port, char* ipHA, int portHA) {
    ok = new Server(port,portHA,ip,ipHA);
//    ok->connectClient(&client);
}

void rmlib::rm_new(char *key, void *value, int value_size) {
    ok->addMem(key,value,value_size,&client);
    /**char* message = new char[1025];
    int offset = 0;
    int cpyval = value_size;
    char size[100], temp;
    for(;cpyval>0;){
        temp = '0'+ cpyval%10;
        std::strcat(size,temp);
        cpyval/=10;
    }
    memcpy(message+offset,value, sizeof(value));
    offset+= sizeof(value);
    memcpy(message+offset,&value_size, sizeof(value_size));
    offset+= sizeof(value_size);
    memcpy(message+offset,key, sizeof(key));
    ok->addMem(message,&client);**/

}

rmRef_h rmlib::rm_get(char *key) {
    return rmRef_h();
}

void rmlib::rm_delete(rmRef_h *handler) {

}

