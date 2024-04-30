#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include "Map.h"
#include "Herbivore.h"
#include "Omnivore.h"
#include "util.h"

class Ecosystem
{
    private:
        Map m_map{};
        std::unordered_map<char,Organism*> m_species{};
        std::unordered_set<Organism*> m_organisms{};

    public:
        Ecosystem();
        Ecosystem(std::string& mapFile, std::string& speciesFile);
        Map getMap();
        std::unordered_map<char,Organism*> getSpecies();
        void iterate();
        void iterate(int steps);
    private:
        void populateMap(std::string& mapFile);
        void createSpeciesList(std::string& speciesFile);
        void takeTurn(Organism* organism);
        void takeTurn(Plant* plant);
        void takeTurn(Herbivore* herbivore);
        void takeTurn(Omnivore* omnivore);

};

Organism* parseSpecies(std::string& s);

