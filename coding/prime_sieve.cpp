#include <iostream>
using namespace std;

#define UPPER_BOUND 100
int main() {
	//sieve of erathosenes
	//use an array to see if we colored a number or not

	bool arr[UPPER_BOUND] = {false}; 
	//default garbage value for us is true, but for the checker... it's false - so now the first would be false and the rest zero (always fills rest with zeros)
	
	for (int i = 2; i < UPPER_BOUND; ++i) {
		if (!arr[i]) { //zero is prime number, so we can print it
			cout << i << ","; 
		}

		for (int j = i; j < UPPER_BOUND; j += i) {
			arr[j] = true; 
		}
	}

	return 0; 
}
