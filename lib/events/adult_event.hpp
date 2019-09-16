#ifndef ADULTEVENT_H
#define ADULTEVENT_H
 
#include "event.hpp"

class AdultEvent: public Event {

    protected:
        int elderAmount;  

    public:
        int get_elder_amout(){return elderAmount;}
};
 
#endif