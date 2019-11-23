#include "../../lib/ticket_machines/movie_theater_tickets.hpp"
#include "../../lib/exceptions/ticket_unavailable_exception.hpp"
#include "../../lib/exceptions/not_enough_tickets_exception.hpp"
#include "../../lib/exceptions/invalid_entity_exception.hpp"
#include <iostream>
#include <algorithm>


MovieTheaterTickets* MovieTheaterTickets::instance = NULL;
MovieTheaterTickets::MovieTheaterTickets(){}

MovieTheaterTickets* MovieTheaterTickets::getInstance(){
    if(instance == NULL){
        instance = new MovieTheaterTickets();
    }else
        return instance;
}

void MovieTheaterTickets::show_schedules(BoxOffice *boxOffice, int id_event, int price, int l){
    system("clear");
    std::cout 
        << boxOffice->get_movie_theaters()[id_event]->get_name()
        << "\n\nDuraçao do filme: " << boxOffice->get_movie_theaters()[id_event]->get_running_time() << ":00"
        << "\nQuantidade de ingressos do lote atual: " << boxOffice->get_movie_theaters()[id_event]->get_capacity()[l]
        << "\nPreço inicial: R$:" << price << ",00"
    << std::endl;  
    std::cout << "\nHorarios:\n";
    for (auto s: boxOffice->get_movie_theaters()[id_event]->get_movie_schedules())
        std::cout << "- " << s << ":00\n";
    
}

void MovieTheaterTickets::time_exists(int time, std::vector<int> schedule){
    if (std::find(schedule.begin(), schedule.end(), time) == schedule.end())
        throw InvalidEntityException("Horario nao existe", "O horario selecionado nao existe");

}

int MovieTheaterTickets::get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted){
    int ticketsAvailable = 0;
    for (int i = 0; i < boxOffice->get_movie_theaters()[id_event]->get_capacity().size(); i++)
        ticketsAvailable += boxOffice->get_movie_theaters()[id_event]->get_capacity()[i];
    if(ticketsAvailable < ticketsWanted){
        system("clear");
        throw NotEnoughtTicketsException("Os ingressos acabaram", ticketsAvailable);
    }    
    return ticketsAvailable;    
}

int MovieTheaterTickets::get_current_price(BoxOffice *boxOffice, int id_event){
    for (int i = 0; i < boxOffice->get_movie_theaters()[id_event]->get_capacity().size(); i++){
        if(boxOffice->get_movie_theaters()[id_event]->get_capacity()[i] > 0)
	        return i;
    }    
}

void MovieTheaterTickets::sell_tickets(BoxOffice *boxOffice, int id_event, int id_user){
    int lote = 0, ticketsWanted, time;
    double priceIndex = this->get_current_price(boxOffice, id_event);   
    double individuaPrice = boxOffice->get_movie_theaters()[id_event]->get_prices()[priceIndex];

    this->show_schedules(boxOffice, id_event, individuaPrice, priceIndex);
    
    std::cout << "\n\nDigite o horário desejado: ";    
    std::cin >> time;
    time_exists(time, boxOffice->get_movie_theaters()[id_event]->get_movie_schedules());  

    std::cout << "\nDigite quantos ingressos você deseja: ";    
    std::cin >> ticketsWanted;
    
    int ticketsAvailable = this->get_tickets_available(boxOffice, id_event, ticketsWanted);
    double totalPrice = this->get_total_price(boxOffice->get_movie_theaters()[id_event], id_event, ticketsWanted);
    std::cout <<"\nPreço total: " << totalPrice << std::endl;
    
    if(boxOffice->get_adults()[id_user] != nullptr){
        if(boxOffice->get_adults()[id_user]->get_budget() < totalPrice){
            system("clear");
            throw TicketUnavailableException("Comprar ingressos", "Você nao possui saldo o suficiente");
        } else {
            for(int i = 0; i < ticketsWanted; i++)
                boxOffice->get_adults()[id_user]->increase_bought_tickets();
            
            boxOffice->get_adults()[id_user]->set_budget(totalPrice);
            boxOffice->add_logged_id(id_user);
            boxOffice->add_bought_movie(id_event,ticketsWanted);
            this->change_capacity(boxOffice->get_movie_theaters()[id_event], id_event, ticketsWanted);
            emit_ticket(boxOffice,id_event,ticketsWanted,totalPrice);
        }
    } else{
        if(boxOffice->get_elders()[id_user]->get_budget() < totalPrice){
            system("clear");
            throw TicketUnavailableException("Comprar ingressos", "Você nao possui saldo o suficiente");
        } else { 
            for(int i = 0; i < ticketsWanted; i++)
                boxOffice->get_elders()[id_user]->increase_bought_tickets();
              
            boxOffice->get_elders()[id_user]->set_budget(totalPrice);
            boxOffice->add_bought_movie(id_event,ticketsWanted);
            boxOffice->add_logged_id(id_user);
            this->change_capacity(boxOffice->get_movie_theaters()[id_event], id_event, ticketsWanted);
            emit_ticket(boxOffice,id_event,ticketsWanted,totalPrice);
        }
    }

}    

void MovieTheaterTickets::emit_ticket(BoxOffice *boxOffice, int id_event, int tickets, int price){
system("clear");
    std::cout << "================================================================================================\n" << std::endl;
    std::cout 
        << "INGRESSO: "
        << boxOffice->get_movie_theaters()[id_event]->get_name()
        << "\nQuantidade de unidades: " << tickets
        << "\nPreco total: " << price
    << std::endl;
    std::cout << "\n================================================================================================" << std::endl;
}