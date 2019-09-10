#ifndef CONSERT_H
#define CONSERT_H
 
#include "adult_event.hpp"

class Consert: public AdultEvent {

private:
    int gateOpening;
    std::vector<std::string> artists;

public:  
    Consert();
    Consert(int id, std::string category, std::string name, std::vector<int> capacity, std::vector<int> prices,
        int elderAmount, int gateOpening, std::vector<std::string> artists);

    int get_gate_opening(){return gateOpening;}
    std::vector<std::string> get_artists(){return artists;} 
};
 
#endif