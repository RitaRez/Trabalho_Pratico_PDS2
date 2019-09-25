#ifndef ELDER_H
#define ELDER_H
 
#include "kid.hpp"
#include "adult.hpp"

class Elder: public Adult{
    
    private:

    public:
        Elder();
        Elder(int id, std::string category, std::string name, int age, float budget);

        static void print_elders(std::map<int,Elder>& elders);
};
 
#endif