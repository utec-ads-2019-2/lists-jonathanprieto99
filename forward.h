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
                        this->nodes--;
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
                        this->nodes--;
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
                this->head->killSelf(0);
                this->head = nullptr;
                this->tail = nullptr;
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
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
                        throw runtime_error("Empty list!");
                }
                if (this->nodes==0)
                {
                        this->head = list.head;
                }
                else
                {
                        this->head->next = list.tail;
                }
                this->tail = list.tail;
                this->nodes += list.nodes;
        }
};

#endif