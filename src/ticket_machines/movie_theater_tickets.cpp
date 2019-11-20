#include "../../lib/ticket_machines/movie_theater_tickets.hpp"

MovieTheaterTickets* MovieTheaterTickets::instance = NULL;

MovieTheaterTickets* MovieTheaterTickets::getInstance(){
    if(instance == NULL){
        instance = new MovieTheaterTickets();
    }else
        return instance;
}

MovieTheaterTickets::MovieTheaterTickets(){}