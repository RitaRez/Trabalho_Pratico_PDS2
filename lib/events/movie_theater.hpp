#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
 
#include "event.hpp"

class MovieTheater: public Event {

private:
    std::vector<int> movieSchedules;
    int runningTime;

public:
    MovieTheater(std::string id, std::string name, std::vector<int> capacity, std::vector<int> prices,
        std::vector<int> movieSchedules, int runningTime);
};
 
#endif