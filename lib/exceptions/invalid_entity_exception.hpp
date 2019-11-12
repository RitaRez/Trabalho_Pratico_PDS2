#ifndef INVALID_ENTITY_EXCEPTION_H
#define INVALID_ENTITY_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class InvalidEntityException: public std::exception{
    public:
        InvalidEntityException(std::string action, std::string reason);
        std::string what();
        std::string get_message();

    private:
        std::string action;
        std::string reason;
};

#endif
