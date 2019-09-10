#ifndef FILEPARSER_H
#define FILEPARSER_

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
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
    std::vector<std::string> stringUser;
    std::vector<std::string> stringEvent;

    std::map<int, Kid> kids;
    std::map<int, Adult> adults;
    std::map<int, Elder> elders;

    std::map<int, MovieTheater> movieTheaters;
    std::map<int, PuppetShow> puppetShows;
    std::map<int, Consert> conserts;
    std::map<int, Club> clubs;

public:
    FileParser();
    FileParser(std::vector<std::string> stringUser, std::vector<std::string> stringEvent);

    void parse_users();
    void parse_events();
    void printKids();
    void printAdults();
    void printElders();
    

};
 
#endif