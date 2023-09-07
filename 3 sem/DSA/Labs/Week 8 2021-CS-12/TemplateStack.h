#include<iostream>
#include "TemplateLinkList.h"

template <class T>
class Stack{
    LinkList<T> l;
    int top = 0;

    public:

    Stack(){

    }
    bool push(T key){
        if(top == 0){
            l.insertHead(key);
        }
        else{
            l.insertTail(key);
        }
        top++;
        return true;
    }

    T pop(){
        top--;
        if (top != 0){
            return l.DeleteFromTail();
        }
        return l.DeleteFromHead();
    }
    void print(){
        l.print();
    }
    T peek(){
        T k = l.DeleteFromTail();
        // cout<<"Returning"<<ret;
        top--;

        this->push(k);
        return k;
    }
    int length(){
        return l.length();
    }
    Stack(Stack* s){
        this->l = s->getList();
        this->top = s->getTop();
    }
    LinkList<T> getList(){
        return l;
    }

};
