#include "../lib/users/kid.hpp"
#include "../lib/users/elder.hpp"

Elder::Elder(){}

Elder::Elder(int new_id, std::string new_category, std::string new_name, int new_age, float new_budget){
    id = new_id;
    category = new_category;
    name = new_name;
    age = new_age;
    budget = new_budget;
}

