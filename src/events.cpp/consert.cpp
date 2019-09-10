#include "../../lib/events/consert.hpp"

Consert::Consert(){}

Consert::Consert(int n_id, std::string n_category, std::string n_name, std::vector<int> n_capacity, std::vector<int> n_prices,
    int n_elderAmount, int n_gateOpening, std::vector<std::string> n_artists){

    id = n_id;
    category =  n_category;
    name = n_name;
    capacity = n_capacity;
    prices = n_prices;
    elderAmount = n_elderAmount;
    gateOpening = n_gateOpening;
    artists = n_artists;

}