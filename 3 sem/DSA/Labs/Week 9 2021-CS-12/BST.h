#include<iostream>
#include<math.h>
using namespace std;

template <class T>
class Node{
    public:
    T data;
    Node* left;
    Node* right;
    Node* parent;

    Node();
    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class T>
class BST{
    Node<T> * root = NULL;

    public:

    BST();
    BST(T arr[], int size){
        for(int i = 0; i < size; ++i){
            this->insertElement(arr[i]);
        }
    }
    ~BST();
    bool isEmpty(){
        return root == NULL;
    }

    Node<T>* searchTree(Node<T>* root, T element){

        if (root == NULL || root->data == element){
            return root;
        }
      
        if (root->data < element){
            if(root->right == NULL){
                return root;
            }
            return searchTree(root->right, element);
        }
        else{
            if(root->left == NULL){
                return root;
            }
            return searchTree(root->left, element);
        }
        return NULL;
    }

    Node<T>* treeMinimum(Node<T>* root){
        while(root->left != NULL){
            root = root ->left;
        }
        return root;
    }
    Node<T>* treeMaximum(Node<T>* root){
        while(root->right != NULL){
            root = root ->right;
        }
        return root;
    }

    Node<T>* treeSuccessor(Node<T>* given){
        if(given->right != NULL){
            return treeMinimum(given->right);
        }
        Node<T>* y = given->parent;
        while(y != NULL && given->data == y->right->data){
            given = y;
            y = y->parent;
        }
        return y;
    }

    bool insertElement(T element){
        Node<T>* N = new Node<T>(element);

        if(root == NULL){
            root = N;
        }
        else{
            Node<T>* lastNode = searchTree(root,element);
            if(element > lastNode->data){
                lastNode->right = N;
                N->parent = lastNode;
            }
            else{
                lastNode->left = N;
                N->parent = lastNode;
            }
        }
        return true;
    }

    Node<T>* getTree(){
        return root;
    }
    bool isBST(Node<T>* root){

        if(root == NULL){
            return true;
        }
        else if(root->left != NULL && maximumBin(root->left) > root->data){
            return false;
        }
        else if(root->right != NULL && minimumBin(root->right) < root->data){
            return false;
        }

        return true;
    }
    T maximumBin(Node<T>* root){
        if(root == NULL){
            return INT32_MIN;
        }
        T curNode = root ->data ;
        T leftmax = maximumBin(root->left);
        T rightmax = maximumBin(root->right);

        T bin = min(leftmax, rightmax);
        T ret = max(curNode,bin);

        return ret;
    }
    T minimumBin(Node<T>* root){
        if(root == NULL){
            return INT32_MAX;
        }
        T curNode = root ->data ;
        T leftmin = minimumBin(root->left);
        T rightmin = minimumBin(root->right);

        T bin = max(leftmin, rightmin);
        T ret = min(curNode,bin);

        return ret;
    }
    void transplant(Node<T>* original , Node<T>* replacement){
        if(original->parent == NULL){
            this->root = replacement;
        }
        else if(original == original->parent->left){
            original->parent->left = replacement;
        }
        else if(original == original->parent->right){
            original->parent->right = replacement;
        }

        if(replacement != NULL){
            replacement->parent = original->parent;
        }
    }
    bool deleteNode(T x){
        Node<T>* find = searchTree(this->root, x);
        if(find->data != x) return false; //guard clause to check for leaf nodes

        if(find->left == NULL){ 
            transplant(find,find->right);   // tree has no left child
        }
        else if(find->right == NULL){ 
            transplant(find,find->left);   // tree has no right child
        }

        else{
            Node<T>* y = treeMinimum(find->right);
            if(y->parent != find){
                transplant(y,y->right);
                y->right = find->right;
                y->right->parent = y;
            }

            transplant(find,y);
            y->left = find->left;
            y->left->parent = y;
        }
        return true;
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
    int NumberOfNodes(Node<T>* root){
        int count = 0;
        if(root != NULL){
            count++;
            count += NumberOfNodes(root->left);
            count += NumberOfNodes(root->right);
        }
        return count;
    }
    int Height(Node<T>* root){
        if(root == NULL){
            return 0;
        }
        int leftH = NumberOfNodes(root->left);
        int rightH = NumberOfNodes(root->right);

        int maximum = max(leftH,rightH);
        return maximum + 1;
    }
};
