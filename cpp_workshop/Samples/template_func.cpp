#include <iostream>
using namespace std;

template <class T1>
T1 f(T1 x,T1 y){
    return (x+y)/2;
}

int main(){
    int x  = 65, y = 66;
    cout << f<int>(x,y) << endl;
    cout << f<float>(x,y) << endl;
    cout << f<char>(x,y) << endl;
    return 0;
}
