#include "../../lib/users/kid.hpp"
#include "../../lib/users/adult.hpp"

Adult::Adult(){}

Adult::Adult(int id, std::string category, std::string name, int age, float budget){
    this->id = id;
    this->category = category;
    this->name = name;
    this->age = age;
    this->budget = budget;
}

void Adult::add_children(int kid){
    children.push_back(kid);
}

