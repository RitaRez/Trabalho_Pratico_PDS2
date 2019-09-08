#include<iostream>
#include<string>

#ifndef EVENT_H
#define EVENT_H
 
class Event {

private:
    std::string id;
    std::string name;
    int numberOfTypes;

 
public:  
    std::string getId() { return id; }
    std::string getName() { return name; }
    int getNumberOfTypes()  { return numberOfTypes; }
};
 
#endif