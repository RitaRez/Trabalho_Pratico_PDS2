#include "../../lib/ticket_machines/consert_tickets.hpp"

ConsertTickets* ConsertTickets::instance = NULL;

ConsertTickets*  ConsertTickets::getInstance(){
    if(instance == NULL){
        instance = new ConsertTickets();
    }else
        return instance;
}

ConsertTickets::ConsertTickets(){}