#include "../lib/box_office.hpp"
#include "../lib/file_parser.hpp"
#include "../lib/exceptions/data_not_loaded_exception.hpp"
#include "../lib/exceptions/invalid_entity_exception.hpp"

#include <iomanip>

BoxOffice::BoxOffice(){}

int BoxOffice::menu_text(){
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

void BoxOffice::initialize(const char** args){
    if(this->get_movie_theaters().empty() && this->get_puppet_shows().empty() && this->get_clubs().empty() && this->get_conserts().empty()){
        FileParser::parse_users((char *)args[1], kids, adults, elders);
        FileParser::parse_events((char *)args[2], clubs, conserts, puppetShows, movieTheaters, adults, elders);
        system("clear");
    } else {
        system("clear");
        throw DataNotLoadedException("Inicializar variaveis", "Você já carregou os dados!"); 
    }
}

void BoxOffice::print_users(){
    if(this->get_kids().empty() && this->get_adults().empty() && this->get_elders().empty()){
        system("clear");
        throw DataNotLoadedException("Imprimir usuários e ventos", "Você não pode exibir usuários pois eles ainda não foram carregados!");
    } else {
        std::cout << "\n\nIdosos: " << std::endl;
        Elder::print_elders(this->get_elders());
        std::cout << "\n\nAdultos (sem ser idosos): " << std::endl;
        Adult::print_adults(this->get_adults());
        std::cout << "\n\nCrianças: " << std::endl;
        Kid::print_kids(this->get_kids(),this->get_adults(), this->get_elders());
    }
    std::cout << "\n\nPressione alguma tecla para voltar ao menu principal!" << std::endl;
    char c;
    std::cin >> c;
    system("clear");

}

int BoxOffice::print_events(){

    if(this->get_movie_theaters().empty() && this->get_puppet_shows().empty() && this->get_clubs().empty() && this->get_conserts().empty()){
        system("clear");
        throw DataNotLoadedException("Imprimir usuários e eventos", "Você não pode exibir eventos pois eles ainda não foram carregados!");
    } else {
        std::cout << "\n\nFilmes: " << std::endl;
        MovieTheater::print_movie_theaters(this->get_movie_theaters());
        std::cout << "\n\nBoates: " << std::endl;
        Club::print_clubs(this->get_clubs());
        std::cout << "\n\nShows: " << std::endl;
        Consert::print_conserts(this->get_conserts());
        std::cout << "\n\nTeatros de Fantoche: " << std::endl;
        PuppetShow::print_puppet_shows(this->get_puppet_shows());

        int id;
        std::cout << "\nDigite o ID do evento desejado: " << std::endl;
        std::cin >> id;
        if(this->get_movie_theaters().count(id) == 0 && this->get_puppet_shows().count(id) == 0 && this->get_clubs().count(id) == 0 && this->get_conserts().count(id) == 0){
            system("clear");
            throw InvalidEntityException("Fazer login", "\nO evento não existe!");
        } else {
            return id;
        }
    }
}

int BoxOffice::login(){
    int id;
    if(this->get_kids().empty() && this->get_adults().empty() && this->get_elders().empty()){
        system("clear");
        throw DataNotLoadedException("Fazer login", "Você não pode logar pois os dados ainda não foram carregados!");
    } else {
        std::cout << "\nDigite um ID de adulto para logar: ";
        std::cin >> id;
        if(this->get_adults().find(id) == this->get_adults().end() && this->get_elders().find(id) == this->get_elders().end()){
            system("clear");
            throw InvalidEntityException("Fazer login", "\nO ID não existe ou pertence a uma criança!");
        } else {
            this->loggedId.push_back(id);
            system("clear");
            if(this->get_adults().find(id) == this->get_adults().end())
                std::cout << "\nBem vindo, " <<  this->get_elders()[id]->get_name() << std::endl;
            else
                std::cout << "\nBem vindo, " <<  this->get_adults()[id]->get_name() << std::endl;

        }
    }
}
