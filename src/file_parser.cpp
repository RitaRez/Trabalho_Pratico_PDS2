#include "../lib/file_parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>


std::vector<std::string> FileParser::read_file(std::string fileName){
    
    std::string object;
    std::string endLine;
    int num = 48;
    std::vector<std::string> objectsArray;
    std::ifstream inFile;

    inFile.open(fileName);
    if (!inFile) {
        std::cerr << "Unable to open file\n";
        exit(2); 
    } 

    while(!inFile.eof()){
        getline(inFile, object);
        if((int)object[0] == num){
            objectsArray.push_back(object);
        }
        num++;
    }
    inFile.close();

    return objectsArray;
}

PuppetShow* FileParser::create_puppet_show(std::vector<std::string> objs){   
    std::vector<int> capacity, schedules;
    std::vector<float> prices;   
    int end = 6 + (std::stoi(objs[5])*2);

    for(int i = 6; i < objs.size(); i++){
        if(i < end)
            if(i % 2 == 0) 
                capacity.push_back(std::stoi(objs[i]));
            else 
                prices.push_back(std::stof(objs[i]));
        else 
            schedules.push_back(std::stoi(objs[i]));  
             
    }
    PuppetShow *ps = new PuppetShow(std::stoi(objs[0]), objs[2], objs[3], std::stoi(objs[4]), capacity, prices, schedules);
    return ps;
}

Club* FileParser::create_club(std::vector<std::string> objs){   
    std::vector<int> capacity;    
    std::vector<float> prices;    
    int end = 6 + (std::stoi(objs[5])*2);

    for(int i = 6; i < objs.size(); i++){
        if(i < end)
            if(i % 2 == 0)  
                capacity.push_back(std::stoi(objs[i]));
            else   
                prices.push_back(std::stof(objs[i]));
    }
    Club *c = new Club(std::stoi(objs[0]), objs[2], objs[3], std::stoi(objs[4]), capacity, prices, std::stoi(objs[objs.size() - 3]), 
        std::stoi(objs[objs.size() - 2]), std::stoi(objs[objs.size() - 1]));
   
    return c;    
}

Consert* FileParser::create_consert(std::vector<std::string> objs){
    std::vector<float> prices;    
    std::vector<int> capacity;
    std::vector<std::string> artists;
    int end = 6 + (std::stoi(objs[5])*2);

    for(int i = 6; i < end; i++){
        if(i % 2 == 0) 
            capacity.push_back(std::stoi(objs[i]));
        else 
            prices.push_back(std::stof(objs[i]));
    }
    for (int i = end + 2; i < objs.size(); i++){
        artists.push_back(objs[i]);
    }
    Consert *c = new Consert(std::stoi(objs[0]), objs[2], objs[3], std::stoi(objs[4]), capacity, prices, std::stoi(objs[end]), 
        std::stoi(objs[end + 1]), artists);
    return c;    
}

MovieTheater* FileParser::create_movie_theater(std::vector<std::string> objs){
    std::vector<int> capacity, schedules;
    std::vector<float> prices;
    int end = 5 + (std::stoi(objs[4])*2);
    
    for(int i = 5; i < end; i++){
        if(i % 2 == 0) 
            prices.push_back(std::stoi(objs[i]));
        else 
            capacity.push_back(std::stof(objs[i]));       
    }
    for (int i = end; i < objs.size() - 1; i++)
        schedules.push_back(std::stoi(objs[i]));

    MovieTheater *mt = new MovieTheater(std::stoi(objs[0]), objs[1], objs[2], std::stoi(objs[3]), capacity, prices, schedules, 
        std::stoi(objs[objs.size() - 1]));
    return mt;    
}

void FileParser::parse_events(char *str, std::map<int,Club*>& clubs, std::map<int,Consert*>& conserts, std::map<int,PuppetShow*>& puppetShows, std::map<int,MovieTheater*>& movieTheaters, std::map<int,Adult*>& adults, std::map<int,Elder*>& elders){
    std::vector<std::string> stringEvent = read_file(str), aux;

    for(std::string str : stringEvent){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){
            aux.push_back(token);
        }    
        if(aux[1].compare("infantil") == 0){         
            PuppetShow *ps = create_puppet_show(aux);
            puppetShows.insert({ps->get_id(), ps});
            
            if(adults.find(std::stoi(aux[4])) != adults.end())       
                adults[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[4])) != elders.end())  
                elders[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
        } else if(aux[1].compare("adulto") == 0 && aux[2].compare("boate") == 0){   
            Club *club = create_club(aux);
            clubs.insert({club->get_id(), club});

            if(adults.find(std::stoi(aux[4])) != adults.end())        
                adults[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[4])) != elders.end())   
                elders[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
        } else if (aux[1].compare("adulto") == 0 && aux[2].compare("show") == 0){
            Consert *consert = create_consert(aux);                
            conserts.insert({consert->get_id(), consert});

            if(adults.find(std::stoi(aux[4])) != adults.end())        
                adults[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[4])) != elders.end())   
                elders[std::stoi(aux[4])]->add_event(std::stoi(aux[0]));
        } else {    
            MovieTheater *mt = create_movie_theater(aux);  
            movieTheaters.insert({mt->get_id(), mt});
          
            if(adults.find(std::stoi(aux[3])) != adults.end())        
                adults[std::stoi(aux[3])]->add_event(std::stoi(aux[0]));
            else if(elders.find(std::stoi(aux[3])) != elders.end())   
                elders[std::stoi(aux[3])]->add_event(std::stoi(aux[0]));
        }
        aux.clear();
    } 
}

void FileParser::parse_users(char *str, std::map<int,Kid*>& kids, std::map<int,Adult*>& adults, std::map<int,Elder*>& elders){
    std::vector<std::string> aux;  
    std::vector<std::string> stringUser = read_file(str);
    
    for(std::string str : stringUser){
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, ',')){
            aux.push_back(token);
        }  
        if(aux[1] == "crianca"){    
            Kid *newKid = new Kid(std::stoi(aux[0]), aux[1], aux[2], std::stoi(aux[3]), std::stof(aux[4]), std::stoi(aux[5]));
            kids.insert({newKid->get_id(), newKid});
            if(adults.find(std::stoi(aux[5])) != adults.end())
                adults[std::stoi(aux[5])]->add_children(newKid->get_id());
            else    
                elders[std::stoi(aux[5])]->add_children(newKid->get_id());
         } else if(aux[1] == "adulto"){
            Adult *newAdult = new Adult(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            adults.insert({newAdult->get_id(), newAdult});    
        } else if (aux[1] == "idoso") {
            Elder *newElder = new Elder(std::stoi(aux[0]),aux[1], aux[2],std::stoi(aux[3]),std::stof(aux[4]));
            elders.insert({newElder->get_id(), newElder});   
        }
        aux.clear();
    } 
}





