#include "../../lib/events/movie_theater.hpp"


MovieTheater::MovieTheater(int n_id, std::string n_category, std::string n_name, int n_responsible, std::vector<int> n_capacity, 
    std::vector<int> n_prices, std::vector<int> n_movieSchedules, int n_runningTime){

    id = n_id;
    category = n_category;
    name = n_name;
    responsible = n_responsible;
    capacity = n_capacity;
    prices = n_prices;
    movieSchedules = n_movieSchedules;
    runningTime = n_runningTime;

}