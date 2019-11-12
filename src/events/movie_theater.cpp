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

void MovieTheater::print_movie_theaters(std::map<int,MovieTheater>& movieTheaters){
    std::map<int, MovieTheater>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
    std::vector<int> movieSchedules;
    int id;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = movieTheaters.begin(); itr != movieTheaters.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        movieSchedules = itr->second.get_movie_schedules();

        std::cout << "\nFilm: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nRunning time: " << itr->second.get_running_time() << " hours"
        << std::endl; 

        std::cout << "\nSchedules: ";    
        for (int i = 0; i < movieSchedules.size(); i++)
            std::cout << "\n- " << movieSchedules[i] << ":00";    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";  

        movieSchedules.clear();
        capacity.clear();
        prices.clear();  
    } 
}
