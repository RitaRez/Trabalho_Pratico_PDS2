#include<iostream>
#include<string>

#ifndef USER_H
#define USER_H
 
class User {

private:
    std::string id;
    std::string category;
    std::string name;
    int age;
    float budget;
 
public:  
    std::string getId() { return id; }
    std::string getCategory() { return category; }
    std::string getName() { return name; }
    int getAge() { return age; }    
    float getBudget()  { return budget; }
};
 
#endif