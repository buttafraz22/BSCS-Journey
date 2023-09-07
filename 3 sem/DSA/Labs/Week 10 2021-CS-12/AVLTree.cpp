#include <iostream>
#include "BST.h"

using namespace std;

template <class T>
class NodeA
{
public:
    T data;
    NodeA *left;
    NodeA *right;
    NodeA *parent;
    int height;

    NodeA()
    {
    }
    NodeA(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1; // new node is initially leaf node at insert Time
    }
};

template <class T>
class AVL
{
    NodeA<T> *root = NULL;

public:
    bool Insert(T element)
    {

        return true;
    }

    bool rightRotate(NodeA<T> *y)
    {
        NodeA<T> *x = y->left;
        NodeA<T> *sec = x->right;

        x->right = y;
        y->left = sec;

        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left),height(x->right)) + 1;

        return true;
    }
    bool leftRotate(NodeA<T> *x)
    {
        NodeA<T> *y = x->right;
        NodeA<T> *sec = y->left;

        y->left = x;
        x->right = sec;

        y->height = max(height(y->left),height(y->right)) + 1;
        x->height = max(height(x->left),height(x->right)) + 1;

        return true;
    }
    int balanceFactor(NodeA<T>* N){
        if(N == NULL){
            return 0;
        }
        return N->left->height - N->right->height;
    }
    int height(NodeA<T>* N){
        if(N == NULL){
            return 0;
        }
        return N->height;
    }
};

int main(){
    AVL<int>  a;
    cout<< "1";
    return 0;
}