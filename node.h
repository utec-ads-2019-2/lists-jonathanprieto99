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
//Tener cuidado con delete prev porque sino no borra el ultimo
    void killSelf(int count) {
        // delete next? Eso va a dejar algunos espacios sin borrar
        if (count > 1){
            next->killSelf(count-1);
        }
        delete next;
    }
};

#endif