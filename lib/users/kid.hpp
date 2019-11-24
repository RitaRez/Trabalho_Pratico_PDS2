/**
 *  @brief Classe de criança.
*/

#ifndef KID_H
#define KID_H

#include "user.hpp"
#include "adult.hpp"
#include "elder.hpp"

 
class Kid: public User{
    
    private:
        int responsible;

    public:
        Kid();

        //@brief Construtor com atributos.
        Kid(int id, std::string category, std::string name, int age, float budget, int responsible);

        //@brief Função que imprime dados da criança.
        //@param kids Mapa de crianças.
        //@param adults Mapa de adultos.
        //@param elders Mapa de idosos.
        static void print_kids(std::map<int,Kid*> kids, std::map<int,Adult*> adults, std::map<int,Elder*> elders);
        
        //@return Identificador do responsável pela criança.
        int get_responsible(){return responsible;}
};
 
#endif