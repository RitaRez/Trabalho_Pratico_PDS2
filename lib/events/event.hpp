#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>
 
class Event {

    protected:
        int id;
        int responsible;
        std::string category;
        std::string name;
        std::vector<int> capacity;
        std::vector<int> prices;

    public:  
        int get_id() { return id; }
        int get_responsible() { return responsible; }
        std::string get_category() { return category; }
        std::string get_name() { return name; }
        std::vector<int> get_capacity()  { return capacity; }
        std::vector<int> get_prices()  { return prices; }
};
 
#endif