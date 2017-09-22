//
// Created by luis on 11/09/17.
//

#include "rmlib.h"
//#include "/home/luis/CLionProjects/Remote_Memory/Servers/Server.h"


Server* ok;
int clientS;

/**
 * Sends the commend to start both the active and inacive server
 * @param ip is the ip for the main server
 * @param port port for the main server
 * @param ipHA is the ip for the passive server
 * @param portHA port for the passive server
 */
void rmlib::rm_init(char* ip, int port, char* ipHA, int portHA) {
    ok = new Server(ip,port,ipHA,portHA);
}
/**
 * adds new memory to the list
 * @param key is the key which it uses as index
 * @param value memory we whish to store
 * @param value_size size of the memory we are storing
 */
void rmlib::rm_new(char *key, void *value, int value_size) {
    ok->newMem(key,value,value_size);
}
/**
 * retrieves memory from the list
 * @param is the index which it checks the list
 * @return returns the memory space
 */
rmRef_h rmlib::rm_get(char *key) {
    ok->getMem(key);
}
/**
 * Deletes an entry in the lsit
 * @param key the index of the momoeryto be deleted
 */
void rmlib::rm_delete(char* key) {
    ok->delMem(key);
}


