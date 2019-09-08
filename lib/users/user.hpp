#ifndef USER_H
#define USER_H
 
#include <iostream>
#include <string>
#include <vector>


class User {

private:
    std::string id;
    std::string category;
    std::string name;
    int age;
    float budget;
 
public:  
    std::string get_id() { return id; }
    std::string get_category() { return category; }
    std::string get_name() { return name; }
    int get_age() { return age; }    
    float get_budget()  { return budget; }
};
 
#endif