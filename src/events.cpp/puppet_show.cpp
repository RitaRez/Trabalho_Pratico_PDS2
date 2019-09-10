#include "../../lib/events/puppet_show.hpp"

PuppetShow::PuppetShow(){}

PuppetShow::PuppetShow(std::string n_id, std::string n_name, std::vector<int> n_capacity, std::vector<int> n_prices,
    std::vector<int> n_theaterSchedules){

    id = n_id;
    name = n_name;
    capacity = n_capacity;
    prices = n_prices;
    theaterSchedules = n_theaterSchedules;
    
}