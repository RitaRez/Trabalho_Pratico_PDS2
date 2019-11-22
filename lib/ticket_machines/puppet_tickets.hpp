#ifndef PUPPET_TICKETS_H
#define PUPPET_TICKETS_H

#include "../totem.hpp"

class PuppetTickets: public Totem {
    
    private:
        static PuppetTickets* instance;
    
    public:
        PuppetTickets();  
        static PuppetTickets* getInstance();
	    
        void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) override;
        void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l) override;
        void emit_ticket(BoxOffice, int id_event, int price) override;
        int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted);
        int get_current_price(BoxOffice *boxOffice, int id_event);
        void time_exists(int time, std::vector<int> schedule);   



};

#endif
