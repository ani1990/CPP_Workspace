#include <iostream>

using namespace std;
class A
{
protected:
    int k;
private :
    int x;

};
class B : public A
{
public:
    void fun()
    {
        //cout << "x-val =" << k <<endl;
        cout << "x-val =" << x <<endl; //Gives compile error with x is private to A.so cant access even in B
    }
private :
    int y;

};

int main()
{
    //std::vector<ColorRGB> image;
    cout << "Hello world!" << endl;
    //srand(clock());
        return 0;
}
