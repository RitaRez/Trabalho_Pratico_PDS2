#include "../../lib/events/club.hpp"

Club::Club(){}

Club::Club(int n_id, std::string n_category, std::string name, int responsible, std::vector<int> capacity, std::vector<float> prices,
    int elderAmount, int startingTime, int endingTime){

    this->id = n_id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->elderAmount = elderAmount;
    this->startingTime = startingTime;
    this->endingTime = endingTime;

}

void Club::print_clubs(std::map<int,Club*> clubs){
    std::map<int, Club*>::iterator itr; 
    int c = 0;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    for (itr = clubs.begin(); itr != clubs.end(); ++itr) { 
        for (int i = 0; i < itr->second->get_capacity().size(); i++)
            c += itr->second->get_capacity()[i];
         
        std::cout << "\n\n" << itr->second->get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->first 
            << "\nClassificacao: Adulto"
            << "\nCategoria: Boate"
            << "\nNúmero de ingressos: " << c 
        << std::endl;   
    } 
}
