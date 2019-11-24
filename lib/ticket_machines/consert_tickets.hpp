/**
 *  @brief Maquina de ingressos de show, realiza compras e emite bilhetes dessas.
 */

#ifndef CONSERT_TICKETS_H
#define CONSERT_TICKETS_H

#include "../totem.hpp"

class ConsertTickets: public Totem {
    
    private:
        static ConsertTickets* instance;
    
    public:
        //@brief Construtor vazio da classe
        ConsertTickets();

        //@brief verifica se existe uma instancia e caso contrario, cria.
        static ConsertTickets* getInstance();
	    
        // @see Declaração das funções na classe mãe Totem
        void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) override;
        void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l, int tickets) override;        
        void emit_ticket(BoxOffice *boxOffice, int id_event, int tickets, int price) override;
        int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted) override;
        int get_current_price(BoxOffice *boxOffice, int id_event) override;

};

#endif