class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};


A public member is accessible from anywhere outside the class but within a program. You can set and get the value of public variables without any member.

A private member variable or function cannot be accessed, or even viewed from outside the class. Only the class and friend functions can access private members.

A protected member variable or function is very similar to a private member but it provided one additional benefit that they can be accessed in child classes which are called derived classes.
    
########################################################################################################################################################
    
Public: All the class members declared under public will be available to everyone. The data members and member functions declared public can be accessed by other classes too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) with the object of that class.

    // C++ program to demonstrate public 
// access modifier 
  
#include<iostream> 
using namespace std; 
  
// class definition 
class Circle 
{ 
    public:  
        double radius; 
          
        double  compute_area() 
        { 
            return 3.14*radius*radius; 
        } 
      
}; 
  
// main function 
int main() 
{ 
    Circle obj; 
      
    // accessing public datamember outside class 
    obj.radius = 5.5; 
      
    cout << "Radius is:" << obj.radius << "\n"; 
    cout << "Area is:" << obj.compute_area(); 
    return 0; 
} 
Output:

Radius is:5.5
Area is:94.985
In the above program the data member radius is public so we are allowed to access it outside the class.
    
    ########################################################################################################################################################
    
    Private: The class members declared as private can be accessed only by the functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class.
Example:
// C++ program to demonstrate private 
// access modifier 
  
#include<iostream> 
using namespace std; 
  
class Circle 
{    
    // private data member 
    private:  
        double radius; 
       
    // public member function     
    public:     
        double  compute_area() 
        {   // member function can access private  
            // data member radius 
            return 3.14*radius*radius; 
        } 
      
}; 
  
// main function 
int main() 
{    
    // creating object of the class 
    Circle obj; 
      
    // trying to access private data member 
    // directly outside the class 
    obj.radius = 1.5; 
      
    cout << "Area is:" << obj.compute_area(); 
    return 0; 
} 
The output of above program will be a compile time error because we are not allowed to access the private data members of a class directly outside the class.
Output:

 In function 'int main()':
11:16: error: 'double Circle::radius' is private
         double radius;
                ^
31:9: error: within this context
     obj.radius = 1.5;
         ^
However we can access the private data members of a class indirectly using the public member functions of the class. Below program explains how to do this:

// C++ program to demonstrate private 
// access modifier 
  
#include<iostream> 
using namespace std; 
  
class Circle 
{    
    // private data member 
    private:  
        double radius; 
       
    // public member function     
    public:     
        double  compute_area(double r) 
        {   // member function can access private  
            // data member radius 
            radius = r; 
              
            double area = 3.14*radius*radius; 
              
            cout << "Radius is:" << radius << endl; 
            cout << "Area is: " << area; 
        } 
      
}; 
  
// main function 
int main() 
{    
    // creating object of the class 
    Circle obj; 
      
    // trying to access private data member 
    // directly outside the class 
    obj.compute_area(1.5); 
      
      
    return 0; 
} 
Output:

Radius is:1.5
Area is: 7.065
########################################################################################################################################################

    
Protected: Protected access modifier is similar to that of private access modifiers, the difference is that the class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class.
// C++ program to demonstrate 
// protected access modifier 
#include <bits/stdc++.h> 
using namespace std; 
  
// base class 
class Parent 
{    
    // protected data members 
    protected: 
    int id_protected; 
     
}; 
  
// sub class or derived class 
class Child : public Parent 
{ 
     
      
    public: 
    void setId(int id) 
    { 
          
        // Child class is able to access the inherited  
        // protected data members of base class 
          
        id_protected = id; 
          
    } 
      
    void displayId() 
    { 
        cout << "id_protected is:" << id_protected << endl; 
    } 
}; 
  
// main function 
int main() { 
      
    Child obj1; 
      
    // member function of derived class can 
    // access the protected data members of base class 
      
    obj1.setId(81); 
    obj1.displayId(); 
    return 0; 
} 
Output:

id_protected is:81    
    
    
    
https://www.geeksforgeeks.org/access-modifiers-in-c/ 
