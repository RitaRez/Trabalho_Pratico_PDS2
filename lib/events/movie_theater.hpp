#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
 
#include "event.hpp"

class MovieTheater: public Event {

    private:
        std::vector<int> movieSchedules;
        int runningTime;

    public:
        MovieTheater(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, std::vector<int> prices,
            std::vector<int> movieSchedules, int runningTime);
        
        int get_running_time(){return runningTime;}
        std::vector<int> get_movie_schedules(){ return movieSchedules;}

};
 
#endif