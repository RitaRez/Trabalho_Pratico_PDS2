/**
 *  @brief Classe de exceção utilizada quando o usuario ainda não selecionou "1" no menu e inicializou as estruturas.
*/

#ifndef DATA_NOT_LOADED_EXCEPTION_H
#define DATA_NOT_LOADED_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class DataNotLoadedException: public std::exception{
    public:
        DataNotLoadedException(std::string action, std::string reason);
        
        /**
         * @brief Função que imprime erro.
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
