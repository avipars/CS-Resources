// q9

#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
#include <list>
using namespace std;

class Order
{
public:
    class Food
    { // מאכל
        public:
            string name; // שם המאכל
            int code;    // קוד המאכל
            Food(string n, int c): name(n), code(c) {}
    };
    public: 
        //   Food(string myname, int mycode) : name(myname), code(mycode) {}
             Order(int myid) : id(myid){}
             void add(Food food);
             void print(); 

private:
    int id;                 // תז של הלקוח
    list<Food> listOfFoods; // רשימת המאכלים שהזמין
};

void Order::add(Food food) //student needs to fill in
{
    listOfFoods.push_back(food); //adds a new food item to the end of the linked list
}

void Order::print(){ //student fills in
//dont use the auto keyword (PER QUESTION)
    for(list<Food>::iterator it = listOfFoods.begin(); it != listOfFoods.end(); it++){
        cout << it->name << " - " << it->code << endl;
        //or 
        cout << (*it).name << " : " << (*it).code << endl;
    }
}

int main(){ //i added in after to test that the code actually works 
    Order order(1);
    Order::Food food1("pizza", 1);
    Order::Food food2("burger", 2);
    Order::Food food3("salad", 3);
    order.add(food1);
    order.add(food2);
    order.add(food3);
    order.print();

    return 0;
}