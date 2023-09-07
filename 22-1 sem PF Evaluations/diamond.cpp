#include <iostream>
using namespace std;

int main() {
    cout << "Enter number of rows ";
    int n;
    cin >> n;
    
    for(int i = 0; i < n ; i++){   // row iterator
        for(int j = 0; j < n - i ; j++){    // Logic of spaces
            cout << " ";
        }
        for(int k = 0; k < 2 * i - 1; k++){   // Logic of stars in upper equliateral triangle
            cout << '*';
        }
        cout<<endl;
    }
    
    for(int i = n - 1; i > 0; i--){   // row iterator
        for (int j = 0; j < n - i; j++) {    // Logic of spaces
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {    // Logic of stars in the lower equilateral triangle
            cout << '*';
        }
        cout<<endl;
    }

    return 0;
}