//one of the moed bet 2022 questions

#include <iostream>
using namespace std;

class A{
    public:
     static int num;
     A(){
        num++;
     }
};
class B {
  public:
    static int num;
  B() {
    num++;
  }
};

int A::num = 0;
int B::num = 0;

int main() {

  A a[5]; 
  B * b[5];
  cout << "A: " << A::num << endl;
  cout << "B: " << B::num << endl;
  return 0;
}

//output: A: 5
//B: 0