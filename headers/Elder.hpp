#include<iostream>
#include<string>
#include<Adult.h>

#ifndef ELDER_H
#define ELDER_H
 
class Elder: public Adult{
    
private:

public:
    Elder(std::string id, std::string name, float budget);
};
 
#endif