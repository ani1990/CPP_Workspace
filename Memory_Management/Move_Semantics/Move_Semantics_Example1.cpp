#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
class Printer{
    public:
       void Print(const string & str){ // the operator & is used for lvalue reference
           some_str = str;
           cout << "lvalue :" << str << endl;
       }
       
       void Print(string && str){    // the operator && here is used for rvalues
           some_str = std::move(str);
           cout << "rvalue :" << some_str << endl;
       }
    private:
       string some_str;
};


int main(){
    Printer printer;
    string str = "Hi";
    printer.Print(str);
    printer.Print("Hello");
    
    cout << &str <<  " " << str << endl;
    printer.Print(std::move(str));   // std::move assigns the str as rvalue
    
    cout << &str << " " << str << endl;
    return 0;
}

/* The Move function is used to modify the ownership of a memory region. To perform a modification in ownership, the identifier holding the
memory block needs to be updated from lvalue to rvalue . std::move() performs this modification. The operator '&&' is used to retreive rvalues.
So now the object printer has the ownership of the memory region held by the identifier - str after the line execution - 30. Although this is not
very useful here, since the object printer is only alive till the main function executes. But consider a situation of multi-thread programming. 
Here even though one of the threads is no longer alive, still the memmory location can be reused. */