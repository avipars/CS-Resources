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
    return 0;
}