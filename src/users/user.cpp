#include "../../lib/users/user.hpp"

#include <iostream>

void User::add_event(int event){
    this->events.push_back(event);
}

void User::set_budget(double budget){
    this->budget-= budget;
}

