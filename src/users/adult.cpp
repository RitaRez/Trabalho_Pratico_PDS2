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

void Adult::print_adults(std::map<int,Kid>& kids, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::map<int, Adult>::iterator itr; 
    int id;
    
    for (itr = adults.begin(); itr != adults.end(); ++itr) {
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget()
        << std::endl; 
    } 
}
