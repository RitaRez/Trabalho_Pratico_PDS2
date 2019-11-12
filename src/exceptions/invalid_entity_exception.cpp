#include <iostream>
#include <exception>
#include "../../lib/exceptions/invalid_entity_exception.hpp"

InvalidEntityException::InvalidEntityException(std::string action, std::string reason){
	this->action = action;
	this->reason = reason;
}

std::string InvalidEntityException::what(){
	return this->reason;
}

std::string InvalidEntityException::get_message(){
	return "Invalid action '"+this->action+"' reason: "+this->reason;
}
