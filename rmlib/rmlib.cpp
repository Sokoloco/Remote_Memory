//
// Created by luis on 11/09/17.
//

#include "rmlib.h"
//#include "/home/luis/CLionProjects/Remote_Memory/Servers/Server.h"


Server* ok;
int clientS;


void rmlib::rm_init(char* ip, int port, char* ipHA, int portHA) {
    ok = new Server(ip,port,ipHA,portHA);
}

void rmlib::rm_new(char *key, void *value, int value_size) {
    ok->newMem(key,value,value_size);
}

rmRef_h rmlib::rm_get(char *key) {
    return rmRef_h();
}

void rmlib::rm_delete(rmRef_h *handler) {

}


