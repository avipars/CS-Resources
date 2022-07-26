#include "BusSegment.h"
#include "Train.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float calcPrice(vector<Segment*> segments){
    float price = 0;
    for(int i = 0; i < segments.size(); i++){
        price += segments[i]->getPrice();
    }
    return price;
}

int main(){
    vector<Segment*> modes = {new BusSegment("Grand Central", "Penn Station", 6), new Train("Penn Station", "NYC", 2), new BusSegment("NYC", "Grand Central", 4)};
    modes.push_back(new BusSegment("NYC", "Grand Central", 7));
    modes.push_back(new Train("Grand Central", "Detroit", 15));

    for_each(modes.begin(), modes.end(), [](Segment* s){
        s->print();
    });

    cout<<"Total price: "<<calcPrice(modes)<<endl;
    return 0;
}