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

void PuppetShow::print_puppet_shows(std::map<int,PuppetShow*> puppetShows){
    std::map<int, PuppetShow*>::iterator itr; 
    int c = 0;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = puppetShows.begin(); itr != puppetShows.end(); ++itr) { 
        for (int i = 0; i < itr->second->get_capacity().size(); i++)
            c += itr->second->get_capacity()[i];

        std::cout << "\n\n" << itr->second->get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->first
            << "\nClassificacao: Infantil"
            << "\nCategoria: Teatro de fantoches"
            << "\nNúmero de ingressos: " << c
        << std::endl;             
    } 
}