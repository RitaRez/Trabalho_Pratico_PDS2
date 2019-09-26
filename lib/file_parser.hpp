#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <vector> 
#include <map> 

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"

#include "./events/event.hpp"
#include "./events/infant_event.hpp"
#include "./events/puppet_show.hpp"
#include "./events/adult_event.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class FileParser{
    private:
        std::vector<std::string> static read_file(std::string fileName);
        
        void static add_puppet_show(std::map<int,PuppetShow>& puppetShows,std::vector<std::string> objs, std::vector<int> capacity, std::vector<float> prices, std::vector<int> theaterSchedules);   
        void static add_club(std::map<int,Club>& clubs, std::vector<std::string> objs, std::vector<int> capacity, std::vector<float> prices);
        void static add_consert(std::map<int,Consert>& conserts, std::vector<std::string> objs, std::vector<int> capacity, std::vector<float> prices, std::vector<std::string> artists);
        void static add_movie_theater(std::map<int,MovieTheater>& movieTheaters, std::vector<std::string> objs, std::vector<int> capacity, std::vector<float> prices, std::vector<int> theaterSchedules);
     
    public:
        void static parse_events(char *str, std::map<int,Club>& clubs, std::map<int,Consert>& conserts, std::map<int,PuppetShow>& puppet_shows, std::map<int,MovieTheater>& movieTheaters, std::map<int,Adult>& adults, std::map<int,Elder>& elders);
        void static parse_users(char *str, std::map<int,Kid>& kids, std::map<int,Adult>& adults, std::map<int,Elder>& elders);

};
 
#endif