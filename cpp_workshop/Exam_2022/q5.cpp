//q5
#include <iostream>
using namespace std; 

class A{
    public: 
        void show1() {
            cout << "-A1-";

        }
        virtual void show2() {
            cout << "-A2-";
        }
};

class B : public A{
    public: 
        void show1() {
            cout << "-B1-";
        }
        void show2() {
            cout << "-B2-";
            A::show2();
        }
};

int main(){

    try{
        B* pA = new B;
        throw pA;
    }
    catch(A* x){
        x->show1();
        x->show2();
    }
    // catch(...){ //not relevant
    //     cout << "catch all" ;
    // }
}

//-A1--B2--A2-