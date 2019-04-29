#include <iostream>

int a = 10;
namespace M
{
    int a = 20;
    namespace N
    {
           int a = 30;
           void f()
           {
              int x = a; //a refers to the name inside N, same as M::N::a
              int y = M::a; //M::a refers to the name inside M
              int z = ::a; //::a refers to the name in the global namespace

              std::cout << x << ", "<< y << ", " << z << std::endl; //30,20,10
           }
    }
}
int main() 
{
    M::N::f();
}