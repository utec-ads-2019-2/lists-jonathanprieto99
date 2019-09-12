#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
                if ( empty() ) {
                        throw runtime_error("TimeOut");
                }
                //This permite acceder a los elementos de la clase lista, la segunda flecha permite acceder a los elementos de head en este caso data.
                return this->head->data;
        }

        T back() {
                if ( empty() ) {
                        throw runtime_error("TimeOut");
                }
                return this->tail->data;
        }

        void push_front(T value) {
                auto *temporal = new Node<T>;
                if(this->nodes==0){
                        temporal->next = temporal;
                        temporal->prev = temporal;
                        this->head=temporal;
                        this->tail=this->head;
                }
                else{
                        temporal->next=this->head;
                        this->head->prev=temporal;
                        this->head=temporal;
                        this->head->prev = this->tail;
                        this->tail->next = this->head;
                }
                temporal->data=value;
                ++this->nodes;
        }

        void push_back(T value) {
                auto *temporal = new Node<T>;
                if(this->nodes==0){
                        temporal->next = temporal;
                        temporal->prev = temporal;
                        this->head=temporal;
                        this->tail=this->head;
                }
                else{
                        temporal->prev=this->tail;
                        this->tail->next=temporal;
                        this->tail=temporal;
                        this->head->prev = this->tail;
                        this->tail->next = this->head;
                }
                temporal->data=value;
                ++this->nodes;
        }

        void pop_front() {
            if(empty()){
                this->head=nullptr;
                this->tail=nullptr;
            }
            else{
                Node<T> *temporal = this->head->next;
                delete this->head;
                this->head=temporal;
                this->head->prev= this->tail;
                this->tail->next= this->head;
                --this->nodes;
            }
        }

        void pop_back() {
            // TODO
        }

        T operator[](int index) {
            // TODO
        }

        bool empty() {
            // TODO
        }

        int size() {
            // TODO
        }

        void clear() {
            // TODO
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(CircularLinkedList<T> list) {
            // TODO
        }
};

#endif