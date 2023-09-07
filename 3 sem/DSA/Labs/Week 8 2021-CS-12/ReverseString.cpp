#include "TemplateStack.h"
#include<iostream>
using namespace std;

int main(){
    Stack<string> S;
    string sentence = "I am from University of Engineering and Technology Lahore";
    sentence += " "; //This is so that the last word will also get pushed on the stack again

    string placeHolder = "";
    
    int size = sentence.length();
    int count = 0;

    for(int i = 0; i < size; i++){
        if(sentence[i] == ' '){
            S.push(placeHolder);
            count++;
            placeHolder = "";
            continue;
        }
        placeHolder += sentence[i];
    }

    
    for(int i = 0; i < count; i++){
        placeHolder += S.pop();
        placeHolder += " ";
    }
    
    cout<<placeHolder<<endl;

    return 0;

}