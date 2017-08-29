//
// Created by luis on 24/08/17.
//
#include <cstdlib>
#include "linkedList.h"
#include "node.h"


SList::SList() {
    head = NULL;
    curnt = NULL;
    temp = NULL;
}
template <typename T>
void SList::addNode(T newD) {
    node n = new node();
    n->next = NULL;
    n->data = newD;
    if(head != NULL){
        curnt = head;
        while(curnt->next != NULL){
            curnt = curnt->next;
        }
        curnt->next = n;
    }
    else
        head = n;
    size++;

}
template <typename T>
void SList::delNode(T delD) {
    node delPtr = NULL;
    temp = head;
    curnt = head;
    while(curnt != NULL && curnt->data.key != delD.key){//TODO: make sure this works
        temp = curnt;
        curnt = temp ->next;
    }
    if(curnt != NULL){
    delPtr = curnt;
    curnt = curnt->next;
    temp->next = curnt;
    }
    delete delPtr;
    size--;
}

template <typename T>
node SList::getNode(T getD) {
    temp = head;
    for(int i = 0; i<size;i++){
        if(getD == temp)
            return temp;
        temp = temp.getNext();
    }
}