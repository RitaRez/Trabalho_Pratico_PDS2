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

void FileParser::parse_users(char *str, const std::map<int,Kid>& kids, const std::map<int,Adult>& adults, const std::map<int,Elder>& elders){
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
                        prices.push_back(std::stoi(aux[i]));
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
                    capacities.push_back(std::stoi(aux[i]));
                else 
                    prices.push_back(std::stoi(aux[i]));       
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

std::vector<float> FileParser::get_ages(){
    std::map<int, Kid>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::map<int, Elder>::iterator itr3; 

    std::vector<float> ages; 
    float min, max = 0, avarage = 0;
    int userCount = kids.size() + adults.size() + elders.size();
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        if(avarage == 0)
            min = itr->second.get_age();
        if(itr->second.get_age() < min)
            min = itr->second.get_age();
        if(itr->second.get_age() > max)
            max = itr->second.get_age();
        avarage += itr->second.get_age();    
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(itr2->second.get_age() < min)
            min = itr2->second.get_age();
        if(itr2->second.get_age() > max)
            max = itr2->second.get_age();
        avarage += itr2->second.get_age();    
    } 
    for (itr3 = elders.begin(); itr3 != elders.end(); ++itr3) { 
        if(itr3->second.get_age() < min)
            min = itr3->second.get_age();
        if(itr3->second.get_age() > max)
            max = itr3->second.get_age();
        avarage += itr3->second.get_age();    
    }    
    avarage = avarage/userCount;
    ages = {min, max, avarage};
    return ages;
}

std::vector<float> FileParser::get_dependents(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 

    std::vector<float> dependents; 
    float min = elders.begin()->second.get_children().size(), max = 0, avarage = 0;
    int userCount = adults.size() + elders.size();
    int size = 0;

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        if(!itr->second.get_children().empty())
            size = itr->second.get_children().size();
        if(size < min)
            min = size;
        if(size > max)
            max = size;

    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(!itr2->second.get_children().empty())
            size = itr2->second.get_children().size();
        if(size < min)
           min = size;
        if(size > max)
            max = size;
    }
    avarage = (float)kids.size()/userCount;
    dependents = {min, max, avarage};
    return dependents;
}

std::string FileParser::get_dependent_relations(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::vector<int>::iterator itrChildren; 
    std::string str;

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        if(!itr->second.get_children().empty()){
            str += itr->second.get_name() + "(ID: " + std::to_string(itr->second.get_id()) + "): ";
            for(auto child: itr->second.get_children()){
                str += kids[child].get_name(); + "(ID: " + std::to_string(child) + "),";
            }
        }
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(!itr2->second.get_children().empty()){
            str += "\n" + itr2->second.get_name() + "(ID: " + std::to_string(itr2->second.get_id()) + "): ";
            for(auto child: itr2->second.get_children())
                str += kids[child].get_name() + "(ID: " + std::to_string(child) + "), ";
    
        }
    }
    return str;
}

std::string FileParser::get_event_relations(){
    return "";
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

void FileParser::print_adults(){
    std::map<int, Adult>::iterator itr; 
    int id;
    
    for (itr = adults.begin(); itr != adults.end(); ++itr) {
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget()
        << std::endl; 
    } 
}

void FileParser::print_elders(){
    std::map<int, Elder>::iterator itr; 
    int id;
    
    for (itr = elders.begin(); itr != elders.end(); ++itr) {
        std::cout 
            << "\nId: " << itr->second.get_id() 
            << "\nName:" << itr->second.get_name() 
            << "\nAge:" << itr->second.get_age() 
            << "\nBudget:" << itr->second.get_budget()
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





