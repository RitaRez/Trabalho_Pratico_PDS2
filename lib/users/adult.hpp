#ifndef ADULT_H
#define ADULT_H

#include "user.hpp"
#include "kid.hpp"


class Adult: public User{
    
private:
    std::vector<Kid> children;
public:
    Adult(std::string id, std::string name, float budget);
};
 
#endif