#include<iostream>
#include<string>
#include<User.h>

#ifndef KID_H
#define KID_H
 
class Kid: public User{
    
private:
    User resposible;

public:
    Kid(std::string id, std::string name, float budget);

    User getResponsible(){return resposible;}
};
 
#endif