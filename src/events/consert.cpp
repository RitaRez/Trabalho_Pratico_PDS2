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

void Consert::print_conserts(std::map<int,Consert> conserts){
    std::map<int, Consert>::iterator itr; 
    std::vector<int> capacity;
    int c = 0;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = conserts.begin(); itr != conserts.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        for (int i = 0; i < capacity.size(); i++)
            c += capacity[i];

        std::cout << "\n\nNome: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nClassificacao: Adulto"
            << "\nCategoria: Show"
            << "\nNúmero de ingressos: " << c 
        << std::endl;   
        
        capacity.clear();
    } 
}
