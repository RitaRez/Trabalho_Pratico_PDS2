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
#include "./lib/events/adult_event.hpp"


void parse_users(std::vector<std::string> StringArray, std::map<int, Kid> *kids, std::map<int, Adult> *adults, std::map<int, Elder> *elders){
    
    std::vector<std::string> aux;
    int id, age;
    float budget;
    std::string responsible;
    
    for(std::string str : StringArray){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){ 
            token = token.c_str();
            aux.push_back(token);
        }  

        if(aux[1].compare("crianca") == 0){     
            Kid new_kid(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), std::stof(aux[4]), std::stoi(aux[5]));
            (*kids)[new_kid.get_id()] = new_kid;
            //(*adults)[std::stoi(aux[5])].add_children(&new_kid);
         
         } else if(aux[1].compare("adulto") == 0){
            Adult new_adult(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            (*adults).insert({new_adult.get_id(), new_adult});    
        
        } else {
            Elder new_elder(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            (*elders)[new_elder.get_id()] = new_elder;   
        }
        aux.clear();
    } 
}

// std::vector<Event::Event> parse_events(std::vector<std::string> StringArray){
//     std::vector<User> events;
//     std::vector<std::string> aux;
    
//     for(std::string str : StringArray){
//         std::stringstream ss(str);
//         std::string token;
        
//         while (std::getline(ss, token, ',')){ 
//             aux.push_back(token);
//         }         
        
//         if(std::string(aux[1]) == "infantil"){    
        
//         } else if(std::string(aux[1]) == "adulto"){   
//             if(std::string(aux[2]) == "show") {

//             } else{

//             }
//         } else {

//         }
//         aux.clear();
//     } 

//    return events;
// }

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
    std::vector<std::string> EventsArray;
    std::map<int, Kid> *kids = new std::map<int, Kid>;
    std::map<int, Adult> *adults = new std::map<int, Adult>;
    std::map<int, Elder> *elders = new std::map<int, Elder>;


    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }
    
    usersArray = read_file(argv[1]);
    EventsArray = read_file(argv[2]);
    printf("Leitura de arquivo funciona\n");
    parse_users(usersArray,kids,adults,elders);


    return 0;
}