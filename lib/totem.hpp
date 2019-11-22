#ifndef TOTEM_H
#define TOTEM_H

#include <vector>
#include <map>

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"
#include "./box_office.hpp"

#include "./events/puppet_show.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class Totem {
    
    public:
        Totem();
        static Totem* factoryMethod(BoxOffice *boxOffice, int id);
	    virtual void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) = 0;
        virtual void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l) = 0;
        virtual void emit_ticket(BoxOffice, int id_event, int price) = 0;
        
        int get_total_price(Event *mt, int id_event, int ticketsWanted);
        void change_capacity(Event *mt, int id_event, int ticketsWanted);

};

#endif
