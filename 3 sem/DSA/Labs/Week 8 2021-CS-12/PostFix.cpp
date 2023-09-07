#include "TemplateStack.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    // Stack<int> S;

    string inpuit = "";
    cout<<"Enter Expression: ";
    cin >> inpuit;
    Stack<int> S;

    int len = inpuit.length();
    for(int i = 0; i < len; i++){
       
        if ( inpuit[i] >= '0' &&  inpuit[i] <= '9')
        {
            S.push( inpuit[i] - '0');
        }

        else{
            int first = S.pop();
            int second = S.pop();

            // cout<<first<<second;
            switch(inpuit[i]){
                
                case '+':
                    S.push(first + second);
                    break;
                case '-':
                    S.push(second-first);
                    break;
                case '*':
                    S.push(first*second);
                    break;
                case '/':
                // cout<<second<<" " <<first<<endl;
                    S.push(second / first);
                    break;
                case '^':
                    cout<<S.peek();
                    break;
            }
        }
    }
    cout<<S.peek();
}