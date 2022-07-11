//q5
#include <iostream>
using namespace std; 

class A{
    public: 
        void show1() {
            cout << "-A1-"  << endl;

        }
        virtual void show2() {
            cout << "-A2-"  << endl;
        }
};

class B : public A{
    public: 
        void show1() {
            cout << "-B1-"  << endl;
        }
        void show2() {
            cout << "-B2-"  << endl;
            A::show2();
        }
};

int mainddd(){

    try{
        B* pA = new B;
        throw pA;
    }
    catch(A* x){
        x->show1();
        x->show2();
    }
    // catch(...){
    //     cout << "catch all" << endl;
    // }
}