#include <iostream>
#include <fstream>
#include <vector>
#include <./lib/User.hpp>


std::vector<User> parse_users(std::string StringArray){

}

std::vector<std::string> read_file(std::string fileName){
    
    std::string object;
    std::vector<std::string> objectsArray;
    std::ifstream inFile;


    inFile.open(fileName);
    if (!inFile) {
        std::cerr << "Unable to open file";
        exit(2); 
    } 

    while(!inFile.eof()){
        getline(inFile, object);
        objectsArray.push_back(object);
    }
    inFile.close();

    return objectsArray;
}


int main(int argc, const char** argv) {
    
    std::ifstream inFile;
    std::vector<std::string> UsersArray;
    std::vector<std::string> EventsArray;

    if(argc != 3) {
        std::cerr << "There arent enough arguments";
        exit(1);
    }
    
    UsersArray = read_file(argv[1]);
    EventsArray = read_file(argv[2]);


    return 0;
}