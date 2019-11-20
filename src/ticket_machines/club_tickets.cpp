#include "../../lib/ticket_machines/club_tickets.hpp"

ClubTickets* ClubTickets::instance = NULL;

ClubTickets*  ClubTickets::getInstance(){
    if(instance == NULL){
        instance = new ClubTickets();
    }else
        return instance;
}

ClubTickets::ClubTickets(){}