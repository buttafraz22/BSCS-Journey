#include<iostream>
#include "BST.h"
#include<stdlib.h>

string Menu(){
    string in;

    cout<<"1.Input Array for Binary Search Tree."<<endl;
    cout<<"2.Store Binary Search Tree."<<endl;
    cout<<"3.In Order Binary Traversal."<<endl;
    cout<<"4.Pre Order Binary Traversal."<<endl;
    cout<<"5. Post Order Binary Traversal"<<endl;
    cout<<"6. Insert Element in BST"<<endl;
    cout<<"7. Delete Element in BST"<<endl;
    cout<<"8.Exit"<<endl;
    cout<<"Please enter your option: ";
    cin >> in;
    return in;
}
BST<int>* inputArrayforBST(){
    const int size = 5;
    cout<<"You can only build an array of five elements. Sorry! "<<endl;

    int arr[size];
    for(int i = 0; i < size; i++){
        cout<<"Enter array element number "+ i+1 <<" ";
        cin>>arr[i];
    }

    BST<int>* BT = new BST<int>(arr,size);
    return BT;
}
void preOrder(BST<int>* BT){
    cout<<endl;
    BT->traversePreOrder(BT->getTree());
    cout<<endl;
}
void postOrder(BST<int>* BT){
    cout<<endl;
    BT->traversePostOrder(BT->getTree());
    cout<<endl;
}
void InOrder(BST<int>* BT){
    cout<<endl;
    BT->traverseInOrder(BT->getTree());
    cout<<endl;
}
void InsertElement(BST<int>* BT){
    int element;
    cout<<"Insert Element: ";
    cin>>element;

    BT->insertElement(element);
}
bool deleteElement(BST<int>* BT){
    int element;
    cout<<"Delete Element: ";
    cin>>element;

    BT->deleteNode(element);
    return true;
}
int main(){
    string op = "";
    BST<int>* BT;
    char c;
    do{
        op = Menu();
        if(op == "1"){
            BT = inputArrayforBST();
        }
        else if(op == "2"){
            //written yet
        }
        else if(op == "3"){
            InOrder(BT);
        }
        else if(op == "4"){
            preOrder(BT);
        }
        else if(op == "5"){
            postOrder(BT);
        }
        else if(op == "6"){
            InsertElement(BT);
        }
        else if(op == "7"){
            deleteElement(BT);
        }
        cin>>c;
        system("cls");
    }while(op != "8");

    return 0;
}