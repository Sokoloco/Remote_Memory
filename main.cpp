
#include <iostream>
#include "/home/luis/CLionProjects/Remote_Memory/rmlib/rmlib.h"
//#include "/home/luis/CLionProjects/Remote_Memory/Servers/Server.cpp"


using namespace std;

int main(int argc, char *argv[]){
    char ip[10]= "127.0.0.1",ip2[10] = "127.0.0.2", key1[3] = "yo";
    int test = 894;
    void* testnum = &test;
    char* ipptr = ip;
    char* ipPtr2 = ip2;
    Server* go = new Server(ipptr,2015,ipPtr2,2017);
    sleep(3);
    go->newMem(key1,testnum,sizeof(testnum));
    sleep(3);
}
