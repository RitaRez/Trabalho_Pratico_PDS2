#ifndef CLUB_TICKETS_H
#define CLUB_TICKETS_H

#include "../totem.hpp"

class ClubTickets: public Totem {
    private:
        static ClubTickets* instance;
        ClubTickets();
    public:
        static ClubTickets* getInstance();
};

#endif