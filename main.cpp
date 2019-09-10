// TESTING IS THIS THE NEW BRANCH?

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <map> 


#include "./lib/users/user.hpp"
#include "./lib/users/kid.hpp"
#include "./lib/users/adult.hpp"
#include "./lib/users/elder.hpp"

#include "./lib/events/event.hpp"
#include "./lib/events/infant_event.hpp"
#include "./lib/events/puppet_show.hpp"
#include "./lib/events/adult_event.hpp"
#include "./lib/events/club.hpp"
#include "./lib/events/consert.hpp"
#include "./lib/events/movie_theater.hpp"



void parse_users(std::vector<std::string> StringArray, std::map<int, Kid> *kids, std::map<int, Adult> *adults, std::map<int, Elder> *elders){
    
    std::vector<std::string> aux;
    
    for(std::string str : StringArray){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){ 
            token = token.c_str();
            aux.push_back(token);
        }  

        if(aux[1].compare("crianca") == 0){     
            Kid newKid(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), std::stof(aux[4]), std::stoi(aux[5]));
            (*kids)[newKid.get_id()] = newKid;
            (*adults)[std::stoi(aux[5])].add_children(newKid.get_id());
         
         } else if(aux[1].compare("adulto") == 0){
            Adult newAdult(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            (*adults).insert({newAdult.get_id(), newAdult});    
        
        } else {
            Elder newElder(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            (*elders)[newElder.get_id()] = newElder;   
        }
        aux.clear();
    } 
}

void parse_events(std::vector<std::string> StringArray, std::map<int, MovieTheater> *movieTheaters, std::map<int, PuppetShow> *puppetShows, std::map<int, Consert> *conserts, std::map<int, Club> *clubs){
    std::vector<std::string> aux;
    
    for(std::string str : StringArray){
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

std::vector<std::string> read_file(std::string fileName){
    
    std::string object;
    std::vector<std::string> objectsArray;
    std::ifstream inFile;


    inFile.open(fileName);
    if (!inFile) {
        std::cerr << "Unable to open file\n";
        exit(2); 
    } 

    while(!inFile.eof()){
        getline(inFile, object);
        objectsArray.push_back(object);
    }
    inFile.close();

    return objectsArray;
}


int main(int argc, const char** argv) {
    
    std::ifstream inFile;
    std::vector<std::string> usersArray;
    std::vector<std::string> eventsArray;

    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }
    
    usersArray = read_file(argv[1]);
    eventsArray = read_file(argv[2]);

    std::map<int, Kid> *kids = new std::map<int, Kid>;
    std::map<int, Adult> *adults = new std::map<int, Adult>;
    std::map<int, Elder> *elders = new std::map<int, Elder>;
    parse_users(usersArray, kids, adults, elders);


    std::map<int, MovieTheater> *movieTheaters = new std::map<int, MovieTheater>;
    std::map<int, PuppetShow> *puppetShows = new std::map<int, PuppetShow>;
    std::map<int, Consert> *conserts = new std::map<int, Consert>;
    std::map<int, Club> *clubs = new std::map<int, Club>;
    parse_events(eventsArray, movieTheaters, puppetShows, conserts, clubs);

    return 0;
}