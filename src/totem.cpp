#include "../lib/totem.hpp"
#include "../lib/box_office.hpp"
#include "../lib/file_parser.hpp"
#include "../lib/events/event.hpp"
#include "../lib/ticket_machines/puppet_tickets.hpp"
#include "../lib/ticket_machines/consert_tickets.hpp"
#include "../lib/ticket_machines/club_tickets.hpp"
#include "../lib/ticket_machines/movie_theater_tickets.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/exceptions/invalid_entity_exception.hpp"
#include "../lib/exceptions/not_enough_tickets_exception.hpp"


#include <iomanip>

Totem::Totem(){}

Totem* Totem::factoryMethod(BoxOffice *boxOffice, int id){
    if(boxOffice->get_clubs()[id] != nullptr){
        return ClubTickets::getInstance();
    } 
    else if(boxOffice->get_puppet_shows()[id] != nullptr){
        return PuppetTickets::getInstance();
    } 
    else if(boxOffice->get_movie_theaters()[id] != nullptr){
        return MovieTheaterTickets::getInstance();
    } 
    else if(boxOffice->get_conserts()[id] != nullptr)
        return ConsertTickets::getInstance();
    else{
        std::cout << "Evento nao existe";
        return NULL;
    }    
}


int Totem::get_total_price(Event *mt, int id_event, int ticketsWanted){
    int t = 0, p = 0;
    int totalPrice = 0;
    for (int i = 0; i < mt->get_capacity().size(); i++){
        if(ticketsWanted < mt->get_capacity()[i]){
            totalPrice += ticketsWanted*mt->get_prices()[i];
            break;
        }
        t = ticketsWanted - mt->get_capacity()[i];
        p = mt->get_prices()[i];
        totalPrice += t*p;
        ticketsWanted -= t;
    } 
    return totalPrice;
}

void Totem::change_capacity(Event *mt, int id_event, int ticketsWanted){
    for (int i = 0; i < mt->get_capacity().size(); i++){
        if(ticketsWanted < mt->get_capacity()[i]){
            mt->set_capacity(ticketsWanted, i);
            break;
        }
        ticketsWanted -= mt->get_capacity()[i];
        mt->get_capacity()[i] = 0;
    }    
}