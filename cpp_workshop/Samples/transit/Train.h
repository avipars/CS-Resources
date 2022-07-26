#include "Segment.h"
#pragma once

class Train: public Segment {
    protected:
        int trainPlat = 0;
        float price = 10; //price per stop
    public:
        Train();
        Train(const char* s, const char* d, int b);
        ~Train();
        void print();
        void setTrainStops(int b);
        int getTrainStops();
        float getPrice();
};