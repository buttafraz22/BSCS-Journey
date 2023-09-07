#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node();
    Node(T key) {
		this->data = key;
        this->next = NULL;
	};
};

template <class T>
class LinkList{
    private:
    Node<T> * Head;

    public:
    LinkList(){
        Head = NULL;
        // return 0;
    }
    bool insertHead(T key) {
		Node<T>* N = new Node<T>(key);
		if (Head == NULL){
            Head =N;
        }
		else{
            N->next = Head;
            Head = N;
        }
		return true;
	}
    bool insertTail(T key){
        Node<T> *N = new Node<T>(key);
        Node<T> *p = Head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = N;
        N -> next = NULL;
        return true;
    }
    T DeleteFromTail(){
        Node<T> *p = Head;
        int count = 0;
        Node<T> *prev = Head;
        while(p->next != NULL){
            if (count > 0){
                prev = prev ->next;
            }
            count++;
            p = p ->next;
        }
        prev->next = NULL;
        return p->data;
    }
    T DeleteFromHead(){
        T k = Head->data;
        Head = Head->next;
        return k;
    }
    Node<T>* getterHeader(){
        return Head;
    }
    void print() {
		Node<T>* N = Head;
		while (N != NULL) {
			cout << N->data << " ";
			N = N->next;
		}
		cout << endl;
	}
};