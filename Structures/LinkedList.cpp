#include <iostream>
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() {
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
/**
 * Adds an element to the list
 * @tparam T type of element to be added
 * @param data data that is going to be added
 */
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
    }
    size++;}
template <class T>
    void LinkedList<T>::remove(T data) {
        if (!first)return;
        if (first == last && first->getData() == data)
            first = last = NULL;
        else if (first->getData() == data)
            first = first->getNext();
        else {
            Node<T>* curr = first, *bhnd = curr;
            while (curr != NULL) {
                if (curr->getData() == data) {
                    bhnd->setNext(curr->getNext());
                    delete(curr);
                }
                bhnd = curr;
                curr = curr->getNext();
            }
        }
    }

template <class T>
    Node<T>* LinkedList<T>::search(T value){
        Node<T>* curr = first;
        while(curr != NULL){
            if(curr->getData() == value) return curr;
            curr = curr->getNext();
        }
        return NULL;
    }
