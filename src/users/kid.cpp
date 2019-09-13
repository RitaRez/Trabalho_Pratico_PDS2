#include "../../lib/users/kid.hpp"

Kid::Kid(){}

Kid::Kid(int id, std::string category, std::string name, int age, float budget, int responsible){
    this->id = id;
    this->category = category;
    this->name = name;
    this->age = age;
    this->budget = budget;
    this->resposible = responsible;
}

    