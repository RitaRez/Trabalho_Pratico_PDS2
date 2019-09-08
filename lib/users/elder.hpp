#ifndef ELDER_H
#define ELDER_H
 
#include "adult.hpp"

class Elder: public Adult{
    
private:

public:
    Elder(std::string id, std::string name, float budget);
};
 
#endif