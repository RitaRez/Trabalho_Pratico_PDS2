#include "../../lib/ticket_machines/movie_theater_tickets.hpp"

MovieTheaterTickets* MovieTheaterTickets::getInstance(){
    instance = NULL;
    if(instance == NULL){
        instance = new MovieTheaterTickets();
    }else
        return instance;
}

