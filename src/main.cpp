#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <map> 
#include <stdlib.h>

#include "../lib/box_office.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/users/kid.hpp"
#include "../lib/users/adult.hpp"
#include "../lib/users/elder.hpp"


void output(BoxOffice *boxOffice){
    float max,min,avarage;

    std::cout 
        << "Numero de usuarios:" << std::endl
        << "Criancas: " << boxOffice->get_kids().size() << std::endl 
        << "Adultos: " << boxOffice->get_adults().size() + boxOffice->get_elders().size() << std::endl 
        << "Idosos: " << boxOffice->get_elders().size() << std::endl; 
    
    boxOffice->get_ages(&min,&max,&avarage);        
    std::cout << std::endl
        << "Idade dos usuarios:" << std::endl
        << "Minima: " << max << std::endl
        << "Maxima: " << min << std::endl
        << "Media: " << std::setprecision(2) << std::fixed << avarage << std::endl;

    boxOffice->get_dependents(&min,&max,&avarage);        
    std::cout << std::endl
        << "Numero de dependentes:" << std::endl << std::setprecision(0) << std::fixed
        << "Minimo: " << max << std::endl
        << "Maximo: " << min << std::endl
        << "Media: " << std::setprecision(2) << std::fixed << avarage << std::endl;

    std::cout << std::endl << "Dependentes:"; 
    boxOffice->get_dependent_relations();

    std::cout << std::endl << "Numero de eventos:" << std::endl
        << "Adultos:" << std::endl
        << '\t' << "Boate: " << boxOffice->get_clubs().size() << std::endl
        << '\t' << "Show: " << boxOffice->get_conserts().size() << std::endl
        << "Livres: " << std::endl
        << '\t' << "Cinema: " << boxOffice->get_movie_theaters().size() << std::endl
        << "Infantis: " << std::endl
        << '\t' << "Teatro de Fantoches: " << boxOffice->get_puppet_shows().size() << std::endl;

    std::cout << std::endl << "Numero de eventos que o usuario possui:" << std::endl;
    boxOffice->get_event_relations();

    std::cout << std::endl << "Evento com maior cota para idoso:" << std::endl;
    boxOffice->get_biggest_elder_amount();

    std::cout << std::endl << std::endl << "Numero de ingressos por preco:" << std::endl;
    boxOffice->get_tickets();
}

void print_users(BoxOffice *boxOffice){
    if(boxOffice == nullptr){
        system("clear");  
        throw DataNotLoadedException("Imprimir usuários e ventos", "Você não pode exibir usuários pois eles ainda não foram carregados!");
    } else {
        std::cout << "\n\nUsuarios: " << std::endl;
        Elder::print_elders(boxOffice->get_elders());
        Adult::print_adults(boxOffice->get_adults());
        Kid::print_kids(boxOffice->get_kids(),boxOffice->get_adults(), boxOffice->get_elders());
    }
    std::cout << "\n\nPressione alguma tecla para voltar ao menu principal!" << std::endl;
    char c;
    std::cin >> c;
    system("clear"); 

}

int menu_text(){
    int op;
    std::cout << "\nSISTEMA DE VENDA DE INGRESSOS\n" << std::endl;
    std::cout << "Favor escolher uma das opções abaixo:" << std::endl;

    std::cout << "\t1. Carregar usuarios e eventos" << std::endl;
    std::cout << "\t2. Exibir usuarios cadastrados" << std::endl;
    std::cout << "\t3. Comprar ingressos" << std::endl;
    std::cout << "\t4. Sair" << std::endl;
    
    std::cout << "Opção: ";
    std::cin >> op;
    
    return op;
}

int main(int argc, const char** argv) {
    system("clear"); 

    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }

    BoxOffice *boxOffice = NULL;
    int op = 0;
    
    while(op != 4){
        op = menu_text(); 
        switch(op) {
            case 1:
                boxOffice = new BoxOffice(argv);
                system("clear"); 
                std::cout << "Dados carregados! " << std::endl;
                break;
            case 2:    
                try { 
                    print_users(boxOffice);
                } catch(DataNotLoadedException e){
                    std::cout << e.what() << std::endl;
                }
                break;
            default:
                break;
        } 
    }
    
    delete(boxOffice);
    return 0;
}