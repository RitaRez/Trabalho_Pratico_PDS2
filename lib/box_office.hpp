#ifndef BOX_OFFICE_H
#define BOX_OFFICE_H

#include <set>
#include <map>

#include "./users/user.hpp"
#include "./users/kid.hpp"
#include "./users/adult.hpp"
#include "./users/elder.hpp"

#include "./events/puppet_show.hpp"
#include "./events/club.hpp"
#include "./events/consert.hpp"
#include "./events/movie_theater.hpp"

class BoxOffice {
    
    private:
        std::map<int, Kid*> kids;
        std::map<int, Adult*> adults;
        std::map<int, Elder*> elders;
        std::map<int, MovieTheater*> movieTheaters;
        std::map<int, PuppetShow*> puppetShows;
        std::map<int, Consert*> conserts;
        std::map<int, Club*> clubs;
        
        std::set<int> loggedId;
        std::map<int, int> boughtClubs, boughtConserts, boughtMovies, boughtPuppets;


    public:
        BoxOffice();
        
        std::map<int, Kid*> get_kids(){return kids;}
        std::map<int, Adult*> get_adults(){return adults;}
        std::map<int, Elder*> get_elders(){return elders;}
        std::map<int, MovieTheater*> get_movie_theaters(){return movieTheaters;}    
        std::map<int, PuppetShow*> get_puppet_shows(){return puppetShows;} 
        std::map<int, Consert*> get_conserts(){return conserts;}
        std::map<int, Club*> get_clubs(){return clubs;}


        void initialize(const char** args);
        int menu_text();
        int login();
        void print_users();
        int print_events();

        void get_ages (float *max, float *min, float *avarage);
        void get_dependents(float *max, float *min, float *avarage);
        void get_dependent_relations();
        void get_event_relations();
        void get_biggest_elder_amount();
        void get_tickets();

        std::set<int> get_logged_id(){return this->loggedId;}
        void add_logged_id(int id){
            this->loggedId.insert(id);
        }


        std::map<int,int> get_bought_clubs(){return this->boughtClubs;}
        std::map<int,int> get_bought_conserts(){return this->boughtConserts;}
        std::map<int,int> get_bought_movies(){return this->boughtMovies;}
        std::map<int,int> get_bought_puppet(){return this->boughtPuppets;}
        
        void add_bought_club(int id, int amount);      
        void add_bought_consert(int id, int amount);       
        void add_bought_movie(int id, int amount);      
        void add_bought_puppet(int id, int amount);
};

#endif