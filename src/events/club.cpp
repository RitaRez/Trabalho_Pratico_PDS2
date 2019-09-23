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