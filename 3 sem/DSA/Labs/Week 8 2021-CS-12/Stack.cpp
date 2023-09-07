#include <iostream>
#include "linkList.h"
#include <string>
#include <algorithm>

using namespace std;

class Stack{

    private:
    LinkList l;
    int top = 0;
    int limit = 0;

    public:
    Stack(int limit){
        this->limit = limit;
    }
    Stack(Stack* s){
        this->l = s->getList();
        this->top = s->getTop();
        this->limit = s->getLimit();
    }
    LinkList getList(){
        return l;
    }
    int getTop(){
        return top;
    }
    int getLimit(){
        return limit;
    }
    bool push(int key){
        if(top == 0){
            l.insertHead(key);
            top++;
        }
        else if(top == limit){
            return false;
        }
        else{
            l.insertTail(key);
            top++;
        }
        return true;
    }
    int peek(){
        int k = l.DeleteFromTail();
        // cout<<"Returning"<<ret;
        top--;

        this->push(k);
        return k;
    }
    int length(){
        return l.length();
    }

    int pop(){
        if(top >= 0){
            int k = l.DeleteFromTail();
            top--;
            return k;
        }
        return -1;
    }

    void print(){
        l.print();
    }

    string Stringify(){
        string str = "";
        int len = this->length();

        Stack *clone = new Stack(this);
        
        for(int i = 0; i < this->length()+1; i++){
            int k = clone->pop();
            str = str + to_string(k) + " ";
        }

        delete(clone);
        reverse(str.begin(),str.end());
        return str;
    }
};

int main(){
    Stack * S = new Stack(30);
    S->push(5);
    S->push(4);
    S->push(13);

    int k = S->peek();
    cout<<endl<<k<<endl;

    S->pop();
    S->print();

    cout<<S->Stringify();
    return 0;
}