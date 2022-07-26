#include <iostream>
using namespace std;
//class shows why we need to override the copy assignment operator
class C {
	int size;
	int* c;
public: 
	C(int x) {
		size = x;
		c = new int[size];
		for (int i = 0; i < x; i++) {
			c[i] = i;
		}
	}

	C(C& o) {
		size = o.size;

		c = new int[size]; 
		for (int i = 0; i < size; i++) {
			c[i] = o.c[i];
		}
	}

	~C() {
		for (int i = 0; i < size; i++) {
			c[i] = 0;
		}

		delete[]c;
		cout << "end" << endl;
	}
};

int main()
{

	C c1(2); //c[0] 0 - 19, size 20
	C c2(3); //0 - 49

	c2 = c1; //c[0] , size 20
			
	C c3(4);

	return 0;
}