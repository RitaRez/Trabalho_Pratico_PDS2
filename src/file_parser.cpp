#include "../lib/file_parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>


std::vector<std::string> FileParser::read_file(std::string fileName){
    
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

void FileParser::parse_users(char *str, std::map<int,Kid>& kids, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::vector<std::string> aux;  
    std::vector<std::string> stringUser = read_file(str);
    
    for(std::string str : stringUser){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){
            aux.push_back(token);
        }  
        if(aux[1] == "crianca"){    
            Kid newKid(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), std::stof(aux[4]), std::stoi(aux[5]));
            kids[newKid.get_id()] = newKid;
            if(adults.find(std::stoi(aux[5])) != adults.end())
                adults[std::stoi(aux[5])].add_children(newKid.get_id());
            else    
                elders[std::stoi(aux[5])].add_children(newKid.get_id());
         } else if(aux[1] == "adulto"){
            Adult newAdult(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            adults[newAdult.get_id()] = newAdult;    
        } else if (aux[1] == "idoso") {
            Elder newElder(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            elders[newElder.get_id()] = newElder;   
        }
        aux.clear();
    } 
}

void FileParser::parse_events(char *str, std::map<int,Club>& clubs, std::map<int,Consert>& conserts, std::map<int,PuppetShow>& puppetShows, std::map<int,MovieTheater>& movieTheaters, std::map<int,Adult>& adults, std::map<int,Elder>& elders){
    std::vector<std::string> aux;
    std::vector<std::string> stringEvent = read_file(str);

    std::vector<int> capacities;
    std::vector<float> prices;
    std::vector<int> schedules;
    std::vector<std::string> artists;
    int gateOpening;

    int end;
    
    for(std::string str : stringEvent){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){ 
            token = token.c_str();
            aux.push_back(token);
        }               
        
        if(aux[1].compare("infantil") == 0){    
            end = 6 + (std::stoi(aux[5])*2);
            for(int i = 6; i < aux.size(); i++){
                if(i < end)
                    if(i % 2 == 0) 
                        capacities.push_back(std::stoi(aux[i]));
                    else 
                        prices.push_back(std::stof(aux[i]));
                else 
                    schedules.push_back(std::stoi(aux[i]));  
                    if(i == end)
                        gateOpening = std::stoi(aux[i]);
                    else      
                        artists.push_back(aux[i]);  
            }
            PuppetShow newPuppetShow(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[4]), capacities, prices, schedules);
            puppetShows.insert({newPuppetShow.get_id(), newPuppetShow});
            if(adults.find(std::stoi(aux[4])) != adults.end())
                adults[std::stoi(aux[4])].add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[4])) != elders.end())
                elders[std::stoi(aux[4])].add_event(std::stoi(aux[0]));

        } else if(aux[1].compare("adulto") == 0){   
            if(aux[2].compare("boate") == 0) {

                end = 6 + (std::stoi(aux[5])*2);
                for(int i = 6; i < aux.size(); i++){
                    if(i < end)
                        if(i % 2 == 0) 
                            capacities.push_back(std::stoi(aux[i]));
                        else 
                            prices.push_back(std::stof(aux[i]));
                    else 
                        schedules.push_back(std::stoi(aux[i]));  
                        if(i == end)
                            gateOpening = std::stoi(aux[i]);
                        else      
                            artists.push_back(aux[i]);  

                }
                Club newClub(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[4]), capacities, prices, std::stoi(aux[aux.size() - 3]), 
                    std::stoi(aux[aux.size() - 2]), std::stoi(aux[aux.size() - 1]));

                clubs.insert({newClub.get_id(), newClub});
                if(adults.find(std::stoi(aux[4])) != adults.end())
                    adults[std::stoi(aux[4])].add_event(std::stoi(aux[0]));
                else if(elders.find(std::stoi(aux[4])) != elders.end()) 
                    elders[std::stoi(aux[4])].add_event(std::stoi(aux[0]));

            } else {
                end = 6 + (std::stoi(aux[5])*2);
                
                for(int i = 6; i < end; i++){
                    if(i % 2 == 0) 
                        capacities.push_back(std::stoi(aux[i]));
                    else 
                        prices.push_back(std::stof(aux[i]));
                }
                for (int i = end + 2; i < aux.size(); i++){
                    artists.push_back(aux[i]);
                }
                
                Consert newConsert(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[4]), capacities, prices, 
                    std::stoi(aux[end]), std::stoi(aux[end + 1]), artists);

                conserts.insert({newConsert.get_id(), newConsert});
                if(adults.find(std::stoi(aux[4])) != adults.end())
                    adults[std::stoi(aux[4])].add_event(std::stoi(aux[0]));
                else if(elders.find(std::stoi(aux[4])) != elders.end()) 
                    elders[std::stoi(aux[4])].add_event(std::stoi(aux[0]));
            }
        } else {
            end = 5 + (std::stoi(aux[4])*2);
            for(int i = 5; i < end; i++){
                if(i % 2 == 0) 
                    prices.push_back(std::stoi(aux[i]));
                else 
                    capacities.push_back(std::stof(aux[i]));       
            }
            for (int i = end; i < aux.size() - 1; i++)
                schedules.push_back(std::stoi(aux[i]));
            
            MovieTheater newMovieTheater(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), capacities, prices, schedules, 
                std::stoi(aux[aux.size() - 1]));

            movieTheaters.insert({newMovieTheater.get_id(), newMovieTheater});
            if(adults.find(std::stoi(aux[3])) != adults.end())
                adults[std::stoi(aux[3])].add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[3])) != elders.end()) 
                elders[std::stoi(aux[3])].add_event(std::stoi(aux[0]));

        }
        aux.clear();
        capacities.clear();
        prices.clear();
        schedules.clear();
        artists.clear();
    } 
}





