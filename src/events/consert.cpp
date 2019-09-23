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