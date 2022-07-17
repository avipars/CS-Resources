//q3
#include <iostream>
using namespace std;

class A;

class B{
    public:    
        void foo();
};

class A{
    public:
        B b;
        int field;
        friend class B;
};

void B:: foo(){
    A a;
    cout << a.field;
}

int main(){
    //bonus/irrelevant things I added
    // cout << "dkdkd";
   // B b;
  //  A a;
   // a.field = 1; //added in after

   // b.foo();

    return 0;
}
