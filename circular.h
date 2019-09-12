#ifndef CIRCULAR_H
#define CIRCULAR_H
#include "list.h"
#include "iterators/bidirectional_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

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
            if(this->nodes==0){
                this->head=nullptr;
                this->tail=nullptr;
            }
            else{
                Node<T> *temporal =this->tail->prev;
                delete this->tail;
                this->tail=temporal;
                this->head->prev= this->tail;
                this->tail->next= this->head;
                --this->nodes;
            }
        }

        T operator[](int index) {
            if (index > size()){
                throw runtime_error("TimeOut");
            }
            Node<T> *temporal = this->head;
            for (int i = 0; i < index; i++)
                temporal = temporal->next ;
            return temporal->data ;
        }

        bool empty() {
            return (this -> nodes == 0);
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf(this->nodes);
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes=0;
        }

        void sort() {
            Node<T> *listaorigin = this->head;
            T* array = new T[this->nodes];

            for(int i = 0; i< this->nodes; i++)
            {
                array[i]=listaorigin -> data;
                listaorigin = listaorigin -> next;
            }
            //Se le pasa donde empieza y termina el array
            std::sort(array, array+this->nodes);
            listaorigin=this->head;

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
            Node<T> *Nodeactual = this->head;
            Node<T> *temporal = NULL;
            while(Nodeactual!= nullptr)
            {
                temporal = Nodeactual->next;
                Nodeactual -> next = Nodeactual->prev;
                Nodeactual -> prev = temporal;
                Nodeactual = temporal;
            }
            swap(this->head,this->tail);
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
	        return BidirectionalIterator<T> (this->head);
        }

        void merge(CircularLinkedList<T> list) {
            if (list.empty()){
                return;
            }
            if (size() == 0)
                return;
            else
            {
                this->tail->next = list.head;
                list.head->prev = this->tail;
                this->tail = list.tail;
                this->tail->next = this->head;
            }
            this->nodes = this->nodes+list.nodes;
        }
};

#endif