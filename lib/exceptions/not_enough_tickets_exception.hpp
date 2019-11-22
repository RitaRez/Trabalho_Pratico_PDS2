#ifndef NOT_ENOUGH_TICKETS_EXCEPTION_H
#define NOT_ENOUGH_TICKETS_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class NotEnoughtTicketsException: public std::exception{
    public:
        NotEnoughtTicketsException(std::string action, int tickets);
        std::string what();
        std::string get_message();

    private:
        int tickets;
        std::string action;
        std::string reason;
};

#endif
