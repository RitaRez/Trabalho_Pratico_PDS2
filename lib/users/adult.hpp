#ifndef ADULT_H
#define ADULT_H

#include "user.hpp"

class Kid;
class Elder;

class Adult: public User{
    
    private:
        std::vector<int> children;
        int boughtTickets = 0;
        
    public:
        Adult();
        Adult(int id, std::string category, std::string name, int age, float budget);

        static void print_adults(std::map<int,Adult*> adults);

        std::vector<int> get_children(){return children;}
        void add_children(int kid);
        int get_bought_tickets(){return this->boughtTickets;}
        void increase_bought_tickets(){this->boughtTickets++;}

};
 
#endif