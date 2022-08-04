// תוכנית ראשונה
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
struct Restaurant
{
    char * name;
    int rating;
};
int main()
{
    ofstream fout("fout.bin");
    Restaurant restaurant;
    restaurant.rating = 10;
    restaurant.name = new char[20];
    strcpy(restaurant.name, "hapisga");;
    fout.write((char*)&restaurant, sizeof(Restaurant));
    fout.close();
    return 0;
}