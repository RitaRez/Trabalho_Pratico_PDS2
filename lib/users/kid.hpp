#ifndef KID_H
#define KID_H

#include "user.hpp"
 
class Kid: public User{
    
private:
    User resposible;

public:
    Kid();
    Kid(int id, std::string category, std::string name, int age, float budget, User responsible);

    User get_responsible(){return resposible;}
};
 
#endif