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

void PuppetShow::print_puppet_shows(std::map<int,PuppetShow>& puppetShows, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::map<int, PuppetShow>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
    std::vector<int> schedules;
    int id;
    std::string responsible;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = puppetShows.begin(); itr != puppetShows.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        schedules = itr->second.get_schedules();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();

        std::cout << "\nPuppet Show: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        std::cout << "\nSchedules: ";    
        for (int i = 0; i < schedules.size(); i++)
            std::cout << "\n- " << schedules[i] << ":00";    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";  

        schedules.clear();
        capacity.clear();
        prices.clear();  
    } 
}