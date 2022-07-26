#include "Train.h"
#include <iostream>
using namespace std;
Train::Train():Segment(), trainPlat(0){}

Train::Train(const char* s, const char* d, int b):Segment(s,d), trainPlat(b){}

Train::~Train(){}

void Train::print(){
    Segment::print();
    cout<<"Train stops: "<<trainPlat<<endl;
}

void Train::setTrainStops(int b){
    trainPlat = b;
}

int Train::getTrainStops(){
    return trainPlat;
}

float Train::getPrice(){
    return trainPlat * price;
}