#ifndef KID_H
#define KID_H

#include "user.hpp"
 
class Kid: public User{
    
    private:
        int resposible;

    public:
        Kid();
        Kid(int id, std::string category, std::string name, int age, float budget, int responsible);

        static void print_kids(std::map<int,Kid>& kids, std::map<int,Adult>& adults, std::map<int,Elder>& elders);
        
        int get_responsible(){return resposible;}
};
 
#endif