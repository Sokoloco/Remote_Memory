//
// Created by luis on 11/09/17.
//

#ifndef REMOTE_MEMORY_RMLIB_H
#define REMOTE_MEMORY_RMLIB_H

#include "/home/luis/CLionProjects/Remote_Memory/Servers/Server.h"

struct rmRef_h {
    char* key;
    void* value;
    int value_size;
};

class rmlib {
public:
    void rm_init (char* ip, int port, char* ipHA, int portHA);
    void rm_new (char* key, void* value, int value_size);
    rmRef_h rm_get(char* key);
    void rm_delete(char *key);
};


#endif //REMOTE_MEMORY_RMLIB_H
