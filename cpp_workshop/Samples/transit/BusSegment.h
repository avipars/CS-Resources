#include "Segment.h"
#pragma once

class BusSegment : public Segment {
    protected:
        int busStops;
        float price = 0.5; //price per stop
    public:
        BusSegment();
        BusSegment(const char* s, const char* d, int b);
        ~BusSegment();
        void print();
        void setBusStops(int b);
        int getBusStops();
        float getPrice();
};