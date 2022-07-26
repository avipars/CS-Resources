#include <iostream>
#include <time.h>
using namespace std;
//example of accessing static members
class St {
private:
	double mark;
	static int num;
	int n = 45;
public: 
	St() { num++; mark = rand() % 100; }
	~St() { num--; }

	static double avg(St* arr) { //given an instance as a paramater, we now can access internal fields and methods!
		double sum = 0;
		for (int i = 0; i < num; i++) {
			sum += arr[i].mark;
			arr[i].mark = 66; //can even modify it 
		}
		return sum / num; 
	}

	static int getChangeNum() { //not allowed
		n += 5; 
		return n;
	}

	static int getChangeNumSt() { //allowed
		num += 5;
		return num;
	}

	
};

int St::num = 0; //init static field

int main() {

	srand(time(NULL));
	St arr[5];
	cout << arr[0].avg(arr) << endl;  //both access the static method
	cout << St::avg(arr) << endl; //same as above 
	St a; //new instance
	cout << a.getChangeNum() << endl;
	cout << St::getChangeNum() << endl;

	return 0;
}