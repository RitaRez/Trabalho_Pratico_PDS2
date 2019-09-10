#include <iostream>
#include <string>
#include <vector>

#ifndef EVENT_H
#define EVENT_H
 
class Event {

protected:
    std::string id;
    std::string name;
    std::vector<int> capacity;
    std::vector<int> prices;

public:  
    std::string get_id() { return id; }
    std::string get_name() { return name; }
    std::vector<int> get_capacity()  { return capacity; }
    std::vector<int> get_prices()  { return prices; }
};
 
#endif