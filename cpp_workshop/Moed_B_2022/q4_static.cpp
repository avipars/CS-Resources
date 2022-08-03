class A {
public:
static int num;
A() { num++; }
};
int A::num = 0;
class B {
public:
static int num;
B() { num++; }
};
int B::num = 0;
int main() {
A a[5];
B* b[ 5];
cout << A::num << " " << B::num << endl;
}