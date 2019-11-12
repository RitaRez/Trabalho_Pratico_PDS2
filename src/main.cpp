#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <map> 
#include <stdlib.h>

#include "../lib/totem.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/exceptions/invalid_entity_exception.hpp"

// void output(Totem *totem){
//     float max,min,avarage;

//     std::cout 
//         << "Numero de usuarios:" << std::endl
//         << "Criancas: " << totem->get_kids().size() << std::endl 
//         << "Adultos: " << totem->get_adults().size() + totem->get_elders().size() << std::endl 
//         << "Idosos: " << totem->get_elders().size() << std::endl; 
    
//     totem->get_ages(&min,&max,&avarage);        
//     std::cout << std::endl
//         << "Idade dos usuarios:" << std::endl
//         << "Minima: " << max << std::endl
//         << "Maxima: " << min << std::endl
//         << "Media: " << std::setprecision(2) << std::fixed << avarage << std::endl;

//     totem->get_dependents(&min,&max,&avarage);        
//     std::cout << std::endl
//         << "Numero de dependentes:" << std::endl << std::setprecision(0) << std::fixed
//         << "Minimo: " << max << std::endl
//         << "Maximo: " << min << std::endl
//         << "Media: " << std::setprecision(2) << std::fixed << avarage << std::endl;

//     std::cout << std::endl << "Dependentes:"; 
//     totem->get_dependent_relations();

//     std::cout << std::endl << "Numero de eventos:" << std::endl
//         << "Adultos:" << std::endl
//         << '\t' << "Boate: " << totem->get_clubs().size() << std::endl
//         << '\t' << "Show: " << totem->get_conserts().size() << std::endl
//         << "Livres: " << std::endl
//         << '\t' << "Cinema: " << totem->get_movie_theaters().size() << std::endl
//         << "Infantis: " << std::endl
//         << '\t' << "Teatro de Fantoches: " << totem->get_puppet_shows().size() << std::endl;

//     std::cout << std::endl << "Numero de eventos que o usuario possui:" << std::endl;
//     totem->get_event_relations();

//     std::cout << std::endl << "Evento com maior cota para idoso:" << std::endl;
//     totem->get_biggest_elder_amount();

//     std::cout << std::endl << std::endl << "Numero de ingressos por preco:" << std::endl;
//     totem->get_tickets();
// }



int main(int argc, const char** argv) {
    system("clear"); 

    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }

    Totem *totem = new Totem();
    int op = 0;
    
    while(op != 4){
        op = totem->menu_text(); 
        switch(op) {
            case 1:
                totem->initialize(argv) ;
                system("clear"); 
                std::cout << "Dados carregados! " << std::endl;
                break;
            case 2:    
                try { 
                    totem->print_users();
                } catch(DataNotLoadedException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                try{
                    totem->login();
                    totem->print_events();
                } catch (InvalidEntityException e){
                    std::cout << e.what() << std::endl;
                }    
                break;
            default:
                break;
        } 
    }
    
    delete(totem);
    return 0;
}