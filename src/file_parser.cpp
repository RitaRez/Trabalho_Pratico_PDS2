#include "../lib/file_parser.hpp"


FileParser::FileParser(std::vector<std::string> n_stringUser, std::vector<std::string> n_stringEvent){
    stringUser = n_stringUser;
    stringEvent = n_stringEvent;   
}

void FileParser::parse_users(){
    std::vector<std::string> aux;

    for(std::string str : stringUser){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){ 
            token = token.c_str();
            aux.push_back(token);
        }  
        if(aux[1].compare("crianca") == 0){     
            Kid newKid(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), std::stof(aux[4]), std::stoi(aux[5]));
            kids[newKid.get_id()] = newKid;
            adults[std::stoi(aux[5])].add_children(newKid.get_id());
         
         } else if(aux[1].compare("adulto") == 0){
            Adult newAdult(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            adults.insert({newAdult.get_id(), newAdult});    
        
        } else {
            Elder newElder(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            elders[newElder.get_id()] = newElder;   
        }
        aux.clear();
    } 
}

void FileParser::parse_events(){
    std::vector<std::string> aux;
    
    for(std::string str : stringEvent){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){ 
            token = token.c_str();
            aux.push_back(token);
        }         
        
        if(aux[1].compare("infantil") == 0){    
            // PuppetShow newPuppetShow(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[3]), std::stof(aux[4]));
            // (*puppetShows).insert({newPuppetShow.get_id()});

        } else if(aux[1].compare("adulto") == 0){   
            if(aux[2].compare("boate") == 0) {

            } else{

            }
        } else {

        }
        aux.clear();
    } 
}

void FileParser::printKids(){
    std::map<int, Kid>::iterator itr; 
    int id;
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        id = itr->second.get_responsible();
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget() 
            << "\nResponsible name:" << adults[id].get_name() 
        << std::endl; 
    } 
}
