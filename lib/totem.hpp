#ifndef TOTEM_H
#define TOTEM_H

#include <vector>
#include <map>

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"
#include "./box_office.hpp"

#include "./events/event.hpp"
#include "./events/infant_event.hpp"
#include "./events/puppet_show.hpp"
#include "./events/adult_event.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class Totem {
    
    private:
        std::vector<int> loggedId;
    
    public:
        Totem();   
        int login(BoxOffice *bf);
        void print_users(BoxOffice *bf);
        void print_events(BoxOffice *bf);
};

#endif