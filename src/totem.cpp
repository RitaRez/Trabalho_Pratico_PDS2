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

#include <iomanip>

Totem::Totem(){}

Totem* Totem::factoryMethod(BoxOffice *boxOffice, int id){
    if(boxOffice->get_movie_theaters().count(id) > 0){
        return MovieTheaterTickets::getInstance();
    } else if(boxOffice->get_puppet_shows().count(id) > 0){
        return PuppetTickets::getInstance();;
    } else if(boxOffice->get_clubs().count(id) > 0){
        return ClubTickets::getInstance();;
    } else if(boxOffice->get_conserts().count(id) > 0){
        return ConsertTickets::getInstance();;
    } else
        return NULL;
}