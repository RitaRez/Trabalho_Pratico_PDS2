#include "../../lib/ticket_machines/club_tickets.hpp"

ClubTickets*  ClubTickets::getInstance(){
    instance = NULL;
    if(instance == NULL){
        instance = new ClubTickets();
    }else
        return instance;
}