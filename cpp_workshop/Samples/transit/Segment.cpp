
#include <iostream>
#include <cstring>
#include "Segment.h"
using namespace std;

Segment::Segment(){
    strcpy(start, " ");
    strcpy(dest, " ");
}

Segment::Segment(const char* s, const char* d){
    strcpy(start, s);
    strcpy(dest, d);
}

Segment::~Segment(){
    strcpy(start, " ");
    strcpy(dest, " ");
}

void Segment::print(){
    cout<< "From: "<<start<<" To: "<<dest<<endl;
}

void Segment::setStart(const char* s){
    strcpy(start, s);
}

void Segment::setDest(const char* s){
    strcpy(dest, s);
}

const char* Segment::getStart(){
    return start;
}

const char *Segment::getDest(){
    return dest;
}