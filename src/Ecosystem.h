#pragma once

#include "Map.h"
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>

class Ecosystem
{
    private:
        Map m_map{};
        std::unordered_map<char,Organism> m_organisms{};

    public:
        Ecosystem();
        Ecosystem(std::string mapFile, std::string speciesFile);
    private:
        void populateMap(std::string mapFile);
        void createSpeciesList(std::string speciesFile);
        

};

Organism parseSpecies(std::string& s);
int mapWidth(std::string mapFile);
int mapHeight(std::string mapFile);
int indexOf(std::string& s,char c);
