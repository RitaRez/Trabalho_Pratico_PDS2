#include "../../lib/events/club.hpp"

Club::Club(){}

Club::Club(int n_id, std::string n_category, std::string name, int responsible, std::vector<int> capacity, std::vector<float> prices,
    int elderAmount, int startingTime, int endingTime){

    this->id = id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->elderAmount = elderAmount;
    this->startingTime = startingTime;
    this->endingTime = endingTime;

}

void Club::print_clubs(std::map<int,Club>& clubs){
    std::map<int, Club>::iterator itr; 
    std::vector<int> capacity;
    int c = 0;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    for (itr = clubs.begin(); itr != clubs.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        for (int i = 0; i < capacity.size(); i++)
            c += capacity[i];
         
        std::cout << "\nNome: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nClassificacao: Adulto"
            << "\nNúmero de ingressos: " << c 
        << std::endl;   

        capacity.clear();
    } 
}
