#include "../../lib/events/puppet_show.hpp"

PuppetShow::PuppetShow(){}

PuppetShow::PuppetShow(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, std::vector<float> prices,
    std::vector<int> theaterSchedules){

    this->id = id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->theaterSchedules = theaterSchedules;
    
}

void PuppetShow::print_puppet_shows(std::map<int,PuppetShow> puppetShows){
    std::map<int, PuppetShow>::iterator itr; 
    std::vector<int> capacity;
    int c;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = puppetShows.begin(); itr != puppetShows.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        for (int i = 0; i < capacity.size(); i++)
            c += capacity[i];

        std::cout << "\nNome: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nClassificacao: Infantil"
            << "\nCategoria: Teatro de fantoches"
        << std::endl; 
            
        capacity.clear(); 
    } 
}