#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Event {

    protected:
        int id;
        int responsible;
        std::string category;
        std::string name;
        std::vector<int> capacity;
        std::vector<float> prices;

    public:  
        int get_id() { return id; }
        int get_responsible() { return responsible; }
        std::string get_category() { return category; }
        std::string get_name() { return name; }
        std::vector<int> get_capacity()  { return capacity; }
        void set_capacity(int new_capacity, int index)  { this->capacity[index] -= new_capacity; }
        std::vector<float> get_prices()  { return prices; }
};
 
#endif