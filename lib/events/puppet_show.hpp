#ifndef PUPPETSHOW_H
#define PUPPETSHOW_H
 
#include "infant_event.hpp"

class PuppetShow: public InfantEvent {

private:
    std::vector<int> theaterSchedules;

public:
    PuppetShow();
    PuppetShow(std::string id, std::string name, std::vector<int> capacity, std::vector<int> prices,
        std::vector<int> theaterSchedules);
};
 
#endif