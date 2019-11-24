/**
 *  @brief Classe que armazena as estruturas do trabalho.
*/

#ifndef BOX_OFFICE_H
#define BOX_OFFICE_H

#include <set>
#include <map>

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"

#include "./events/puppet_show.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class BoxOffice {
    
    private:
        std::map<int, Kid*> kids; //!< Mapa com as crianças onde a chave e o identificador
        std::map<int, Adult*> adults; //!< Mapa com os adultos onde a chave e o identificador
        std::map<int, Elder*> elders; //!< Mapa com os idosos onde a chave e o identificador
        std::map<int, MovieTheater*> movieTheaters; //!< Mapa com os cinemas onde a chave e o identificador
        std::map<int, PuppetShow*> puppetShows; //!< Mapa com os teatros de fantoche onde a chave e o identificador
        std::map<int, Consert*> conserts; //!< Mapa com os shows onde a chave e o identificador
        std::map<int, Club*> clubs; //!< Mapa com as boates onde a chave e o identificador
        
        std::set<int> loggedId; //!< Arranjo com o Id dos usarios que realizaram compras

        //!< Mapa com os eventos que tiveram ingressos adquiridos, a chave é o identificador e o valor é a quantidade de ingressos comprados
        std::map<int, int> boughtClubs, boughtConserts, boughtMovies, boughtPuppets;


    public:
        
        //@brief Construtor vazio da classe
        BoxOffice();
        
        /**
         *  @brief Retorna as crianças.
         *  @return Mapa de crianças
        */
        std::map<int, Kid*> get_kids(){return kids;}
        
        /**
         *  @brief Retorna os adultos.
         *  @return Mapa de adultos
        */
        std::map<int, Adult*> get_adults(){return adults;}
        
        /**
         *  @brief Retorna os idosos.
        */
        std::map<int, Elder*> get_elders(){return elders;}
        
        /**
         *  @brief Retorna as sessões de cinema.
        */
        std::map<int, MovieTheater*> get_movie_theaters(){return movieTheaters;}    

        /**
         *  @brief Retorna os teatros de fantoche.
        */
        std::map<int, PuppetShow*> get_puppet_shows(){return puppetShows;} 

        /**
         *  @brief Retorna os shows.
        */
        std::map<int, Consert*> get_conserts(){return conserts;}

        /**
         *  @brief Retorna as boates.
        */
        std::map<int, Club*> get_clubs(){return clubs;}

        /**
         *  @brief Cria uma instância de FileParser que incializa as estruturas.
         *  @param args Nome dos arquivos csv.
        */
        void initialize(const char** args);

        /**
         *  @brief Exibe menu pro usuário.
         *  @return Inteiro que representa a escolha do usuário.
        */
        int menu_text();

        /**
         *  @brief O usuario loga em uma das contas do usuarios disponiveis.
         *  @return Id do usuário digitado.
        */
        int login();
        
        /**
         *  @brief Imprime usuários do sistema.
        */
        void print_users();
        
        /**
         *  @brief Exibe eventos do sistema e permite o usuario escolher um.
         *  @return Id do evento escolhido pelo usuário.
        */
        int print_events();

        /**
         *  @brief Retorna arranjo dos usuários que realizaram compras.
        */
        std::set<int> get_logged_id(){return this->loggedId;}
        
        /**
         *  @brief Adiciona usuário que realizou uma compra.
         *  @param id Identificador do usuário que realizou a compra.
        */
        void add_logged_id(int id){
            this->loggedId.insert(id);
        }

        //@brief Retorna os mapas dos eventos que tiveram ingressos adquiridos.
        std::map<int,int> get_bought_clubs(){return this->boughtClubs;}
        std::map<int,int> get_bought_conserts(){return this->boughtConserts;}
        std::map<int,int> get_bought_movies(){return this->boughtMovies;}
        std::map<int,int> get_bought_puppet(){return this->boughtPuppets;}

        //@brief Adiciona identificador do evento a estrutura de eventos comprados.
        void add_bought_club(int id, int amount);      
        void add_bought_consert(int id, int amount);       
        void add_bought_movie(int id, int amount);      
        void add_bought_puppet(int id, int amount);
        
        //@brief Deleta todos os elementos dos mapas da classe boxOffice.
        void free_maps();
};

#endif