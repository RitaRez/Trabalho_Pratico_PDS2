#include <iostream>
#include <exception>
#include "../../lib/exceptions/not_enough_tickets_exception.hpp"

NotEnoughtTicketsException::NotEnoughtTicketsException(std::string action, int tickets){
	this->action = action;
	this->tickets = tickets;
}

std::string NotEnoughtTicketsException::what(){
	system("clear");
	return  "Existem apenas " + std::to_string(tickets) + " ingressos disponiveis!";
}

std::string NotEnoughtTicketsException::get_message(){
	return "Invalid action '"+this->action+"' reason: "+this->reason;
}
