#include "../../lib/events/club.hpp"

Club::Club(){}

Club::Club(std::string n_id, std::string n_name, std::vector<int> n_capacity, std::vector<int> n_prices,
    int n_elderAmount, int n_startingTime, int n_endingTime){

    id = n_id;
    name = n_name;
    capacity = n_capacity;
    prices = n_prices;
    elderAmount = n_elderAmount;
    startingTime = n_startingTime;
    endingTime = n_endingTime;

}
