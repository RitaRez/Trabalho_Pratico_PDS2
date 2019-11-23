#ifndef MOVIE_THEATER_TICKETS_H
#define MOVIE_THEATER_TICKETS_H

#include "../totem.hpp"

class MovieTheaterTickets: public Totem {
    
    private:
        static MovieTheaterTickets* instance;
    
    public:
        MovieTheaterTickets();       
        static MovieTheaterTickets* getInstance();
        
        void time_exists(int time, std::vector<int> schedule);
	    void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) override;
        void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l) override; 
        void emit_ticket(BoxOffice *boxOffice, int id_event, int tickets, int price) override;
        int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted);
        int get_current_price(BoxOffice *boxOffice, int id_event);
};

#endif
