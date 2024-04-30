#pragma once

#include "Map.h"
#include "Herbivore.h"
#include "Omnivore.h"
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include "util.h"

class Ecosystem
{
    private:
        Map m_map{};
        std::unordered_map<char,Organism*> m_species{};

    public:
        Ecosystem();
        Ecosystem(std::string mapFile, std::string speciesFile);
        Map getMap();
        std::unordered_map<char,Organism*> getSpecies();
        void iterate();
        void iterate(int steps);
    private:
        void populateMap(std::string mapFile);
        void createSpeciesList(std::string speciesFile);
        
        

};

Organism* parseSpecies(std::string& s);

