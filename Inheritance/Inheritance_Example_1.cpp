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
   
/*
Explanation of the below notation:
The Class node is a nested class of B..So to create an object of class Node, the notation used is B::Node
Also we see a public inheritance of the Class A but only the structure Node in the class A, all other member functions and attributes irrespective of any access specifier used will be private and cannot be 
accessed directly by the nested class Node. Here in this situation the function call fun() inside the class Node will result in a compiler error, since the member 'c' of class A is actually visisible as private
variable here, although in originality it was aprotected variable
*/

   
    class Node : A::Node{       
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
    B::Node b;
    b.fun();
    return 0;
}