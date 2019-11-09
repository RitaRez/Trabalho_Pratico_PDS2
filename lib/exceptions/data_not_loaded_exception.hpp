#ifndef DATA_NOT_LOADED_EXCEPTION_H
#define DATA_NOT_LOADED_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class DataNotLoadedException: public std::exception{
    public:
        DataNotLoadedException(std::string action, std::string reason);
        std::string what();
        std::string get_message();

    private:
        std::string action;
        std::string reason;
};

#endif
