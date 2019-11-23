#include <iostream>
#include <exception>
#include "../../lib/exceptions/ticket_unavailable_exception.hpp"

TicketUnavailableException::TicketUnavailableException(std::string action, std::string reason){
	this->action = action;
	this->reason = reason;
}

std::string TicketUnavailableException::what(){
	return this->reason;
}

std::string TicketUnavailableException::get_message(){
	system("clear");
	return "Invalid action '"+this->action+"' reason: "+this->reason;
}
