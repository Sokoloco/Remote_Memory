//
// Created by luis on 24/08/17.
//

#ifndef REMOTE_MEMORY_LINKEDLIST_H
#define REMOTE_MEMORY_LINKEDLIST_H

#include "node.h"

template <typename T>

class SList{
private:
    node head,curnt,temp;
    int size;

public:
    template <typename T>
    SList();
    void addNode(T newD);
    void delNode(T delD);
    node getNode(T getD);
};
#endif //REMOTE_MEMORY_LINKEDLIST_H