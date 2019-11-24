/**
 *  @brief Classe de Adulto.
*/

#ifndef ADULT_H
#define ADULT_H

#include "user.hpp"

class Kid;
class Elder;

class Adult: public User{
    
    private:
        std::vector<int> children; // !< Crianças que o adulto cuida.
        int boughtTickets = 0; // !< Quantidade de ingressos compradas pelo adulto.
        
    public:
        
        //@brief Construtor vazio da classe.
        Adult();
        
        //@brief Construtor com atributos.
        Adult(int id, std::string category, std::string name, int age, float budget);

        //@brief Função que imprime dados do adulto.
        //@param adults Mapa de adultos.
        static void print_adults(std::map<int,Adult*> adults);

        /**
         *  @brief Retorna as crianças.
         *  @return Vetor do identificador das crianças.
        */
        std::vector<int> get_children(){return children;}

        /**
         *  @brief Adiciona criança como dependente do adulto.
         *  @param kid Identificador da criança.
        */
        void add_children(int kid);

        // @return Quantos ingressos o usuário comprou.
        int get_bought_tickets(){return this->boughtTickets;}
        
        // @return Aumenta a quantidade de ingressos comprados pelo adulto.
        void increase_bought_tickets(){this->boughtTickets++;}

};
 
#endif