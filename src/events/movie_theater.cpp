#include "../../lib/events/movie_theater.hpp"


MovieTheater::MovieTheater(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, 
    std::vector<int> prices, std::vector<int> movieSchedules, int runningTime){

    this->id = id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->movieSchedules = movieSchedules;
    this->runningTime = runningTime;

}