#include "../../lib/ticket_machines/puppet_tickets.hpp"

PuppetTickets* PuppetTickets::instance = NULL;

PuppetTickets* PuppetTickets::getInstance(){
    if(instance == NULL){
        instance = new PuppetTickets();
    }else
        return instance;
}

PuppetTickets::PuppetTickets(){}