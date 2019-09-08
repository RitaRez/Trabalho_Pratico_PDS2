#include<iostream>
#include<string>
#include<User.h>


#ifndef ADULT_H
#define ADULT_H
 
class Adult: public User{
    
private:

public:
    Adult(std::string id, std::string name, float budget);
};
 
#endif