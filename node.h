#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    //Data de tipo T que es template
    T data;
    //Puntero al nodo siguiente
    Node<T>* next;
    //Puntero al nodo anterior
    Node<T>* prev;

    void killSelf() {
        // TODO
    }
};

#endif