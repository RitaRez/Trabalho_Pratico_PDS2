#include "../lib/users/kid.hpp"
#include "../lib/users/adult.hpp"

Adult::Adult(){}

Adult::Adult(int new_id, std::string new_category, std::string new_name, int new_age, float new_budget){
    id = new_id;
    category = new_category;
    name = new_name;
    age = new_age;
    budget = new_budget;
}

//void add_children(Kid::Kid kid){children.push_back(kid);}