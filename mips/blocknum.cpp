//I sometimes wrote code for mips first in CPP then translated them to assembly myself

#include <iostream>
using namespace std;


int main(){

    //using cache we have a block # and # of blocks in cache
    // which give us the resulting block#1

    cout << "enter a block #: " << endl;
    int block_num;
    cin >> block_num;

    cout << "enter # of blocks in cache: " << endl;
    int num_blocks;
    cin >> num_blocks;

    //fully associative cache only
    cout << "block # in cache: " << block_num % num_blocks << endl;
    return 0;
}