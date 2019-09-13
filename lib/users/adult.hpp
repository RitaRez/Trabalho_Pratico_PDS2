#ifndef ADULT_H
#define ADULT_H

class User;
class Kid;

class Adult: public User{
    
private:
    std::vector<int> children;
    
public:
    Adult();
    Adult(int id, std::string category, std::string name, int age, float budget);

    std::vector<int> get_children(){return children;}
    void add_children(int kid);

};
 
#endif