#ifndef ADULT_H
#define ADULT_H

#include "user.hpp"
#include "kid.hpp"


class Adult: public User{
    
private:
    std::vector<Kid> children;
    
public:
    Adult();
    Adult(int id, std::string category, std::string name, int age, float budget);

    std::vector<Kid> get_children(){return children;}
    void add_children(Kid *kid);

};
 
#endif