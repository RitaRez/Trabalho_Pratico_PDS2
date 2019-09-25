#ifndef CONSERT_H
#define CONSERT_H
 
#include "adult_event.hpp"
#include "../../lib/users/elder.hpp"


class Consert: public AdultEvent {

    private:
        int gateOpening;
        std::vector<std::string> artists;

    public:  
        Consert();
        Consert(int id, std::string category, std::string name, int responsible, std::vector<int> capacity, std::vector<float> prices,
            int elderAmount, int gateOpening, std::vector<std::string> artists);

        static void print_conserts(std::map<int,Consert>& conserts, std::map<int,Adult>& adults, std::map<int,Elder>& elders);

        
        int get_gate_opening(){return gateOpening;}
        std::vector<std::string> get_artists(){return artists;} 
};
 
#endif