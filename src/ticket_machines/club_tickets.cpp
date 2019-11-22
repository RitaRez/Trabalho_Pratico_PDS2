#include "../../lib/ticket_machines/club_tickets.hpp"
#include "../../lib/exceptions/ticket_unavailable_exception.hpp"
#include "../../lib/exceptions/not_enough_tickets_exception.hpp"

ClubTickets* ClubTickets::instance = NULL;

ClubTickets*  ClubTickets::getInstance(){
    if(instance == NULL){
        instance = new ClubTickets();
    }else
        return instance;
}

ClubTickets::ClubTickets(){}

void ClubTickets::show_schedules(BoxOffice *boxOffice, int id_event, int price, int l){
    system("clear");
    std::cout 
        << boxOffice->get_clubs()[id_event]->get_name()
        << "\nHorario de inicio: " << boxOffice->get_clubs()[id_event]->get_starting_time() << ":00"
        << "\nHorario de termino: " << boxOffice->get_clubs()[id_event]->get_ending_time() << ":00"
        << "\nPreço: R$:" << price << ",00"
    << std::endl;    
}

int ClubTickets::get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted){
    int ticketsAvailable = 0;
    for (int i = 0; i < boxOffice->get_clubs()[id_event]->get_capacity().size(); i++)
        ticketsAvailable += boxOffice->get_clubs()[id_event]->get_capacity()[i];
    if(ticketsAvailable < ticketsWanted){
        system("clear");
        throw NotEnoughtTicketsException("Os ingressos acabaram", ticketsAvailable);
    }    
    return ticketsAvailable;    
}

int ClubTickets::get_current_price(BoxOffice *boxOffice, int id_event){
    for (int i = 0; i < boxOffice->get_clubs()[id_event]->get_capacity().size(); i++){
        if(boxOffice->get_clubs()[id_event]->get_capacity()[i] > 0)
	        return i;
    }    
}

void ClubTickets::sell_tickets(BoxOffice *boxOffice, int id_event, int id_user){
    printf("debug\n");
    int lote = 0, ticketsWanted, time;
    double priceIndex = this->get_current_price(boxOffice, id_event);   
    std::cout << priceIndex << "std::end\n";
    double individuaPrice = boxOffice->get_clubs()[id_event]->get_prices()[priceIndex];

    this->show_schedules(boxOffice, id_event, individuaPrice, priceIndex);
    
    std::cout << "\nDigite quantos ingressos você deseja: \n";    
    std::cin >> ticketsWanted;
    
    int ticketsAvailable = this->get_tickets_available(boxOffice, id_event, ticketsWanted);
    double totalPrice = this->get_total_price(boxOffice->get_clubs()[id_event], id_event, ticketsWanted);
    std::cout <<"\nPreço total: " << totalPrice << std::endl;
    
    if(boxOffice->get_clubs()[id_event]->get_elder_amout() >= ticketsAvailable && boxOffice->get_elders()[id_user] != nullptr){
        system("clear");
        throw TicketUnavailableException("Não existem ingressos de nao idosos", "Não há mais ingressos da sua categoria");
    }
    
    if(boxOffice->get_adults()[id_user] != nullptr){
        if(boxOffice->get_adults()[id_user]->get_budget() < totalPrice){
            system("clear");
            throw TicketUnavailableException("Comprar ingressos", "Você nao possui saldo o suficiente");
        } else {
            for(int i = 0; i < ticketsWanted; i++)
                boxOffice->get_adults()[id_user]->increase_bought_tickets();
            
            boxOffice->get_adults()[id_user]->set_budget(totalPrice);
            boxOffice->add_logged_id(id_user);
            boxOffice->add_bought_club(id_event,ticketsWanted);
            this->change_capacity(boxOffice->get_clubs()[id_event], id_event, ticketsWanted);
        }
    } else{
        if(boxOffice->get_elders()[id_user]->get_budget() < totalPrice){
            system("clear");
            throw TicketUnavailableException("Comprar ingressos", "Você nao possui saldo o suficiente");
        } else { 
            for(int i = 0; i < ticketsWanted; i++)
                boxOffice->get_elders()[id_user]->increase_bought_tickets();
              
            boxOffice->get_elders()[id_user]->set_budget(totalPrice);
            boxOffice->add_bought_club(id_event,ticketsWanted);
            boxOffice->add_logged_id(id_user);
            this->change_capacity(boxOffice->get_clubs()[id_event], id_event, ticketsWanted);
        }
    }  
}

void ClubTickets::emit_ticket(BoxOffice, int id_event, int price){

    
}
