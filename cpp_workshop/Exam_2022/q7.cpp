//q7
#include <iostream>
using namespace std; 

bool f(int x){
    unsigned int y = x & 0x0000001; //bit mask 
    y <<=31; //shift left 31 bits
    
    return y;
}

void print(int count){

    for (int i = 0; i < count; i++)
    {
        /* code */
        cout << i << " " << (f(i) ? "true" : "false") << endl;
    }
    
}
int maijjjhhjn()
{
    // print(30);
   // unsigned int left = 
    //cout << (unsigned int)(5 << 31) << endl;

    return 0;
}