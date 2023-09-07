#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int element;
    vector <int> neighbours;
};

class Graph{
    public:
    vector <Node> edges;

    void addEdge(int element ,int neighbours[] , int size){
        Node nwE;
        nwE.element = element;

        // int size = sizeof(neighbours) / sizeof(neighbours[0]);
        for(int i = 0; i < size; i++){
            nwE.neighbours.push_back(neighbours[i]);
        }
        this->edges.push_back(nwE);
    }

    void printGraph(){
        for(Node vectors: edges){
            cout<<"This element is: "<<vectors.element;
            cout<<" and Adjacency List (Neighbour) -> :";
            for(int elements: vectors.neighbours){
                cout<<elements<<"   ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    int n [3]= {1,2,3};
    int p [2] = {1,2};
    int k [2] = {4,5};
    int l [1] = {3};
    int m [2] = {3,5};
    g.addEdge(5, n , 3);
    g.addEdge(3,p, 2);
    g.addEdge(1,l , 1);
    g.addEdge(2,m , 2);
    g.addEdge(4,k , 2);

    g.printGraph();
}