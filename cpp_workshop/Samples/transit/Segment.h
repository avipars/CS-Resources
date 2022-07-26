#define MAX_LEN 31 //30 and null char
#pragma once

class Segment{ 
    protected:
        //start and dest point in char array
        char start[MAX_LEN];
        char dest[MAX_LEN];
    public:
        Segment(); 
        Segment(const char* s, const char* d);
        virtual ~Segment();
        virtual void print();
        void setStart(const char* s);
        void setDest(const char* d);
        const char* getStart();
        const char* getDest();
        virtual float getPrice() = 0;
};