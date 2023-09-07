#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node* left;
    Node* right;

    Node();
    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class T>
class BinaryTree{
    Node<T> * root = NULL;

    public:
    bool insertElement(T element){
        Node<T>* N = new Node<T>(element);

        if(root == NULL){
            root = N;
        }
        else{
            if(N->data < root->data){
                Node<T>* p = root;
                while(p->left != NULL){
                    p = p->left;
                }
                p->left = N;
                N->left = NULL;
            }
            else if(N->data > root->data){
                Node<T>* p = root;
                while(p->right != NULL){
                    p = p->right;
                }
                p->right = N;
                N->right = NULL;
            }
        }
        return true;
    }

    Node<T>* getRoot(){
        return root;
    }

    void traverseInOrder(Node<T>* root){
        if(root != NULL){
            traverseInOrder(root->left);
            cout << " " << root->data;
            traverseInOrder(root->right);
        }
        return;
    }

    void traversePreOrder(Node<T>* root){
        if(root != NULL){
            cout << " " << root->data;
            traverseInOrder(root->left);
            traverseInOrder(root->right);
        }
        return;
    }
    void traversePostOrder(Node<T>* root){
        if(root != NULL){
            traverseInOrder(root->left);
            traverseInOrder(root->right);
            cout << " " << root->data;
        }
        return;
    }
};

int main(){
    BinaryTree<int> BT;

    BT.insertElement(3);
    BT.insertElement(4);
    BT.insertElement(5);
    BT.insertElement(2);

    BT.traverseInOrder(BT.getRoot());
    cout<<endl;

    BT.traversePreOrder(BT.getRoot());
    cout<<endl;

    BT.traversePostOrder(BT.getRoot());
    cout<<endl;

    return 0;
}