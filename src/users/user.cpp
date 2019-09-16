#include "../../lib/users/user.hpp"

#include <iostream>

void User::add_event(int event){
    this->events.push_back(event);
}

