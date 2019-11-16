#ifndef MOVIE_THEATER_TICKETS_H
#define MOVIE_THEATER_TICKETS_H

#include "../totem.hpp"

class MovieTheaterTickets: public Totem {
   private:
       static MovieTheaterTickets* instance;
       MovieTheaterTickets();
   public:
       static MovieTheaterTickets* getInstance();
};

#endif
