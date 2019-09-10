#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>

using namespace std;

template <typename T>
class List {
    protected:
        //Puntero al primer elemento de la lista
        Node<T>* head;
        //Puntoero al ultimo elemento de la lista
        Node<T>* tail;
        //Nodos de la lista
        int nodes;

    public:
    //Se inicializa las variables poniendo punteros vacios, y diciendo que node es 0.
        List() : head(nullptr), tail(nullptr), nodes(0) {};

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        ~List() {
            // TODO
        }
};

#endif