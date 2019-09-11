#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include <string>
#include <algorithm>
#include <iostream>
#include "iterators/bidirectional_iterator.h"

using namespace std;

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            if ( empty() ) {
                throw;
            }
                //This permite acceder a los elementos de la clase lista, la segunda flecha permite acceder a los elementos de head en este caso data.
                return this->head->data;
        }

        T back() {
            if ( empty() ) {
                throw;
            }
                return this->tail->data;
        }

        void push_front(T value) {
            auto *temporal = new Node<T>;
                if(this->nodes==0){
                    this->head=temporal;
                    this->tail=temporal;
                }
                else{
                    temporal->next=this->head;
                    this->head=temporal;
                }
            temporal->data=value;
            ++this->nodes;
        }

        void push_back(T value) {
            auto *temporal = new Node<T>;
                if(this->nodes==0){
                    this->head=temporal;
                    this->tail=temporal;
                }
                else{
                    temporal->prev=this->tail;
                }
            temporal->data=value;
            temporal->next= nullptr;
            ++this->nodes;
        }

        void pop_front() {
                if(empty()){
                    this->head=nullptr;
                    this->tail=nullptr;
                }
                else{
                    Node<T> *temporal = this->head;
                    this->head=this->head->next;
                    delete temporal;
                    --this->nodes;
                }
        }

        void pop_back() {
                if(this->nodes==0){
                        this->head=nullptr;
                        this->tail=nullptr;
                }
                else{
                    Node<T> *temporal =this->tail;
                    this->tail=this->tail->prev;
                    delete temporal;
                    this->tail->next= nullptr;
                    --this->nodes;
                }
        }

    T operator[](int index) {
        if (index > size()){
            throw;
        }
        Node<T> *temporal = this->head;
        for (int i = 0; i < index; i++)
            temporal = temporal->next ;
        return temporal->data ;
    }

        bool empty() {
                //Te retorna true si no hay nada en el head
            return (this -> nodes == 0);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf(this->nodes);
            this->nodes=0;
            this->head = nullptr;
            this->tail = nullptr;
        }

        void sort() {
            Node<T> *listaorigin = this->head;
            T* array = new T[this->nodes];

            for(int i = 0; i< size(); i++)
            {
                array[i]=listaorigin -> data;
                listaorigin = listaorigin -> next;
            }
            int n = sizeof(array)/sizeof(array[0]);
            std::sort(array, array+n);
            listaorigin=this -> head;

            for (int i = 0; i < size(); i++)
            {
                listaorigin-> data = array[i];
                listaorigin = listaorigin -> next;
            }

            delete[] array;
        }
    
        void reverse() {
            if (size() <= 1) {
                return;
            }
            Node<T> *Nodoprevio = NULL;
            Node<T> *Nodeactual = this->head;
            Node<T> *temporal = NULL;
            for (int i = 0; i < size(); i++)
            {
                temporal = Nodeactual->next;
                Nodeactual -> next = Nodoprevio;
                Nodeactual -> prev = temporal;
                Nodoprevio = Nodeactual;
                Nodeactual = temporal;
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T> (this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T> (NULL);
        }

        void merge(LinkedList<T> list) {
            if (list.empty()){
                return;
            }
            if (size() == 0)
                this->head = list.head;
            else
            {
                this->tail->next = list.head;
                list.head->prev = this->tail;
            }
            this->tail = list.tail;
            this->nodes += list.nodes;
        }
};

#endif