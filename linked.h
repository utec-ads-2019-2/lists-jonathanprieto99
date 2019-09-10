#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
                //This permite acceder a los elementos de la clase lista, la segunda flecha permite acceder a los elementos de head en este caso data.
                return this->head->data;
        }

        T back() {
                return this->tail->data;
        }

        void push_front(T value) {
                Node temporal = new T;
                temporal->data=value;
                temporal->next=this->head;
                this->head=temporal;
        }

        void push_back(T value) {
                Node temporal = new T;
                temporal->data=value;
                temporal->next=this->tail;
                this->head=temporal;
        }

        void pop_front() {
                Node<T> temporal = this->head;
                this->head=this->head->next;
                delete *temporal;
        }

        void pop_back() {
                if(empty()=true){
                        this->head=nullptr;
                        this->tail=nullptr;
                }
                Node<T> temporal =this->tail;
                this->tail=this->tail->prev;
                delete *temporal;
                this->tail->next= nullptr;
        }

        T operator[](int index) {
            // TODO
        }

        bool empty() {
                //Te retorna true si no hay nada en el head
            return !(this->head->data);
        }

        int size() {
                int contador=0;
                Node<T> current=this->head;
                while(current!= nullptr)
                {
                        current=current->next;
                        contador++;
                }
                return contador;
        }

        void clear() {
                int contador=0;
                Node<T> current=this->head;
                Node<T> previous=new T;
                while(current!= nullptr)
                {
                        previous=current;
                        current=current->next;
                        pop_front(previous);
                }
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif