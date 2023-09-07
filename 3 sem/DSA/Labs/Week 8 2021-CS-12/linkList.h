#include<iostream>
// #include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node();
    Node(int key) {
		this->data = key;
        this->next = NULL;
	};
};

class LinkList{
    private:
    Node * Head;

    public:
    LinkList(){
        Head = NULL;
        // return 0;
    };
    bool insertHead(int key) {
		Node* N = new Node(key);
		if (Head == NULL){
            Head =N;
        }
		else{
            N->next = Head;
            Head = N;
        }
		return true;
	}
    void reverse(){
        Node * nexts = NULL;
        Node * prev = NULL;
        Node * temp = Head;
        while( temp != NULL){
            nexts = temp -> next;
            temp ->next = prev;
            prev = temp;
            temp = nexts;
        }
        Head = prev;
    }
    bool insertTail(int key){
        Node *N = new Node(key);
        Node *p = Head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = N;
        N -> next = NULL;
        return true;
    }
    Node* search(int key){
        Node *p = Head;
        while(p != NULL){
            if(p->data == key){
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
    bool insert(int key, int location){
        Node *N = new Node(key);
        Node *p = Head;

        for(int i = 0; i < location; i++){
            p = p->next;
        }
        N->next = p->next;
        p->next = N;
        return 1;
    }
    int length(){
        Node *p = Head;
        int start = 0;
        while(p->next != NULL){
            start++;
            p = p->next;
        }
        return start+1;
    }
    
    bool Delete(int key){
        Node *p = Head;
        int count = 0;
        Node *prev = Head;
        while(p != NULL && p->data != key){
            p = p ->next;
            if (count > 0){
                prev = prev->next;
            }
            count++;
        }
        prev->next = p->next;
        return true;
    }
    int DeleteFromHead(){
        int k = Head->data;
        Head = Head->next;
        return k;
    }
    int DeleteFromTail(){
        Node *p = Head;
        int count = 0;
        Node *prev = Head;
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
    void sortList(){
        Node * current = Head, *index = NULL;
        while(current != NULL){
            index = current->next;
            while(index != NULL){
                if(current->data > index->data){
                    // Node * temp; 
                    int temp = index->data;
                    index->data = current->data;
                    current->data = temp;
                    
                }
                index = index ->next;
            }
            current = current -> next;
        }

    }
    Node* mergeList(Node* list1, Node* list2){
        Node* p = list1;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = list2;
        return Head;
    }
    Node* getterHeader(){
        return Head;
    }
    Node* interestLists(Node* list1, Node* list2){
        Node * p = list1;
        Node*  t = list2;
        int len1= 0 , len2 = 0;

        while(p->next != NULL){
            len1++;
            p = p->next;
        }

        while(t->next != NULL){
            len2++;
            t = t->next;
        }

        p = NULL;
        t = NULL;

        p = list1;
        t = list2;

        if(len1 > len2){
            for(int i = 0; i < len1 - len2; ++i){
                p = p->next;
            }
        }
        else if(len1 < len2){
            for(int i = 0; i < len2 - len1; ++i){
                t = t->next;
            }
        }

        while(p != NULL && t != NULL){
            if(p->data == t->data){
                return p;
            }

            p = p->next;
            t = t->next;
        }

        return NULL;

    }
    bool update(int key, int location){
        Node *N = new Node(key);
        Node *p = Head;

        for(int i = 0; i < location; i++){
            if (i + 1 >= location){
                break;
            }
            p = p->next;
        }
        
        p->data = key;
        return 1;
    }
    void print() {
		Node* N = Head;
		while (N != NULL) {
			cout << N->data << " ";
			N = N->next;
		}
		cout << endl;
	}
};
