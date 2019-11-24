/**
 *  @brief Classe de idoso.
*/

#ifndef ELDER_H
#define ELDER_H
 
#include "kid.hpp"
#include "adult.hpp"

class Elder: public Adult{
    
    private:

    public:
        Elder();
        //@brief Construtor com atributos.
        Elder(int id, std::string category, std::string name, int age, float budget);

        //@brief Função que imprime dados do idoso.
        //@param elders Mapa de idosos.
        static void print_elders(std::map<int,Elder*> elders);
};
 
#endif