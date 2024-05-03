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
        void iterate();
        void iterate(int steps);
    private:
        void populateMap(std::string& mapFile);
        void setUpOrganism(Organism* organism, int x, int y);
        void createSpeciesList(std::string& speciesFile);
        void takeTurn(Organism* organism);
        void takeTurn(Plant* plant);
        void takeTurn(Herbivore* herbivore);
        void takeTurn(Omnivore* omnivore);
        void sortTiles(Omnivore* omnivore, std::vector<MapTile*>& food, std::vector<MapTile*>& empty);
        void sortTiles(Herbivore* herbivore, std::vector<MapTile*>& predator, std::vector<MapTile*>& food, std::vector<MapTile*>& empty);
        void moveAnimal(Animal* animal, MapTile* tile);
        void tryEscape(Herbivore* prey, Omnivore* predator);
        bool tryEscapeTo(Herbivore* prey, int x, int y);
};

Organism* parseSpecies(std::string& s);
void Menu(Ecosystem& ecosystem);


