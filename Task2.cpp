//CPP Program to create a simple calculator

#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"======================Simple Calculator======================\n";
    cout<< "Enter a value:";
    cin>> a;
    cout<< "Enter b value:";
    cin>> b;

    int ch;
    cout<<"Options Menu: \n";
    cout<< "1. Addition\n";
    cout<< "2. Subtraction \n";
    cout<< "3. Multipication \n";
    cout<< "4. Division \n";
    cout<< "5. Remainder \n";
    cout<<"Enter your choice: ";
    cin>>ch;
    
    switch(ch){
        case 1: 
              cout<<"The addition of the numbers is:" << a+b ;
              break;
        case 2: 
              cout<<"The subtraction of the numbers is:" << a-b ;
              break;
        case 3: 
              cout<<"The multiplication of the numbers is:" << a*b ;
              break;
        case 4: 
              cout<<"The division of the numbers is:" << a/b ;
              break;
        case 5: 
              cout<<"The remainder of the numbers is:" << a%b ;
              break;
        default: cout<< "Invalid number entered" ;
    }
    return 0;
}