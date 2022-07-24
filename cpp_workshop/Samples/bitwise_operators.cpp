//bitwise operators

#include <iostream>


using namespace std;

int main(){
    
    int x = 6; 
    int y = 5;
    if ((x & y) != 0) {
        cout << "x and y are not equal" << endl;
    }
    else{
        cout << "x and y are equal" << endl;
    }

    if ((x | y) != 0) { 
        cout << "x or y are not equal" << endl;
    }
    else{
        cout << "x or y are equal" << endl;
    }

    cout <<  "left shift 5 by 1 " << (5 << 1) << endl;
    cout <<  "right shift 5 by 1 " << (5 >> 1) << endl;
    cout <<  "left shift 5 by 2 " << (5 << 2) << endl;
    cout <<  "right shift 5 by 2 " << (5 >> 2) << endl;

    //xor
    cout <<  "xor 5 and 3 " << (5 ^ 3) << endl;
    //not (2s comp)
    cout <<  "not 5 " << (~5) << endl;

    return 0;
}