In C++, scope resolution operator is ::. It is used for following purposes.

1) To access a global variable when there is a local variable with same name:


// C++ program to show that we can access a global variable 
// using scope resolution operator :: when there is a local  
// variable with same name  
#include<iostream>  
using namespace std; 
   
int x;  // Global x 
   
int main() 
{ 
  int x = 10; // Local x 
  cout << "Value of global x is " << ::x; 
  cout << "\nValue of local x is " << x;   
  return 0; 
} 
Output:

Value of global x is 0
Value of local x is 10

