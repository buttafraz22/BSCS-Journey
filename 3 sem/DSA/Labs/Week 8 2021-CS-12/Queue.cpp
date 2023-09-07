#include<iostream>
#include "linkList.h"

class Queue{
    private:
    LinkList l;
    int top = 0;
    int limit = 0;

    public:

    Queue(int limit){
        this->limit = limit;
    }

    bool isFull(){
        return top == limit;
    }
    bool isEmpty(){
        return top == 0;
    }
    void print(){
        l.print();
    }

    int peek(){
        int k = l.DeleteFromHead();
        top--;
        l.insertHead(k);
        return k;
    }
    bool enqueue(int key){
        if(top == 0){
            l.insertHead(key);
        }
        else{
            l.insertTail(key);
        }
        top++;
        return true;
    }
    bool dequeue(){
        l.DeleteFromHead();
        return true;
    }

};

int main(){
    Queue *q = new Queue(30);
    cout<<q->isEmpty()<<" of Boolean"<<endl;

    q->enqueue(19);
    q->enqueue(3);
    q->enqueue(13);
    // q->print();
    cout<<"Element at front: "<<q->peek()<<endl;

    q->dequeue();
    q->print();
    return 0;
}