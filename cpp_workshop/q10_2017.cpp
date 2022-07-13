//code from 2017 midterm 
#include <iostream>

using namespace std;

class A{
    protected:
        int *pA;
        public:
            A(int a){
                pA = new int(a);
                cout << "a ctor" << endl;
            }
           virtual  ~A(){ //added virtual
                delete pA;
                cout << "a dtor" << endl;
            }
};

class B: public A{
    private:
        int *pB;
    public:
        B(int a,int b):A(b){
            pB = new int(b);
            cout << "b ctor" << endl;
        }
        ~B(){
            delete pB;
            cout << "b dtor" << endl;
        }
};

int main(){
    A* x = new B(2,3); 
    //print b ctor and b dtor
    delete x;
    return 0;
}