#ifndef ADULT_H
#define ADULT_H

#include "user.hpp"

class Kid;
class Elder;

class Adult: public User{
    
    private:
        std::vector<int> children;
        
    public:
        Adult();
        Adult(int id, std::string category, std::string name, int age, float budget);

        static void print_adults(std::map<int,Adult>& adults);

        std::vector<int> get_children(){return children;}
        void add_children(int kid);

};
 
#endif