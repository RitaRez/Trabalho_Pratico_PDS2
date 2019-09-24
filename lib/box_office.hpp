#ifndef BOXOFFICE_H
#define BOXOFFICE_

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

class BoxOffice {
    
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
        BoxOffice(const char** args);

        std::map<int, Kid> get_kids(){return kids;}
        std::map<int, Adult> get_adults(){return adults;}
        std::map<int, Elder> get_elders(){return elders;}
        std::map<int, MovieTheater> get_movie_theaters(){return movieTheaters;}    
        std::map<int, PuppetShow> get_puppet_shows(){return puppetShows;} 
        std::map<int, Consert> get_conserts(){return conserts;}
        std::map<int, Club> get_clubs(){return clubs;}

        void get_ages (float *max, float *min, float *avarage);
        void get_dependents(float *max, float *min, float *avarage);
        void get_dependent_relations();
        void get_event_relations();
        void get_biggest_elder_amount();
        void get_tickets();

        void print_kids();
        void print_adults();
        void print_elders();
        void print_clubs();
        void print_conserts();
        void print_puppet_shows();
        void print_movie_theaters();
};

#endif