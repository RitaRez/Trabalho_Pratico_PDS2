/**
 *  @brief Maquina de ingressos de cinema, realiza compras e emite bilhetes dessas.
 */

#ifndef MOVIE_THEATER_TICKETS_H
#define MOVIE_THEATER_TICKETS_H

#include "../totem.hpp"

class MovieTheaterTickets: public Totem {
    
    private:
        static MovieTheaterTickets* instance;
    
    public:

        //@brief Construtor vazio da classe
        MovieTheaterTickets();       

        //@brief verifica se existe uma instancia e caso contrario, cria.
        static MovieTheaterTickets* getInstance();
        
        /**
         *  @brief Verifica se o horario digitado pelo usuario existe.
         *  @param schedule horarios disponiveis
        */
        void time_exists(int time, std::vector<int> schedule);
        
        // @see Declaração das funções na classe mãe Totem
	    void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) override;
        void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l) override;  
        void emit_ticket(BoxOffice *boxOffice, int id_event, int tickets, int price) override;
        int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted) override;
        int get_current_price(BoxOffice *boxOffice, int id_event) override;
};

#endif
