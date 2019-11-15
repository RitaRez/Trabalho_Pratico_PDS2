#include "../lib/totem.hpp"
#include "../lib/box_office.hpp"
#include "../lib/file_parser.hpp"
#include "../lib/events/event.hpp"
#include "../lib/ticket_machines/puppet_tickets.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/exceptions/invalid_entity_exception.hpp"

#include <iomanip>

Totem::Totem(){}

void Totem::print_users(BoxOffice *boxOffice){
    if(boxOffice->get_kids().empty() && boxOffice->get_adults().empty() && boxOffice->get_elders().empty()){
        system("clear");  
        throw DataNotLoadedException("Imprimir usuários e ventos", "Você não pode exibir usuários pois eles ainda não foram carregados!");
    } else {
        std::cout << "\n\nIdosos: " << std::endl;
        Elder::print_elders(boxOffice->get_elders());
        std::cout << "\n\nAdultos (sem ser idosos): " << std::endl;
        Adult::print_adults(boxOffice->get_adults());
        std::cout << "\n\nCrianças: " << std::endl;
        Kid::print_kids(boxOffice->get_kids(),boxOffice->get_adults(), boxOffice->get_elders());
    }
    std::cout << "\n\nPressione alguma tecla para voltar ao menu principal!" << std::endl;
    char c;
    std::cin >> c;
    system("clear"); 

}

void Totem::print_events(BoxOffice *boxOffice){
    
    if(boxOffice->get_movie_theaters().empty() && boxOffice->get_puppet_shows().empty() && boxOffice->get_clubs().empty() && boxOffice->get_conserts().empty()){
        system("clear");  
        throw DataNotLoadedException("Imprimir usuários e eventos", "Você não pode exibir eventos pois eles ainda não foram carregados!");
    } else {
        std::cout << "\n\nFilmes: " << std::endl;
        MovieTheater::print_movie_theaters(boxOffice->get_movie_theaters());        
        std::cout << "\n\nBoates: " << std::endl;
        Club::print_clubs(boxOffice->get_clubs());
        std::cout << "\n\nShows: " << std::endl;
        Consert::print_conserts(boxOffice->get_conserts());
        std::cout << "\n\nTeatros de Fantoche: " << std::endl;
        PuppetShow::print_puppet_shows(boxOffice->get_puppet_shows());
          
        int id;
        std::cout << "\nDigite o ID do evento desejado: " << std::endl;
        std::cin >> id;
        if(boxOffice->get_movie_theaters().count(id) == 0 && boxOffice->get_puppet_shows().count(id) == 0 && boxOffice->get_clubs().count(id) == 0 && boxOffice->get_conserts().count(id) == 0){
            system("clear");  
            throw InvalidEntityException("Fazer login", "\nO evento não existe!");
        } else {
            if(boxOffice->get_movie_theaters().count(id) > 0){
                std::cout << "É AQUI Q CE INSTANCIA A MAQUINA DE CINEMA\n";
            } else if(boxOffice->get_puppet_shows().count(id) > 0){
                std::cout << "É AQUI Q CE INSTANCIA A MAQUINA DE FANTOCHE\n";
            } else if(boxOffice->get_clubs().count(id) > 0){
                std::cout << "É AQUI Q CE INSTANCIA A MAQUINA DE BOATE\n";
            } else if(boxOffice->get_conserts().count(id) > 0){
                std::cout << "É AQUI Q CE INSTANCIA A MAQUINA DE SHOW\n";
            }
        }
    }
}

int Totem::login(BoxOffice *boxOffice){
    int id;
    if(boxOffice->get_kids().empty() && boxOffice->get_adults().empty() && boxOffice->get_elders().empty()){
        system("clear");  
        throw DataNotLoadedException("Fazer login", "Você não pode logar pois os dados ainda não foram carregados!");
    } else { 
        std::cout << "\nDigite um ID de adulto para logar: ";
        std::cin >> id;
        if(boxOffice->get_adults().find(id) == boxOffice->get_adults().end() && boxOffice->get_elders().find(id) == boxOffice->get_elders().end()){
            system("clear");  
            throw InvalidEntityException("Fazer login", "\nO ID não existe ou pertence a uma criança!");
        } else {
            this->loggedId.push_back(id);  
            system("clear");
            if(boxOffice->get_adults().find(id) == boxOffice->get_adults().end())
                std::cout << "\nBem vindo, " <<  boxOffice->get_elders()[id].get_name() << std::endl;     
            else
                std::cout << "\nBem vindo, " <<  boxOffice->get_adults()[id].get_name() << std::endl;     

        }
    }    
}
