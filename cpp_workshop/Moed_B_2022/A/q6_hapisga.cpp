#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring> //added this in for strcpy 
using namespace std;

//p1
struct Restaurant {
  char* name;
  int rating;
};


//p1
int main() {
  ofstream fout("fout.bin");
  Restaurant restaurant;
  restaurant.rating = 10;
  restaurant.name = new char[20];
  strcpy(restaurant.name, "hapisga");
  
  fout.write((char*)&restaurant, sizeof(Restaurant));
  fout.close();

  //p2
  
    ifstream fin("fout.bin");
    Restaurant rest;
    fin.read((char*)&rest, sizeof(Restaurant));
    cout << rest.name << endl;
    fin.close();
  

  return 0;
}