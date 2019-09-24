#include "../lib/box_office.hpp"
#include "../lib/file_parser.hpp"
#include <iomanip>


BoxOffice::BoxOffice(const char** args){
    FileParser::parse_users((char *)args[1], kids, adults, elders);
    FileParser::parse_events((char *)args[2], clubs, conserts, puppetShows, movieTheaters, adults, elders);
}

void BoxOffice::get_ages(float *max, float *min, float *avarage){
    std::map<int, Kid>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::map<int, Elder>::iterator itr3; 
    
    *max = 0;
    *avarage = 0;
    int userCount = kids.size() + adults.size() + elders.size();
    
    for (itr = kids.begin(); itr != kids.end(); ++itr) { 
        if(*avarage == 0)
            *min = itr->second.get_age();
        if(itr->second.get_age() < *min)
            *min = itr->second.get_age();
        if(itr->second.get_age() > *max)
            *max = itr->second.get_age();
        *avarage += itr->second.get_age();    
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(itr2->second.get_age() < *min)
            *min = itr2->second.get_age();
        if(itr2->second.get_age() > *max)
            *max = itr2->second.get_age();
        *avarage += itr2->second.get_age();    
    } 
    for (itr3 = elders.begin(); itr3 != elders.end(); ++itr3) { 
        if(itr3->second.get_age() < *min)
            *min = itr3->second.get_age();
        if(itr3->second.get_age() > *max)
            *max = itr3->second.get_age();
        *avarage += itr3->second.get_age();    
    }    
}

void BoxOffice::get_dependents(float *max, float *min, float *avarage){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 

    *min = elders.begin()->second.get_children().size(), 
    *max = 0, 
    *avarage = 0;
    int userCount = adults.size() + elders.size();
    int size = 0;

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        if(!itr->second.get_children().empty())
            size = itr->second.get_children().size();
        if(size < *min)
            *min = size;
        if(size > *max)
            *max = size;
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(!itr2->second.get_children().empty())
            size = itr2->second.get_children().size();
        if(size < *min)
           *min = size;
        if(size > *max)
            *max = size;
    }
}

void BoxOffice::get_dependent_relations(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 
    std::vector<int>::iterator itrChildren; 

    for (itr = elders.begin(); itr != elders.end(); ++itr) { 
        if(!itr->second.get_children().empty()){
            std::cout << std::setprecision(0) << std::fixed << itr->second.get_name() + "(ID: " << itr->second.get_id() << "): ";
            for(auto child: itr->second.get_children())
                std::cout << kids[child].get_name() + "(ID: " << child << "),";
        }
    } 

    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2) { 
        if(!itr2->second.get_children().empty()){
            std::cout << std::setprecision(0) << std::fixed << "\n" + itr2->second.get_name() + "(ID: " << itr2->second.get_id() << "): ";
            for(auto child: itr2->second.get_children())
                std::cout << std::setprecision(0) << std::fixed << kids[child].get_name() + "(ID: " << child << "), ";
        }
    }
    std::cout << std::endl;
}

void BoxOffice::get_event_relations(){
    std::map<int, Elder>::iterator itr; 
    std::map<int, Adult>::iterator itr2; 

    for (itr = elders.begin(); itr != elders.end(); ++itr) 
        if(!itr->second.get_events().empty())
            std::cout << itr->second.get_name() << "(ID: " << itr->second.get_id() << "): " 
            << itr->second.get_events().size() << std::endl;
        
    for (itr2 = adults.begin(); itr2 != adults.end(); ++itr2)
        if(!itr2->second.get_events().empty())
            std::cout << itr2->second.get_name() << "(ID: " << itr2->second.get_id() << "): " 
            << itr2->second.get_events().size() << std::endl;
            
}

void BoxOffice::get_biggest_elder_amount(){
    std::map<int,Club>::iterator itr;
    std::map<int,Consert>::iterator itr2;
    std::string name;
    std::string id;
    int max;

    for(itr = clubs.begin(); itr != clubs.end(); ++itr){
        if(max < itr->second.get_elder_amout()){
            max = itr->second.get_elder_amout();
            name = itr->second.get_name();
            id = std::to_string(itr->second.get_id());
        }    
    }

    for(itr2 = conserts.begin(); itr2 != conserts.end(); ++itr2){
        if(max < itr2->second.get_elder_amout()){
            max = itr2->second.get_elder_amout();
            name = itr2->second.get_name();
            id = std::to_string(itr2->second.get_id());
        }    
    }
    
    std::cout << name + " (ID: " + id + "): " << max;
}

void BoxOffice::get_tickets(){

    std::map<float, int> tickets;
    std::vector<float> prices;
    std::vector<int> capacity;

    std::map<float, int>::iterator t_itr;
    std::map<int,PuppetShow>::iterator puppet_itr;
    std::map<int,MovieTheater>::iterator movie_itr;
    std::map<int,Consert>::iterator consert_itr;
    std::map<int,Club>::iterator club_itr;

    for(puppet_itr = puppetShows.begin() ;puppet_itr != puppetShows.end(); ++puppet_itr){
        prices = puppet_itr->second.get_prices();
        capacity = puppet_itr->second.get_capacity();

        for (int i = 0; i < puppet_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(movie_itr = movieTheaters.begin(); movie_itr != movieTheaters.end(); ++movie_itr){
        prices = movie_itr->second.get_prices();
        capacity = movie_itr->second.get_capacity();

        for (int i = 0; i < movie_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(consert_itr = conserts.begin() ;consert_itr != conserts.end(); ++consert_itr){
        prices = consert_itr->second.get_prices();
        capacity = consert_itr->second.get_capacity();

        for (int i = 0; i < consert_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();         
    }

    for(club_itr = clubs.begin(); club_itr != clubs.end(); ++club_itr){
        prices = club_itr->second.get_prices();
        capacity = club_itr->second.get_capacity();

        for (int i = 0; i < club_itr->second.get_capacity().size(); i++)
            tickets[prices[i]] += capacity[i];

        prices.clear();
        capacity.clear();   
    }
    for (t_itr = tickets.begin() ;t_itr != tickets.end(); ++t_itr)
        std::cout << "R$:" << t_itr->first << ": " << t_itr->second << std::endl;
        
}

void BoxOffice::print_clubs(){
    std::map<int, Club>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
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

void BoxOffice::print_conserts(){
    std::map<int, Consert>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
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

void BoxOffice::print_movie_theaters(){
    std::map<int, MovieTheater>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
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

void BoxOffice::print_puppet_shows(){
    std::map<int, PuppetShow>::iterator itr; 
    std::vector<int> capacity;
    std::vector<float> prices;
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