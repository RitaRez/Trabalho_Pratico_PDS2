/**
 *  @brief Classe de exceção utilizada quando o usuario seleciona algum objeto que não exista.
 */

#ifndef INVALID_ENTITY_EXCEPTION_H
#define INVALID_ENTITY_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class InvalidEntityException: public std::exception{
    public:
        InvalidEntityException(std::string action, std::string reason);
        /**
         * @brif Função que imprime erro.
         * @return Texto explicando motivo de erro
         */
        std::string what();
        std::string get_message();

    private:
        /**
         *  Ação que causou a exceção.
         */
        std::string action;
        /**
         *  Motivo pelo qual a ação causa a exceção.
         */
        std::string reason;
};

#endif
