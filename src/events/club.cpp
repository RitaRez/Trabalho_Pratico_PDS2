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

void Club::print_clubs(std::map<int,Club>& clubs, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::map<int, Club>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
    int id;
    std::string responsible;


    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    for (itr = clubs.begin(); itr != clubs.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();
         
        std::cout << "\nClub: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nElder amount: " << itr->second.get_elder_amout() 
            << "\nStarting Time: " << itr->second.get_starting_time() << ":00"
            << "\nEnding Time: " << itr->second.get_ending_time() << ":00"
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";   

        capacity.clear();
        prices.clear();

    } 
}
