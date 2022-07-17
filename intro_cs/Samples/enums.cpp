/*
	This file takes 3 inputs (2 numbers and operator) and does math functions if operator is relevant
	Excercise 3 Question 3
 */

#include <iostream>
using namespace std;

//initialize enum with the different math functions
enum Operator { //we were told to use enums in the global scope 
	ADD = '+',
	SUB = '-',
	MULT = '*',
	DIV = '/'
};

int main() {
	char oper;
	int first, last;
	//receive user input for 2 numbers
	cout << "enter 2 numbers: " << endl;
	cin >> first >> last; //stores the numbers

	cout << "enter an operator: " << endl;
	cin >> oper; //gets math symbol

	switch (oper)
	{
	case ADD:
		cout << first << " " << '+' << " " << last << " = " << first + last << endl;
		break;
	case SUB:
		cout << first << " " << '-' << " " << last << " = " << first - last << endl;
		break;
	case MULT:
		cout << first << " " << '*' << " " << last << " = " << first * last << endl;
		break;
	case DIV:
		if (last == 0)
		{ //divide by zero is undefined
			cout << "ERROR" << endl;
		}
		else
		{
			cout << first << " " << '/' << " " << last << " = " << (float)first / last << endl;
			//we want to cast to float to account for any decimal points
		}
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	return 0;
}