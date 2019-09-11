#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include <string>
#include <algorithm>
#include <vector>
#include "iterators/bidirectional_iterator.h"

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
                if(empty()){//ES IGUAL A empty()==true
                    this->head=nullptr;
                    this->tail=nullptr;
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
                if(empty()){
                    this->head=nullptr;
                    this->tail=nullptr;
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
                if(empty()){
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
        if (index >= size())
            throw;
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
            Node<T> *temporal = this->head;
            vector<T> temporal_content(size());
            for(int i = 0; i< size(); i++)
            {
                temporal_content[i]=temporal -> data;
                temporal = temporal -> next;
            }
            std::sort(temporal_content.begin(), temporal_content.end());
            temporal= this -> head;
            for (int i = 0; i < size(); i++)
            {
                temporal-> data = temporal_content[i];
                temporal = temporal -> next;
            }
            temporal_content.erase(temporal_content.begin(), temporal_content.end());
        }
    
        void reverse() {
            //Solo hay un elemento o menos en la lista
            if (size() <= 1) {
                return;
            }
            Node<T> *Nodoprevio = NULL;
            Node<T> *Nodeactual = this->head;
            auto *temporal = new Node<T>();
            for (int i = 0; i < size(); i++)
            {
                temporal = Nodeactual -> next;
                Nodeactual -> next = Nodoprevio;
                Nodeactual -> prev = temporal;
                Nodoprevio = Nodeactual;
                Nodeactual = temporal;
            }
            std::swap(this->head, this->tail);
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