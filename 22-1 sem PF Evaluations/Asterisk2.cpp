#include<iostream>
using namespace std;

int main()
{
    int i,j,spaces,rows,k;
    string m;
    cout << "Enter number of rows:   " ;
    cin >> rows ; 
   //   rows = 5;
    k=rows;
    m=" ";
    
   
   for ( i = 0 ; i <= rows ; i++) //loop for number of rows
    {
        for ( j = 0; j < i ; j++) // loop for printing first triangle with *
        {
           cout << "*" ;
        }
        

        for ( spaces = (rows*2)-1 ;  spaces >= (i*2) ; spaces--) //loop for spacing
        {
           cout << " " ;   
        }

        for ( j = 0 ; j < i ; j++) // loop for printing second triangle with *
        {
           cout << "*" ;
        }

        cout << "\n" ;


        //end of inner loop 
    
    }
   return 0;
}