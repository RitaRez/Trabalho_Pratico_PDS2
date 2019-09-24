#include "../../lib/events/consert.hpp"

Consert::Consert(){}

Consert::Consert(int id, std::string category, std::string  name, int  responsible, std::vector<int>  capacity, std::vector<float>  prices,
    int  elderAmount, int gateOpening, std::vector<std::string> artists){

    this->id =  id;
    this->category =   category;
    this->name =  name;
    this->responsible =  responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->elderAmount = elderAmount;
    this->gateOpening = gateOpening;
    this->artists = artists;

}

void Consert::print_conserts(std::map<int,Consert>& conserts, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::map<int, Consert>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
    std::vector<std::string> artists;
    int id;
    std::string responsible;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = conserts.begin(); itr != conserts.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        artists = itr-> second.get_artists();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();

        std::cout << "\nConsert: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nElder amount: " << itr->second.get_elder_amout() 
            << "\nGate opening time: " << itr->second.get_gate_opening() << ":00"
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        std::cout << "\nArtists: ";    
        for (int i = 0; i < artists.size(); i++)
            std::cout << "\n- " << artists[i];    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";   
        
        capacity.clear();
        prices.clear();
        artists.clear();
        
    } 
}
