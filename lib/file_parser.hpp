#ifndef FILEPARSER_H
#define FILEPARSER_

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
         
    public:
        std::vector<std::string> static read_file(std::string fileName);
        void static parse_users(char *str, const std::map<int,Kid>& kids, const std::map<int,Adult>& adults, const std::map<int,Elder>& elders);
        void static parse_events(char *str, const std::map<int,Club>& clubs, const std::map<int,Consert>& conserts, const std::map<int,PuppetShow>& puppet_shows, const std::map<int,MovieTheater>& movieTheaters);

};
 
#endif