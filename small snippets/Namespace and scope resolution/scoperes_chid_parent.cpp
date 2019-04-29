#include <iostream>

class A
{
    public:
        void f() { std::cout << "A::f()" << std::endl; }
};

class B : public A
{
    public:
        void f(int) { std::cout << "B::f(int)" << std::endl; }
};

int main() {
	B b;
        b.f(10); //ok
        b.f();  //error - as the function is hidden
                //b.A::f(); is correct

	return 0;
}
