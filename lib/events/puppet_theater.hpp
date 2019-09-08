#ifndef PUPPETTHEATER_H
#define PUPPETTHEATER_H
 
#include "infant_event.hpp"

class PuppetTheater: public InfantEvent {

private:
    std::vector<int> theaterSchedules;

public:
    PuppetTheater(std::string id, std::string name, std::vector<int> capacity, std::vector<int> prices,
        std::vector<int> theaterSchedules);
};
 
#endif