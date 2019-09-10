#include "../../lib/events/club.hpp"

Club::Club(){}

Club::Club(int n_id, std::string n_category, std::string n_name, int n_responsible, std::vector<int> n_capacity, std::vector<int> n_prices,
    int n_elderAmount, int n_startingTime, int n_endingTime){

    id = n_id;
    category = n_category;
    name = n_name;
    responsible = n_responsible;
    capacity = n_capacity;
    prices = n_prices;
    elderAmount = n_elderAmount;
    startingTime = n_startingTime;
    endingTime = n_endingTime;

}
