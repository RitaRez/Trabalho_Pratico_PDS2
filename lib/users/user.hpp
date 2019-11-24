/**
 *  @brief Classe de usuário.
*/

#ifndef USER_H
#define USER_H
 
#include <string>
#include <vector>
#include <iostream>
#include <map>

class User {
        
    protected:
        int id; // !< Identificador único obrigatório a todo usuário.
        std::string category; // !< Tipo de usuário.
        std::string name; // !< Nome do usuário.
        int age; // !< Idade do usuário.
        float budget; // !< Saldo do usuário.
        std::vector<int> events; // !< Eventos pelo qual ele é responsável.
    
    public:  

        /**
         *  @brief Retorna atributos do usuario.
        */
        int get_id() {return id;}
        std::string get_category() {return category;}
        std::string get_name() {return name;}
        int get_age() {return age;}    
        float get_budget() {return budget;}
        std::vector<int> get_events(){return events;}

        /**
         *  @param event Identificador do evento pelo qual o usuário é responsável.
        */
        void add_event(int event);
        
        /**
         *  @brief Debita valor do saldo do usuário.
         *  @param subtract Valor a ser debitado do saldo do usuário.
        */
	    void set_budget(double subtract);
};
 
#endif
