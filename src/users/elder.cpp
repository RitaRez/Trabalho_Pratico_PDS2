#include "../../lib/users/kid.hpp"
#include "../../lib/users/elder.hpp"

Elder::Elder(){}

Elder::Elder(int id, std::string category, std::string name, int age, float budget){
    this->id = id;
    this->category = category;
    this->name = name;
    this->age = age;
    this->budget = budget;
}

