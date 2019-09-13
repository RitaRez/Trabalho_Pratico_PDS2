// TESTING IS THIS THE NEW BRANCH?

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector> 
#include <map> 

#include "./lib/file_parser.hpp"


std::vector<std::string> read_file(std::string fileName){
    
    std::string object;
    std::vector<std::string> objectsArray;
    std::ifstream inFile;


    inFile.open(fileName);
    if (!inFile) {
        std::cerr << "Unable to open file\n";
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
    std::vector<std::string> usersArray;
    std::vector<std::string> eventsArray;

    if(argc != 3) {
        std::cerr << "There arent enough arguments\n";
        exit(1);
    }
    
    usersArray = read_file(argv[1]);
    eventsArray = read_file(argv[2]);

    FileParser fp(usersArray, eventsArray);
    fp.parse_users();
    fp.parse_events();

    fp.print_clubs();
    fp.print_conserts();
    fp.print_movie_theaters();
    fp.print_puppet_shows();

    return 0;
}