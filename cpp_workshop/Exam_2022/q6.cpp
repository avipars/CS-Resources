//q6
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student{
    char name[15];
    int mark;
};

int mainfgff(){
    ofstream outfle("fout.bin");
    Student fSt; 
    fSt.mark = 90; 
    strcpy(fSt.name, "avi");
    outfle.write((char*)&fSt, sizeof(Student));
    outfle.close();

    ifstream infile("fout.bin");
    Student sT;
    infile.read((char*)&sT, sizeof(fSt));
    cout << sT.name << endl;

    infile.close();
    return 0;
}