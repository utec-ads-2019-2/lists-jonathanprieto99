#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
                if ( empty() ) {
                        throw runtime_error("Empty list!");
                }
                return this->head->data;
        }

        T back() {
                if ( empty() ) {
                        throw runtime_error("Empty list!");
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
                if(empty()){//ES IGUAL A empty()==true
                        this->head=nullptr;
                        this->tail=nullptr;
                }
                else{
                        this->tail-> next= temporal;
                }
                this->tail=temporal;
                temporal->data=value;
                temporal -> next = nullptr;
                ++this->nodes;
        }

        void pop_front() {
                if (!empty())
                {
                        auto *temporal = this->head->next;
                        delete this->head;
                        this->head = temporal;
                        --this->nodes;
                }
        }

        void pop_back() {
                if ( empty() ) { throw runtime_error("Empty list!"); }
                else
                {
                        auto *temporal = this->head;
                        while (temporal->next!=this->tail)
                        {
                                temporal=temporal->next;
                        }
                        this->tail = temporal;
                        delete this->tail;
                        this->tail->next = nullptr;
                        --this->nodes;
                }
        }

        T operator[](int index) {
                if (index > size())
                        throw runtime_error("Empty list!");
                auto *temporal = this->head;
                int i=0;
                while(i<index)
                {
                        temporal=temporal->next ;
                        i++;
                }
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
                else{
                        Node<T> *Nodoprevio = NULL;
                        Node<T> *Nodeactual = this->head;
                        Node<T> *temporal = NULL;
                        for (int i = 0; i < size(); i++)
                        {
                                temporal = Nodeactual->next;
                                Nodeactual -> next= Nodoprevio;
                                Nodoprevio= Nodeactual;
                                Nodeactual = temporal;
                        }
                }
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
                return ForwardIterator<T> (this->head);
        }

	    ForwardIterator<T> end() {
                return ForwardIterator<T> (NULL);
        }

        void merge(ForwardList<T> list) {
                if (list.empty())
                {
                        return;
                }
                else
                {
                        this->tail->next = list.head;
                        this->tail = list.tail;
                }
                this->nodes= this->nodes+list.nodes;
        }
};

#endif