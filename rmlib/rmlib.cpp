//
// Created by luis on 11/09/17.
//

#include <cstring>
#include "rmlib.h"
#include <iostream>


#include <typeinfo>

Server* ok;
int clientS;


void rmlib::rm_init(char* ip, int port, char* ipHA, int portHA) {
    ok = new Server(port,portHA,ip,ipHA);
}

void rmlib::rm_new(char *key, void *value, int value_size) {
    ok->connectClient(&clientS);
    ok->addMem(key,value,value_size,&clientS);
}

rmRef_h rmlib::rm_get(char *key) {
    return rmRef_h();
}

void rmlib::rm_delete(rmRef_h *handler) {

}

