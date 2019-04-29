In C++, scope resolution operator is ::. It is used for following purposes.
##############################################################################
1) To access a global variable when there is a local variable with same name:
##############################################################################

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
   
#########################################################################
2) To define a function outside a class.
#########################################################################

// C++ program to show that scope resolution operator :: is used 
// to define a function outside a class 
#include<iostream>  
using namespace std; 
  
class A  
{ 
public:   
   // Only declaration 
   void fun(); 
}; 
  
// Definition outside class using :: 
void A::fun() 
{ 
   cout << "fun() called"; 
} 
  
int main() 
{ 
   A a; 
   a.fun(); 
   return 0; 
} 
Output:

fun() called

#########################################################################
3) To access a class’s static variables.
#########################################################################
// C++ program to show that :: can be used to access static 
// members when there is a local variable with same name 
#include<iostream> 
using namespace std; 
   
class Test 
{ 
    static int x;   
public: 
    static int y;    
  
    // Local parameter 'a' hides class member 
    // 'a', but we can access it using :: 
    void func(int x)   
    {  
       // We can access class's static variable 
       // even if there is a local variable 
       cout << "Value of static x is " << Test::x; 
  
       cout << "\nValue of local x is " << x;   
    } 
}; 
   
// In C++, static members must be explicitly defined  
// like this 
int Test::x = 1; 
int Test::y = 2; 
   
int main() 
{ 
    Test obj; 
    int x = 3 ; 
    obj.func(x); 
   
    cout << "\nTest::y = " << Test::y; 
  
    return 0; 
} 
Output:

Value of static x is 1
Value of local x is 3
Test::y = 2;

#########################################################################
4) In case of multiple Inheritance:
#########################################################################
If same variable name exists in two ancestor classes, we can use scope resolution operator to distinguish.

// Use of scope resolution operator in multiple inheritance. 
#include<iostream> 
using namespace std; 
  
class A 
{ 
protected: 
    int x; 
public: 
    A() { x = 10; } 
}; 
  
class B 
{ 
protected: 
    int x; 
public: 
    B() { x = 20; } 
}; 
  
class C: public A, public B 
{ 
public: 
   void fun() 
   { 
      cout << "A's x is " << A::x; 
      cout << "\nB's x is " << B::x; 
   } 
}; 
  
int main() 
{ 
    C c; 
    c.fun(); 
    return 0; 
}
Output:

A's x is 10
B's x is 20

#########################################################################
   5
#########################################################################   
You can also use the class scope operator to qualify class names or class member names.
If a class member name is hidden, you can use it by qualifying it with its class name and the class scope operator.

In the following example, the declaration of the variable X hides the class type X,
but you can still use the static class member count by qualifying it with the class type X and the scope resolution operator.
   
 #include <iostream>
using namespace std;

class X
{
public:
      static int count;
};
int X::count = 10;                // define static data member

int main ()
{
      int X = 0;                  // hides class type X
      cout << X::count << endl;   // use static member of class X
}  
