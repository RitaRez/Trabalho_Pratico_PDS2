#ifndef ELDER_H
#define ELDER_H
 
#include "adult.hpp"

class Elder: public Adult{
    
    private:

    public:
        Elder();
        Elder(int id, std::string category, std::string name, int age, float budget);

        void print();
};
 
#endif