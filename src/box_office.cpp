#include "../lib/box_office.hpp"
#include "../lib/file_parser.hpp"
#include "../lib/events/event.hpp"
#include "../lib/ticket_machines/puppet_tickets.hpp"
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
    FileParser::parse_users((char *)args[1], kids, adults, elders);
    FileParser::parse_events((char *)args[2], clubs, conserts, puppetShows, movieTheaters, adults, elders);
    system("clear"); 
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
        Totem* machine;
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
                std::cout << "\nBem vindo, " <<  this->get_elders()[id].get_name() << std::endl;
            else
                std::cout << "\nBem vindo, " <<  this->get_adults()[id].get_name() << std::endl;

        }
    }
}

void BoxOffice::get_ages(float *max, float *min, float *avarage){
    std::map<int, Kid>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::map<int, Elder>::iterator itr3; 
    
    *max = 0;
    *avarage = 0;
    int userCount = kids.size() + adults.size() + elders.size();
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        if(*avarage == 0)
            *min = itr->second.get_age();
        if(itr->second.get_age() < *min)
            *min = itr->second.get_age();
        if(itr->second.get_age() > *max)
            *max = itr->second.get_age();
        *avarage += itr->second.get_age();    
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(itr2->second.get_age() < *min)
            *min = itr2->second.get_age();
        if(itr2->second.get_age() > *max)
            *max = itr2->second.get_age();
        *avarage += itr2->second.get_age();    
    } 
    for (itr3 = elders.begin(); itr3 != elders.end(); ++itr3) { 
        if(itr3->second.get_age() < *min)
            *min = itr3->second.get_age();
        if(itr3->second.get_age() > *max)
            *max = itr3->second.get_age();
        *avarage += itr3->second.get_age();    
    }    
    *avarage = *avarage/userCount;
}

void BoxOffice::get_dependents(float *max, float *min, float *avarage){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 

    *min = elders.begin()->second.get_children().size(), 
    *max = 0, 
    *avarage = 0;
    int userCount = adults.size() + elders.size();
    int size = 0;

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        if(!itr->second.get_children().empty())
            size = itr->second.get_children().size();
        if(size < *min)
            *min = size;
        if(size > *max)
            *max = size;
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(!itr2->second.get_children().empty())
            size = itr2->second.get_children().size();
        if(size < *min)
           *min = size;
        if(size > *max)
            *max = size;
    }
    *avarage = (float)kids.size()/userCount;
}

void BoxOffice::get_dependent_relations(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::map<int, std::string>::iterator itr3;
    std::vector<int>::iterator itrChildren; 
    std::map<int, std::string> out;
    std::string str;

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        str = "";
        if(!itr->second.get_children().empty()){
            str += itr->second.get_name() + " (ID: " + std::to_string(itr->second.get_id()) + "): ";
            for(auto child: itr->second.get_children())
                str+= kids[child].get_name() + " (ID: " + std::to_string(child) + "),";
        }
        out[itr->second.get_id()] = str;
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        str = "";
        if(!itr2->second.get_children().empty()){
            str += "\n" +  itr2->second.get_name() + " (ID: " + std::to_string(itr2->second.get_id()) + "): ";
            for(auto child: itr2->second.get_children())
                str += kids[child].get_name() + " (ID: " + std::to_string(child) + "), ";
        }
        out[itr2->second.get_id()] = str;
    }

    for(itr3 = out.begin(); itr3 != out.end(); ++itr3)
        std::cout << itr3->second;

    std::cout << std::endl;    
}

void BoxOffice::get_event_relations(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::map<int, std::string>::iterator itr3;
    std::map<int, std::string> out;
    std::string str;

    for (itr = elders.begin(); itr != elders.end(); ++itr){
        if(!itr->second.get_events().empty()){
            str = "";
            str += itr->second.get_name() + " (ID: " + std::to_string(itr->second.get_id()) + "): " 
                + std::to_string(itr->second.get_events().size());
            out.insert({itr->second.get_id(), str});    
        }    
    }    
    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2){
        if(!itr2->second.get_events().empty()){
            str = "";
            str += itr2->second.get_name() + " (ID: " + std::to_string(itr2->second.get_id()) + "): " 
                + std::to_string(itr2->second.get_events().size());
            out.insert({itr2->second.get_id(), str});    
        }
    }    

    for(itr3 = out.begin(); itr3 != out.end(); ++itr3)
        std::cout << itr3->second << std::endl;
            
}

void BoxOffice::get_biggest_elder_amount(){
    std::map<int,Club>::iterator itr;
    std::map<int,Consert>::iterator itr2;
    std::string name = "";
    int id;
    int max = 0;

    for(itr = clubs.begin(); itr != clubs.end(); ++itr){
        if(max < itr->second.get_elder_amout()){
            max = itr->second.get_elder_amout();
            name = itr->second.get_name();
            id = itr->second.get_id();
        }    
    }

    for(itr2 = conserts.begin(); itr2 != conserts.end(); ++itr2){
        if(max < itr2->second.get_elder_amout()){
            max = itr2->second.get_elder_amout();
            name = itr2->second.get_name();
            id = itr2->second.get_id();
        }    
    }
    
    std::cout << name + " (ID: " << id << "): " << max;
}

void BoxOffice::get_tickets(){

    std::map<float, int> tickets;
    std::vector<float> prices;
    std::vector<int> capacity;

    std::map<float, int>::iterator t_itr;
    std::map<int,PuppetShow>::iterator puppet_itr;
    std::map<int,MovieTheater>::iterator movie_itr;
    std::map<int,Consert>::iterator consert_itr;
    std::map<int,Club>::iterator club_itr;

    for(puppet_itr = puppetShows.begin() ;puppet_itr != puppetShows.end(); ++puppet_itr){
        prices = puppet_itr->second.get_prices();
        capacity = puppet_itr->second.get_capacity();

        for (int i = 0; i < puppet_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(movie_itr = movieTheaters.begin(); movie_itr != movieTheaters.end(); ++movie_itr){
        prices = movie_itr->second.get_prices();
        capacity = movie_itr->second.get_capacity();

        for (int i = 0; i < movie_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(consert_itr = conserts.begin() ;consert_itr != conserts.end(); ++consert_itr){
        prices = consert_itr->second.get_prices();
        capacity = consert_itr->second.get_capacity();

        for (int i = 0; i < consert_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(club_itr = clubs.begin(); club_itr != clubs.end(); ++club_itr){
        prices = club_itr->second.get_prices();
        capacity = club_itr->second.get_capacity();

        for (int i = 0; i < club_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();   
    }
    for (t_itr = tickets.begin() ;t_itr != tickets.end(); ++t_itr)
        std::cout << "R$" << t_itr->first << ": " << t_itr->second << std::endl;
        
}