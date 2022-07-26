#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <class T>
void print(T beg, T end){
    if(beg != end){
        print(++beg, end); //recursive call 
        while(beg != end){
            cout << *beg << " "; //print value
            beg++; //increment pointer
        }
        cout << endl;
    }
}

int main(){
    list <int> l; 
    for(int i = 0; i < 10; i+=2){
        l.push_front(i); //push to the front of the list
    }
    list<int>:: iterator it = l.begin(); //iterator to the beginning of the list

    for_each(it, l.end(), [](int i){ //simply print the original list
        cout << i << " ";
    });
    cout << endl;

    cout << "final list: " << endl;
    print(l.rbegin(), l.rend()); //print the list in reverse order
    return 0;
}

/*
output:
8 6 4 2 0 

8 
6 8
4 6 8
2 4 6 8
*/