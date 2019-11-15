#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
 
#include "event.hpp"
#include "../../lib/users/elder.hpp"


class MovieTheater: public Event {

    private:
        std::vector<int> movieSchedules;
        int runningTime;

    public:
        MovieTheater(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, std::vector<float> prices,
            std::vector<int> movieSchedules, int runningTime);
        static void print_movie_theaters(std::map<int,MovieTheater> movieTheaters);

        int get_running_time(){return runningTime;}
        std::vector<int> get_movie_schedules(){ return movieSchedules;}

};
 
#endif