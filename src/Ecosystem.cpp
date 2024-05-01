#include "Ecosystem.h"

Ecosystem::Ecosystem() 
    : m_map{}, m_species{}, m_organisms{} {}
Ecosystem::Ecosystem(std::string& mapFile, std::string& speciesFile) 
    : m_species{}, m_organisms{} {
    int width = mapWidth(mapFile);
    int height = mapHeight(mapFile);
    m_map = Map(height,width);
    createSpeciesList(speciesFile);
    populateMap(mapFile);
}

void Ecosystem::populateMap(std::string& mapFile) {
    std::ifstream mFile{mapFile};
    std::string row{};
    for (int i=0;i<m_map.getHeight();i++) {
        getline(mFile,row);
        for (int j=0;j<m_map.getWidth();j++) {
            char tile = row[j];
            if(tile!=' ') {
                Organism* organism = m_species[tile];
                SpeciesType type = organism->getSpeciesType();
                switch(type) {
                    case plant:
                        {
                            Plant* p = (dynamic_cast<Plant*>(organism))->clone();
                            p->setX(j);
                            p->setY(i);
                            m_map.getTile(j,i)->setPlant(p);
                            m_organisms.insert(p);
                        }
                        break;
                    case herbivore:
                        {
                            Herbivore* h = (dynamic_cast<Herbivore*>(organism))->clone();
                            h->setX(j);
                            h->setY(i);
                            m_map.getTile(j,i)->setAnimal(h);
                            m_organisms.insert(h);
                        }
                        break;
                    case omnivore:
                        {
                            Omnivore* o = (dynamic_cast<Omnivore*>(organism))->clone();
                            o->setX(j);
                            o->setY(i);
                            m_map.getTile(j,i)->setAnimal(o);
                            m_organisms.insert(o);
                        }
                        break;
                    default:
                        std::cerr << "SpeciesType Invalid in Ecosystem::populateMap";
                        //This should never trigger, for testing purposes
                        break;
                }
            }
        }
    }
}

void Ecosystem::createSpeciesList(std::string& speciesFile) {
    std::ifstream sFile{speciesFile};
    std::string s{};
    while (getline(sFile,s)) {
        Organism* o = parseSpecies(s);
        m_species[o->getID()] = o;
    }
}

Map Ecosystem::getMap() { return m_map; }
std::unordered_map<char,Organism*> Ecosystem::getSpecies() { return m_species; }

void Ecosystem::iterate() {

}

void Ecosystem::iterate(int steps) {
    for (int i=0;i<steps;i++) {
        iterate();
    }
}

void Ecosystem::takeTurn(Organism* organism) {
    SpeciesType type = organism->getSpeciesType();
    switch(type) {
    case plant:
        {
            Plant* p = (dynamic_cast<Plant*>(organism))->clone();
            takeTurn(p);
        }
        break;
    case herbivore:
        {
            Herbivore* h = (dynamic_cast<Herbivore*>(organism))->clone();
            takeTurn(h);
        }
        break;
    case omnivore:
        {
            Omnivore* o = (dynamic_cast<Omnivore*>(organism))->clone();
            takeTurn(o);
        }
        break;
    default:
        std::cerr << "SpeciesType Invalid in Ecosystem::populateMap";
        //This should never trigger, for testing purposes
        break;
    }
}
void Ecosystem::takeTurn(Plant* plant) {
    if (plant->isEaten()) {
        if (m_map.getTile(plant->getX(),plant->getY())->hasAnimal()==false) {
            plant->grow();
        }
    }
}
void Ecosystem::takeTurn(Herbivore* herbivore) {}
void Ecosystem::takeTurn(Omnivore* omnivore) {
    std::vector<MapTile*> adjacent = m_map.getAdjacent(omnivore->getX(),omnivore->getY());
    std::vector<MapTile*> food{};
    std::vector<MapTile*> empty{};
    for (int i=0;i<adjacent.size();i++) {
        MapTile* tile = adjacent[i];
        if ((tile->hasAnimal()&&(tile->getAnimal()->getSpeciesType()==herbivore))) {
            if (omnivore->canConsume(dynamic_cast<Herbivore*>(tile->getAnimal()))) {
                food.push_back(tile);
            }
        } else if (tile->hasPlant()) {
            if (tile->getPlant()->isEaten()) {
                empty.push_back(tile);
            } else {
                if (omnivore->Animal::canConsume(tile->getPlant())) {
                    food.push_back(tile);
                }
            }
        } else {
            empty.push_back(tile);
        }
    }
}

Organism* parseSpecies(std::string& s) {
    Organism* organism;
    std::string type = s.substr(0,indexOf(s,' '));
    if (type.compare("plant")==0) {
        char id = s[6];
        s = s.substr(8,s.length());
        int spaceIdx = indexOf(s,' ');
        std::string s_regrowCoef = s.substr(0,spaceIdx);
        std::string s_energyPts = s.substr(spaceIdx+1,s.length());
        int regrowCoef = stoi(s_regrowCoef);
        int energyPts = stoi(s_energyPts);
        organism = new Plant(-1,-1,id,regrowCoef,energyPts);
    } else if (type.compare("herbivore")==0) {
        char id = s[10];
        std::string s_maxEnergy = s.substr(12,s.length());
        int maxEnergy = stoi(s_maxEnergy);
        organism = new Herbivore(-1,-1,id,maxEnergy);
    } else {
        char id = s[9];
        std::string s_maxEnergy = s.substr(11,s.length());
        int maxEnergy = stoi(s_maxEnergy);
        organism = new Omnivore(-1,-1,id,maxEnergy);
    }
    return organism;
}

int main(int argc, char* argv[]) {
    std::string path = "/space/jlin60/Desktop/CS3210 Project/project-CoolDude435/input/";
    if (argc == 2) {
        std::string mapFile{argv[0]};
        std::string speciesFile{argv[1]};
    }
    std::string map = path+"map.txt";
    std::string species = path+"species.txt";
    Ecosystem ecosystem{map,species};
    std::cout << "Width: " << ecosystem.getMap().getWidth() << '\n';
    std::cout << "Height: " << ecosystem.getMap().getHeight() << '\n';    
    ecosystem.getMap().print();
}