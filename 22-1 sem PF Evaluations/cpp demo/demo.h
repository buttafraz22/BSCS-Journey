#include <iostream>
using namespace std;

void AddTwoNumbers(int a, int b){
    cout << a+b;
}
string parseData(string row,int field){
    string item;
    int commansCount = 1;
    for(int i = 0; i < row.length(); i++){
        if(row[i] == ',')   commansCount++;

        else if(commansCount == field){
            item = item + row[i];
        }
    }
    return item;
}