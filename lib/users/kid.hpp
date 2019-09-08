#ifndef KID_H
#define KID_H

#include "user.hpp"
 
class Kid: public User{
    
private:
    User resposible;

public:
    Kid(std::string id, std::string name, float , User responsible);

    User get_responsible(){return resposible;}
};
 
#endif