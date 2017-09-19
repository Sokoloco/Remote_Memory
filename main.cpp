
#include <iostream>
#include "/home/luis/CLionProjects/Remote_Memory/rmlib/rmlib.h"



using namespace std;

int main() {
    rmlib* go = new rmlib;
    char ip[10]= "127.0.0.1",ip2[10] = "127.0.0.2";
    char*ipptr = ip;
    char* ipPtr2 = ip2;
    go->rm_init(ipptr,2015,ipPtr2,2017);
    int test = 1;
    void* testnum = &test;
    char key1[3] = "yo";
    char* key = key1;
    cout<<key<<endl;
    go->rm_new(key,testnum,sizeof(testnum));
    }