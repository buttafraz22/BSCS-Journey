#include <iostream>
#include "demo.h"
using namespace std;
int main(){
    AddTwoNumbers(1,2); cout <<endl;
    string row = "Afraz,Butt,12,UET-Lahore";

    for(int i = 1; i <= 4; i++){
        cout << parseData(row,i)<<"\t";
    }
}