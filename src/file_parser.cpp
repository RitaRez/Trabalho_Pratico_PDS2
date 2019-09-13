#include "../lib/file_parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>


FileParser::FileParser(std::vector<std::string> stringUser, std::vector<std::string> stringEvent){
    this->stringUser = stringUser;
    this->stringEvent = stringEvent;   
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

    std::vector<int> capacities;
    std::vector<int> prices;
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
                        prices.push_back(std::stoi(aux[i]));
                else 
                    schedules.push_back(std::stoi(aux[i]));  
                    if(i == end)
                        gateOpening = std::stoi(aux[i]);
                    else      
                        artists.push_back(aux[i]);  
            }
            PuppetShow newPuppetShow(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[4]), capacities, prices, schedules);
            puppetShows.insert({newPuppetShow.get_id(), newPuppetShow});
        
        } else if(aux[1].compare("adulto") == 0){   
            if(aux[2].compare("boate") == 0) {
                end = 6 + (std::stoi(aux[5])*2);
                for(int i = 6; i < aux.size(); i++){
                    if(i < end)
                        if(i % 2 == 0) 
                            capacities.push_back(std::stoi(aux[i]));
                        else 
                            prices.push_back(std::stoi(aux[i]));
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
            } else {
                end = 6 + (std::stoi(aux[5])*2);
                
                for(int i = 6; i < end; i++){
                    if(i % 2 == 0) 
                        capacities.push_back(std::stoi(aux[i]));
                    else 
                        prices.push_back(std::stoi(aux[i]));
                }
                for (int i = end + 2; i < aux.size(); i++){
                    artists.push_back(aux[i]);
                }
                
                Consert newConsert(std::stoi(aux[0]), aux[2], aux[3], std::stoi(aux[4]), capacities, prices, 
                    std::stoi(aux[end]), std::stoi(aux[end + 1]), artists);

                conserts.insert({newConsert.get_id(), newConsert});
            }
        } else {
            end = 5 + (std::stoi(aux[4])*2);
            for(int i = 5; i < end; i++){
                if(i % 2 == 0) 
                    capacities.push_back(std::stoi(aux[i]));
                else 
                    prices.push_back(std::stoi(aux[i]));       
            }
            for (int i = end; i < aux.size() - 1; i++)
                schedules.push_back(std::stoi(aux[i]));
            
            MovieTheater newMovieTheater(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), capacities, prices, schedules, 
                std::stoi(aux[aux.size() - 1]));

            movieTheaters.insert({newMovieTheater.get_id(), newMovieTheater});
        }
        aux.clear();
        capacities.clear();
        prices.clear();
        schedules.clear();
        artists.clear();
    } 
}

void FileParser::print_kids(){
    std::map<int, Kid>::iterator itr; 
    int id;
    std::string responsible;
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();
                
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget() 
            << "\nResponsible's name:" << responsible
        << std::endl; 
    } 
}

void FileParser::print_clubs(){
    std::map<int, Club>::iterator itr; 
    std::vector<int> capacity;
    std::vector<int> prices;
    int id;
    std::string responsible;


    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    for (itr = clubs.begin(); itr != clubs.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();
         
        std::cout << "\nClub: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nElder amount: " << itr->second.get_elder_amout() 
            << "\nStarting Time: " << itr->second.get_starting_time() << ":00"
            << "\nEnding Time: " << itr->second.get_ending_time() << ":00"
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";   

        capacity.clear();
        prices.clear();

    } 
}

void FileParser::print_conserts(){
    std::map<int, Consert>::iterator itr; 
    std::vector<int> capacity;
    std::vector<int> prices;
    std::vector<std::string> artists;
    int id;
    std::string responsible;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = conserts.begin(); itr != conserts.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        artists = itr-> second.get_artists();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();

        std::cout << "\nConsert: " << itr->second.get_name()  << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nElder amount: " << itr->second.get_elder_amout() 
            << "\nGate opening time: " << itr->second.get_gate_opening() << ":00"
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        std::cout << "\nArtists: ";    
        for (int i = 0; i < artists.size(); i++)
            std::cout << "\n- " << artists[i];    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";   
        
        capacity.clear();
        prices.clear();
        artists.clear();
        
    } 
}

void FileParser::print_movie_theaters(){
    std::map<int, MovieTheater>::iterator itr; 
    std::vector<int> capacity;
    std::vector<int> prices;
    std::vector<int> movieSchedules;
    int id;
    std::string responsible;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = movieTheaters.begin(); itr != movieTheaters.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        movieSchedules = itr->second.get_movie_schedules();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();

        std::cout << "\nFilm: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nRunning time: " << itr->second.get_running_time() << " hours"
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        std::cout << "\nSchedules: ";    
        for (int i = 0; i < movieSchedules.size(); i++)
            std::cout << "\n- " << movieSchedules[i] << ":00";    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";  

        movieSchedules.clear();
        capacity.clear();
        prices.clear();  
    } 
}

void FileParser::print_puppet_shows(){
    std::map<int, PuppetShow>::iterator itr; 
    std::vector<int> capacity;
    std::vector<int> prices;
    std::vector<int> schedules;
    int id;
    std::string responsible;

    std::cout << 
        "-----------------------------------------------------------------------------------------------------------------------------------" 
    << std::endl;
    
    for (itr = puppetShows.begin(); itr != puppetShows.end(); ++itr) { 
        capacity = itr->second.get_capacity();
        prices = itr->second.get_prices();
        schedules = itr->second.get_schedules();
        id = itr->second.get_responsible();
        
        if(adults.find(id) != adults.end())
            responsible = adults[id].get_name();
        else 
            responsible = elders[id].get_name();

        std::cout << "\nPuppet Show: " << itr->second.get_name() << std::endl;
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nResponsible's name: " << responsible 
        << std::endl; 

        std::cout << "\nSchedules: ";    
        for (int i = 0; i < schedules.size(); i++)
            std::cout << "\n- " << schedules[i] << ":00";    
        
        std::cout << "\n\n";
        for (int i = 0; i < prices.size(); i++)
            std::cout << "Capacity: " << capacity[i] << "  Price: " << prices[i] << std::endl;
        std::cout << "\n";  

        schedules.clear();
        capacity.clear();
        prices.clear();  
    } 
}





