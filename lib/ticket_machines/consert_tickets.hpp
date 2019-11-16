#ifndef CONSERT_TICKETS_H
#define CONSERT_TICKETS_H

#include "../totem.hpp"

class ConsertTickets: public Totem {
   private:
       static ConsertTickets* instance;
       ConsertTickets();
   public:
       static ConsertTickets* getInstance();
};

#endif