/**
 *  @brief Classe mãe das maquinas de venda.
*/

#ifndef TOTEM_H
#define TOTEM_H

#include <vector>
#include <map>

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"
#include "./box_office.hpp"

#include "./events/puppet_show.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class Totem {
    
    public:
        
        //@brief Construtor vazio da classe
        Totem();
        
        /** @brief Chama a funcao construtora da maquina do respectivo evento
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @return Retorna Maquina respectiva do evento
        */
        static Totem* factoryMethod(BoxOffice *boxOffice, int id);
        
        /**
         *  @brief Realiza a compra de ingressos de show.
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @param id_user Identificador do usuário que está fazendo a compra
        */
	    virtual void sell_tickets(BoxOffice *boxOffice, int id_event, int id_user) = 0;
        
        /**
         *  @brief Imprime na tela os dados do evento.
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @param id_user Identificador do usuário que está fazendo a compra
         *  @param l Lote em que as vendas se encontram
         *  @param tickets Ingressos disponiveis
        */
        virtual void show_schedules(BoxOffice *boxOffice, int id_event, int price, int l, int tickets) = 0;
        
        /**
         *  @brief Imprime na tela o bilhete da compra.
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @param tickets Quantidade de ingressos comprada
         *  @param price Preço pago pelo usuario
        */
        virtual void emit_ticket(BoxOffice *boxOffice, int id_event, int tickets, int price) = 0;
        
        /**
         *  @brief Calcula o preco total pago pelo ususario.
         *  @param mt Evento que vai ser comprado
         *  @param id_event Identificador do evento desejado
         *  @param ticketsWanted Quantidade de ingressos comprados
         *  @return Preco total
        */
        virtual int get_total_price(Event *mt, int id_event, int ticketsWanted);

        /**
         *  @brief Reduz a quantidade de ingressos disponivel na estrutura.
         *  @param mt Evento que vai ser comprado
         *  @param id_event Identificador do evento desejado
         *  @param ticketsWanted Quantidade de ingressos comprados
        */
        virtual void change_capacity(Event *mt, int id_event, int ticketsWanted);
        
        /**
         *  @brief Imprime na tela o bilhete da compra.
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @param ticketsWanted Quantidade de ingressos desejada
         *  @return Ingressos disponiveis
        */
        virtual int get_tickets_available(BoxOffice *boxOffice, int id_event, int ticketsWanted) = 0;
        
        /**
         *  @brief Calcula o preco do lote atual.
         *  @param boxOffice Instancia da classe bilheteria que contem dados de usuarios e eventos
         *  @param id_event Identificador do evento desejado
         *  @return Preco do lote atual
        */
        virtual int get_current_price(BoxOffice *boxOffice, int id_event) = 0;

};

#endif
