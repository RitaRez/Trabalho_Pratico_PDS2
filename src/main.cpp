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
    for(std::set<int>::iterator it = bf->get_logged_id().begin(); it != bf->get_logged_id().end(); ++it){
        if(bf->get_adults()[*it] != nullptr){
            std::cout 
                << "\nNome: " << bf->get_adults()[*it]->get_name() 
                << "\nID: " << *it
                << "\nSaldo: " << bf->get_adults()[*it]->get_budget()
                << "\nQuantidade de ingressos adquiridos: " << bf->get_adults()[*it]->get_bought_tickets()
            << std::endl;
        }
        else if (bf->get_elders()[*it] != nullptr){
            std::cout 
                << "\nNome: " << bf->get_elders()[*it]->get_name() 
                << "\nID: " << *it
                << "\nSaldo: " << bf->get_elders()[*it]->get_budget()
                << "\nQuantidade de ingressos adquiridos: " << bf->get_elders()[*it]->get_bought_tickets()
            << std::endl;
        }
    }
}

void output_events(BoxOffice *bf){
    std::map<int, int>::iterator itr;
    int id, amount;
    std::cout << "\nEventos comprados: " << std::endl;
    if(!bf->get_bought_clubs().empty()){
        std::cout << "\nBoates: " << std::endl;
        for(itr = bf->get_bought_clubs().begin(); itr != bf->get_bought_clubs().end(); ++itr){
            std::cout 
                << itr->first << " - " << bf->get_clubs()[itr->first]->get_name()
                << "\nNumero de ingressos vendidos: " << itr->second
            << std::endl;    
        }
    }
    if(!bf->get_bought_conserts().empty()){
        std::cout << "\nShows: " << std::endl;
        for(itr = bf->get_bought_conserts().begin(); itr != bf->get_bought_conserts().end(); ++itr){
            std::cout 
                << itr->first << " - " << bf->get_conserts()[itr->first]->get_name()
                << "\nNumero de ingressos vendidos: " << itr->second
            << std::endl;    
        }
    }
    if(!bf->get_bought_movies().empty()){
        std::cout << "\nFilmes: "  << std::endl;
        for(itr = bf->get_bought_movies().begin(); itr != bf->get_bought_movies().end(); ++itr){
            std::cout 
                << itr->first << " - " << bf->get_movie_theaters()[itr->first]->get_name()
                << "\nNumero de ingressos vendidos: " << itr->second
            << std::endl;    
        }
    }    
    if(!bf->get_bought_puppet().empty()){
        std::cout << "\nTeatros de fantoche: " << std::endl;
        for(itr = bf->get_bought_puppet().begin(); itr != bf->get_bought_puppet().end(); ++itr){
            std::cout 
                << itr->first << " - " << bf->get_puppet_shows()[itr->first]->get_name()
                << "\nNumero de ingressos vendidos: " << itr->second
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