//q4
#include <iostream>
using namespace std;

class A{
    public: 
        A(){
            cout << "def" << endl;

        }
       A(const A& a){
            cout << "copy" << endl;
        }
        A(const A&& a){
            cout << "move" << endl;
        }
};

void func1(){
    A a;
}

A func2(){
    A a;
    return a;
}
void func3(A a){
}

void func4(A& a){
}

int main(){
    A a1;
    A a2(a1);
    func1();
    func2();
    func3(a1);
    func4(a1);
}

//in vscode it doesn't call the move ctor