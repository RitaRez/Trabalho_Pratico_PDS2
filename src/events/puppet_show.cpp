#include "../../lib/events/puppet_show.hpp"

PuppetShow::PuppetShow(){}

PuppetShow::PuppetShow(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, std::vector<int> prices,
    std::vector<int> theaterSchedules){

    this->id = id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->theaterSchedules = theaterSchedules;
    
}