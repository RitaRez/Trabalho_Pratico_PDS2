#include "../../lib/users/kid.hpp"

Kid::Kid(){}

Kid::Kid(int id, std::string category, std::string name, int age, float budget, int responsible){
    this->id = id;
    this->category = category;
    this->name = name;
    this->age = age;
    this->budget = budget;
    this->responsible = responsible;
}

void Kid::print_kids(std::map<int,Kid> kids, std::map<int,Adult> adults, std::map<int,Elder> elders){
    std::map<int, Kid>::iterator itr; 
    int id;
    std::string responsible;
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        //id = itr->second.get_responsible();
        
        // if(adults.find(id) != adults.end())
        //     responsible = adults[id].get_name();
        // else 
        //     responsible = elders[id].get_name();
                
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nNome: " << itr->second.get_name() 
            << "\nCategoria: Criança" 
            << "\nIdade: " << itr->second.get_age() 
            << "\nSaldo: " << itr->second.get_budget() 
            << "\nID do responsavel:" << itr->second.get_responsible()
        << std::endl; 
    } 
}
