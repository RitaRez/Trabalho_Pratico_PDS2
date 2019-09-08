#include "../lib/users/kid.hpp"

Kid::Kid(){}

Kid::Kid(int new_id, std::string new_category, std::string new_name, int new_age, float new_budget, User new_responsible){
    id = new_id;
    category = new_category;
    name = new_name;
    age = new_age;
    budget = new_budget;
    resposible = new_responsible;
}

    