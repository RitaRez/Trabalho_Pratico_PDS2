#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <map> 

#include "../lib/box_office.hpp"


void output(BoxOffice *boxOffice){
    float max,min,avarage;

    std::cout 
        << "Número de usuários:" << std::endl
        << "Crianças: " << boxOffice->get_kids().size() << std::endl 
        << "Adultos: " << boxOffice->get_adults().size() + boxOffice->get_elders().size() << std::endl 
        << "Idosos: " << boxOffice->get_elders().size() << std::endl; 
    
    boxOffice->get_ages(&min,&max,&avarage);        
    std::cout << std::endl
        << "Idade dos usuários:" << std::endl
        << "Mínimo: " << max << std::endl
        << "Máximo: " << min << std::endl
        << "Média: " << std::setprecision(2) << std::fixed << avarage << std::endl;

    boxOffice->get_dependents(&min,&max,&avarage);        
    std::cout << std::endl
        << "Número de dependentes:" << std::endl << std::setprecision(0) << std::fixed
        << "Mínimo: " << max << std::endl
        << "Máximo: " << min << std::endl
        << "Média: " << std::setprecision(2) << std::fixed << avarage << std::endl;

    std::cout << std::endl << "Dependentes:"; 
    boxOffice->get_dependent_relations();

    std::cout << std::endl << "Número de eventos:" << std::endl
        << "Adultos:" << std::endl
        << '\t' << "Boate: " << boxOffice->get_clubs().size() << std::endl
        << '\t' << "Show: " << boxOffice->get_conserts().size() << std::endl
        << "Livres: " << std::endl
        << '\t' << "Cinema: " << boxOffice->get_movie_theaters().size() << std::endl
        << "Infantis: " << std::endl
        << '\t' << "Teatro de fantoches: " << boxOffice->get_puppet_shows().size() << std::endl;

    std::cout << std::endl << "Número de eventos que o usuário possui:" << std::endl;
    boxOffice->get_event_relations();

    std::cout << std::endl << "Evento com maior cota para idoso:" << std::endl;
    boxOffice->get_biggest_elder_amount();

    std::cout << std::endl << std::endl << "Numero de ingrecos por preco:" << std::endl;
    boxOffice->get_tickets();
}

int main(int argc, const char** argv) {
    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }

    BoxOffice *boxOffice = new BoxOffice(argv);
    output(boxOffice);
    delete(boxOffice);
    return 0;
}