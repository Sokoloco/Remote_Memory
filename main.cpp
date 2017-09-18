#include <iostream>
#include <cstring>
#include "Structures/LinkedList.cpp"
#include "/home/luis/CLionProjects/Remote_Memory/Servers/Server.h"



using namespace std;

int main() {
    rmlib* go = new rmlib;
    char ip[10]= "127.0.0.1",ip2[10] = "127.0.0.2";

    go->rm_init(ip,2015,ip2,2017);
}