#ifndef CONSERT_TICKETS_H
#define CONSERT_TICKETS_H

#include "../totem.hpp"

class ConsertTickets: public Totem {
    
    private:
        static ConsertTickets* instance;
    
    public:
        ConsertTickets();
        static ConsertTickets* getInstance();
	    
        void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) override;
        void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l) override;
        void emit_ticket(BoxOffice, int id_event, int price) override;
        int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted);
        int get_current_price(BoxOffice *boxOffice, int id_event);

};

#endif