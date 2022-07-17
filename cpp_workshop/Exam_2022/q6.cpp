//q6
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student{
    char name[15];
    int mark;
};

int main(){
    ofstream outfle("fout.bin"); //output to file
    Student fSt; 
    fSt.mark = 90; 
    strcpy(fSt.name, "avi"); 
    outfle.write((char*)&fSt, sizeof(Student));
    outfle.close();

    ifstream infile("fout.bin"); //read from file
    Student sT;
    infile.read((char*)&sT, sizeof(fSt));
    cout << sT.name << endl; //print student name

    infile.close();
    return 0;
}