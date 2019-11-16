#include "../../lib/ticket_machines/puppet_tickets.hpp"

PuppetTickets* PuppetTickets::getInstance(){
    instance = NULL;
    if(instance == NULL){
        instance = new PuppetTickets();
    }else
        return instance;
}