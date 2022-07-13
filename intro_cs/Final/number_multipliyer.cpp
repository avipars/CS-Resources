#include <iostream>
using namespace std;

//works finally!
int multiplyNumber(int original){
    int result = 0; 
    //print that digit the amount of times it is in the number
    
    int num = original; //copy the value to keep original intact
    int digit_place = 1; //10's hundred place, etc.

    while(num){ //run till hits zero
        //add all numbers together to get the # of digits
        int digit = num % 10; //get the last digit
        num /= 10; //divide the number by 10 

        //add the number to the result
        for(int i = 0; i < digit; i++){
            result += digit * digit_place; //add the digit to the result
            digit_place *= 10; //multiply the digit place by 10
        }
    }
    
    return result;
}

int main()
{
    int original = 0;
    cout << "Enter a number: ";
    cin >> original;
    cout << "Result: " << multiplyNumber(original) << endl;

    return 0; 
}