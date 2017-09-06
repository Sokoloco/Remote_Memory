#include <iostream>
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
    last = NULL;
}

template <class T>
void LinkedList<T>::add(T* data) {
    if(!first) {
        first = new Node<T>(data);
        last = first;
    } else {
        // The list isn't empty
        if(last == first) {
            // The list has one element
            last = new Node<T>(data);
            first->setNext(last);
        } else {
            // The list has more than one element
            Node<T>* insdata = new Node<T>(data);
            last->setNext(insdata);
            last = insdata;
        }
    }}
template <class T>
void LinkedList<T>::add(T data) {
    if(!first) {
        first = new Node<T>(&data);
        last = first;
    } else {
        // The list isn't empty
        if(last == first) {
            // The list has one element
            last = new Node<T>(&data);
            first->setNext(last);
        } else {
            // The list has more than one element
            Node<T>* insdata = new Node<T>(&data);
            last->setNext(insdata);
            last = insdata;
        }
    }}



