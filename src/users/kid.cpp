#include "../../lib/users/kid.hpp"
#include "../../lib/users/adult.hpp"
#include "../../lib/users/elder.hpp"

#include <iostream>
#include <map>

Kid::Kid(){}

Kid::Kid(int id, std::string category, std::string name, int age, float budget, int responsible){
    this->id = id;
    this->category = category;
    this->name = name;
    this->age = age;
    this->budget = budget;
    this->resposible = responsible;
}

void Kid::print_kids(std::map<int,Kid>& kids, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::map<int, Kid>::iterator itr; 
    int id;
    std::string responsible;
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();
                
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget() 
            << "\nResponsible's name:" << responsible
        << std::endl; 
    } 
}
