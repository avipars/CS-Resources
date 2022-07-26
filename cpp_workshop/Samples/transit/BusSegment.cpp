#include "BusSegment.h"
#include <iostream>
using namespace std;

BusSegment::BusSegment():Segment(), busStops(0){}
   
BusSegment::BusSegment(const char* s, const char* d, int b):Segment(s,d), busStops(b){}

BusSegment::~BusSegment(){}

void BusSegment::print(){
    Segment::print();
    cout<<"Bus stops: "<<busStops<<endl;
}

void BusSegment::setBusStops(int b){
    busStops = b;
}

int BusSegment::getBusStops(){
    return busStops;
}

float BusSegment::getPrice(){
    //price = stops * fare
    return busStops * price;
}