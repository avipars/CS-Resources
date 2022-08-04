#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
struct Restaurant
{
char* name;
int rating;
};
int main()
{
ifstream fin("fout.bin");
Restaurant rest;
fin.read((char*)&rest, sizeof(Restaurant));
cout << rest.name << endl;
fin.close();
return 0;
}