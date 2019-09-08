#ifndef CLUB_H
#define CLUB_H
 
#include "adult_event.hpp"

class Club: public AdultEvent {

private:
    int startingTime;
    int endingTime;

public:  
    
    Club(std::string id, std::string name, std::vector<int> capacity, std::vector<int> prices,
        int startingTime, int endingTime);

    int get_starting_time(){return startingTime;}
    int get_ending_time(){return endingTime;} 
};
 
#endif