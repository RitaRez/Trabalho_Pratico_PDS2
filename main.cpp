#include <iostream>
#include <iomanip>
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

void output(FileParser fp){
    std::vector<float> age = fp.get_ages();
    std::vector<float> dependent = fp.get_dependents();

    std::cout 
        << "Número de usuários:" << std::endl
        << "Crianças: " << fp.get_kids().size() << std::endl 
        << "Adultos: " << fp.get_adults().size() + fp.get_elders().size() << std::endl 
        << "Idosos: " << fp.get_elders().size() << std::endl 
        
        << std::endl << "Idade dos usuários:" << std::endl
        << "Mínimo: " << age[0] << std::endl
        << "Máximo: " << age[1] << std::endl
        << "Média: " << std::setprecision(2) << std::fixed << age[2] << std::endl

        << std::endl << "Número de dependentes:" << std::endl << std::setprecision(0) << std::fixed
        << "Mínimo: " << dependent[0] << std::endl
        << "Máximo: " << dependent[1] << std::endl
        << "Média: " << std::setprecision(2) << std::fixed << dependent[2] << std::endl

        << std::endl << "Dependentes:" << std::setprecision(0) << std::fixed
        << fp.get_dependent_relations() << std::endl

        << std::endl << "Número de eventos:" << std::endl
        << "Adultos:" << std::endl
        << '\t' << "Boate: " << fp.get_clubs().size() << std::endl
        << '\t' << "Show: " << fp.get_conserts().size() << std::endl
        << "Livres: " << std::endl
        << '\t' << "Cinema: " << fp.get_movie_theaters().size() << std::endl
        << "Infantis: " << std::endl
        << '\t' << "Teatro de fantoches: " << fp.get_puppet_shows().size() << std::endl

        << std::endl << "Número de eventos que o usuário possui:" << std::endl
        << fp.get_event_relations() << std::endl;


        
}

int main(int argc, const char** argv) {
    
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

    output(fp);
    // fp.print_adults();
    // fp.print_elders();

    return 0;
}