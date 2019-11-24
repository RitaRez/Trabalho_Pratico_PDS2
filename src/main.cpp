#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <set> 
#include <map> 
#include <stdlib.h>

#include "../lib/totem.hpp"
#include "../lib/box_office.hpp"
#include "../lib/events/club.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/exceptions/invalid_entity_exception.hpp"
#include "../lib/exceptions/ticket_unavailable_exception.hpp"
#include "../lib/exceptions/not_enough_tickets_exception.hpp"

void output_users(BoxOffice *bf){    
    system("clear");
    std::cout << "Usuarios que compraram ingressos: " << std::endl;
    if(bf->get_logged_id().empty())
        std::cout << "Nenhum usuario comprou ingresso!" << std::endl;
    for(auto const& adults: bf->get_logged_id()){
        if(bf->get_adults()[adults] != nullptr){
            std::cout 
                << "\nNome: " << bf->get_adults()[adults]->get_name() 
                << "\nID: " << adults
                << "\nSaldo: " << bf->get_adults()[adults]->get_budget()
                << "\nQuantidade de ingressos adquiridos: " << bf->get_adults()[adults]->get_bought_tickets()
            << std::endl;
        }
        else if (bf->get_elders()[adults] != nullptr){
            std::cout 
                << "\nNome: " << bf->get_elders()[adults]->get_name() 
                << "\nID: " << adults
                << "\nSaldo: " << bf->get_elders()[adults]->get_budget()
                << "\nQuantidade de ingressos adquiridos: " << bf->get_elders()[adults]->get_bought_tickets()
            << std::endl;
        }
    }
}

void output_events(BoxOffice *bf){

    std::cout << "\n\nEventos comprados: " << std::endl;
    if(!bf->get_bought_clubs().empty()){
        std::cout << "\nBoates: " << std::endl;
        for(auto const& clubs: bf->get_bought_clubs()){
            std::cout 
                << clubs.first << " - " << bf->get_clubs()[clubs.first]->get_name()
                << "\nNumero de ingressos vendidos: " << clubs.second
            << std::endl;    
        }
    }
    if(!bf->get_bought_conserts().empty()){
        std::cout << "\nShows: " << std::endl;
        for(auto const& conserts: bf->get_bought_conserts()){
            std::cout 
                << conserts.first << " - " << bf->get_conserts()[conserts.first]->get_name()
                << "\nNumero de ingressos vendidos: " << conserts.second
            << std::endl;    
        }
    }
    if(!bf->get_bought_movies().empty()){
        std::cout << "\nFilmes: "  << std::endl;
        for(auto const& movies: bf->get_bought_movies()){
            std::cout 
                << movies.first << " - " << bf->get_movie_theaters()[movies.first]->get_name()
                << "\nNumero de ingressos vendidos: " << movies.second
            << std::endl;    
        }
    }    
    if(!bf->get_bought_puppet().empty()){
        std::cout << "\nTeatros de fantoche: " << std::endl;
        for(auto const& puppet: bf->get_bought_puppet()){
            std::cout 
                << puppet.first << " - " << bf->get_puppet_shows()[puppet.first]->get_name()
                << "\nNumero de ingressos vendidos: " << puppet.second
            << std::endl;    
        }
    }    
    if(bf->get_bought_clubs().empty() && bf->get_bought_conserts().empty() && bf->get_bought_movies().empty() && bf->get_bought_puppet().empty())
        std::cout << "Nenhum ingresso foi comprado!" << std::endl;
}

int main(int argc, const char** argv) {
    system("clear"); 

    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }

    BoxOffice *boxOffice = new BoxOffice();    

    Totem* machine;
    int event = -1, user, op = 0;

    while(op != 4){
        op = boxOffice->menu_text(); 
        switch(op) {
            case 1:
                try { 
                    boxOffice->initialize(argv) ;
                    std::cout << "Dados carregados! " << std::endl;
                } catch(DataNotLoadedException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 2:    
                try { 
                    boxOffice->print_users();
                } catch(DataNotLoadedException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                try{
                    user = boxOffice->login();
                    event = boxOffice->print_events();
                    machine = Totem::factoryMethod(boxOffice, event);
                    machine->sell_tickets(boxOffice, event, user);
                } catch (InvalidEntityException e){
                    std::cout << e.what() << std::endl;
                } catch (DataNotLoadedException e) {
                    std::cout << e.what() << std::endl;
                } catch (TicketUnavailableException e){
                    std::cout << e.what() << std::endl;
                } catch (NotEnoughtTicketsException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                output_users(boxOffice);
                output_events(boxOffice);
                boxOffice->free_maps();
                break;       
            default:
                break;
        } 
    }
    if(event != -1)
        delete(machine);
    delete(boxOffice);
    return 0;
}