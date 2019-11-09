#include <iostream>
#include <exception>
#include "../../lib/exceptions/data_not_loaded_exception.hpp"

DataNotLoadedException::DataNotLoadedException(std::string action, std::string reason){
	this->action = action;
	this->reason = reason;
}

std::string DataNotLoadedException::what(){
	return this->reason;
}

std::string DataNotLoadedException::get_message(){
	return "Invalid action '"+this->action+"' reason: "+this->reason;
}
