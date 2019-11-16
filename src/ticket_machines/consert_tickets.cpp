#include "../../lib/ticket_machines/consert_tickets.hpp"

ConsertTickets*  ConsertTickets::getInstance(){
    instance = NULL;
    if(instance == NULL){
        instance = new ConsertTickets();
    }else
        return instance;
}