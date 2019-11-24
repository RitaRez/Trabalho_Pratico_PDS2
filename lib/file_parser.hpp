/**
 *  @brief Classe que realiza a leitura dos arquivos e transforma os arquivos em mapas de ponteiro de Usuario e evento.
*/

#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <vector> 
#include <map> 

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"

#include "./events/event.hpp"
#include "./events/infant_event.hpp"
#include "./events/puppet_show.hpp"
#include "./events/adult_event.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class FileParser{
    
    private:
        /**
         *  @brief Lê os arquivos CSV e retorna os dados em vetores de string separados por objeto.
         *  @param fileName Nome do arquivo
         *  @return vetor de usuarios e eventos.
        */    
        std::vector<std::string> static read_file(std::string fileName);
        
        /**
         *  @brief Recebe os atributos do objeto e o monta.
         *  @param objs Dados do objeto
         *  @return Objeto.
        */ 
        PuppetShow static *create_puppet_show(std::vector<std::string> objs);   
        /**
         *  @brief Recebe os atributos do objeto e o monta.
         *  @param objs Dados do objeto
         *  @return Objeto.
        */
        Club static *create_club(std::vector<std::string> objs);
        /**
         *  @brief Recebe os atributos do objeto e o monta.
         *  @param objs Dados do objeto
         *  @return Objeto.
        */
        Consert static *create_consert(std::vector<std::string> objs);
        /**
         *  @brief Recebe os atributos do objeto e o monta.
         *  @param objs Dados do objeto
         *  @return Objeto.
        */
        MovieTheater static *create_movie_theater(std::vector<std::string> objs);
     
    public:
        
        /**
         *  @brief Recebe o nome do arquivo e a referencia das estruturas e as popula.
         *      --> A funcao chamara read_file para ambos os arquivos e recebera os objetos em formato de string
         *      --> Convertera essa string em strings menores para cada atributo
         *      --> Chamara a funcao create respectiva do tipo do objeto e a colocara na estrutura
        */ 
        void static parse_events(char *str, std::map<int,Club*>& clubs, std::map<int,Consert*>& conserts, std::map<int,PuppetShow*>& puppet_shows, std::map<int,MovieTheater*>& movieTheaters, std::map<int,Adult*>& adults, std::map<int,Elder*>& elders);
        
        /**
         *  @brief Recebe o nome do arquivo e a referencia das estruturas e as popula.
         *      --> A funcao chamara read_file para ambos os arquivos e recebera os objetos em formato de string
         *      --> Convertera essa string em strings menores para cada atributo
         *      --> Chamara a funcao create respectiva do tipo do objeto e a colocara na estrutura
        */
        void static parse_users(char *str, std::map<int,Kid*>& kids, std::map<int,Adult*>& adults, std::map<int,Elder*>& elders);

};
 
#endif