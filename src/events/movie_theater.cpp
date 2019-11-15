#include "../../lib/events/movie_theater.hpp"

MovieTheater::MovieTheater(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, 
    std::vector<float> prices, std::vector<int> movieSchedules, int runningTime){

    this->id = id;
    this->category = category;
    this->name = name;
    this->responsible = responsible;
    this->capacity = capacity;
    this->prices = prices;
    this->movieSchedules = movieSchedules;
    this->runningTime = runningTime;

}

void MovieTheater::print_movie_theaters(std::map<int,MovieTheater> movieTheaters){
    std::map<int, MovieTheater>::iterator itr; 
    std::vector<int> capacity;
    int c;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = movieTheaters.begin(); itr != movieTheaters.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        for (int i = 0; i < capacity.size(); i++)
            c += capacity[i];

        std::cout << "\nNome: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nClassificacao: Livre"
            << "\nCategoria: Cinema"
        << std::endl; 
            
        capacity.clear();
    } 
}
