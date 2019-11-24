/**
 *  @brief Classe de exceção utilizada quando o usuário não pode comprar o ingresso selecionado.
*/

#ifndef TICKET_UNAVAILABLE_EXCEPTION_H
#define TICKET_UNAVAILABLE_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class TicketUnavailableException: public std::exception{
    public:
        TicketUnavailableException(std::string action, std::string reason);
        std::string what();
        std::string get_message();

    private:
        std::string action;
        std::string reason;
};

#endif
