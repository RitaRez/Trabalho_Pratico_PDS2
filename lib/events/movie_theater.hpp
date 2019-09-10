#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
 
#include "event.hpp"

class MovieTheater: public Event {

private:
    std::vector<int> movieSchedules;
    int runningTime;

public:
    MovieTheater(int id, std::string category, std::string name, std::vector<int> capacity, std::vector<int> prices,
        std::vector<int> movieSchedules, int runningTime);
};
 
#endif