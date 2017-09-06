//
// Created by luis on 24/08/17.
//

#ifndef REMOTE_MEMORY_LINKEDLIST_H
#define REMOTE_MEMORY_LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList{
private:
    Node<T>* first;
    Node<T>* last;
public:
    LinkedList<T>();
    void add(T* data);
    void add(T data);
    T get(T value);
};


#endif //REMOTE_MEMORY_LINKEDLIST_H