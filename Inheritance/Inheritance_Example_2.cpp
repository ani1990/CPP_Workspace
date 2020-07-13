#include <iostream>

using namespace std;



class A{
public: 
   A(){
       
   }
   struct Node{
     int x;
     int y;
   };
   
   void fun(void){
      cout << "Hello World" << endl;
   }
    
   protected:
      int c = 9;
};

class B : public A{
public:
    B(){
        
    }
    
    class Node : public A{   /* here the nested class Node inherits the complete Class A(unlike Inheritance_Example.cpp) as public inheritance . 
	the  'public' keyword before A is optional here */
    public:
        Node(){}
        void fun(void){
            cout << A::c << endl;
        }
        
    };
    
    void fun1(void){
        cout << A::c << endl;
    }
};

int main()
{
    B::Node *b = new B::Node;    /* new keyword : Create a new object on the heap instead of stack of nested type Node of Class B  and assign to the respective pointer*/
    b->fun();
    return 0;
}