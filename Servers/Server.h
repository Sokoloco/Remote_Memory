//
// Created by luis on 29/08/17.
//

#ifndef REMOTE_MEMORY_SERVER_H
#define REMOTE_MEMORY_SERVER_H


class Server {
public:
    void mainServer(int portNum, int iP);
    void pasiveServer(int portNum, int ip);
    void createClient(int portNum, char* iP);

};


#endif //REMOTE_MEMORY_SERVER_H
