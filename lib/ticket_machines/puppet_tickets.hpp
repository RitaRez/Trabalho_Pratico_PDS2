#ifndef PUPPET_TICKETS_H
#define PUPPET_TICKETS_H

#include "../totem.hpp"

class PuppetTickets: public Totem {
   private:
       static PuppetTickets* instance;
       PuppetTickets();
   public:
       static PuppetTickets* getInstance();
};

#endif
