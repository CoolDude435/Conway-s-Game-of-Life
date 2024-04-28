#include "Ecosystem.h"

Ecosystem::Ecosystem() 
    : m_map{}, m_organisms{} {}
Ecosystem::Ecosystem(std::string mapFile, std::string speciesFile) 
    : m_organisms{} {
    int width = mapWidth(mapFile);
    int height = mapHeight(mapFile);
    m_map = Map(height,width);
    createSpeciesList(speciesFile);
    populateMap(mapFile);
}

void Ecosystem::populateMap(std::string mapFile) {
    std::ifstream mFile{mapFile};
    std::string row{};
    for (int i=0;i<m_map.getHeight();i++) {
        getline(mFile,row);
        for (int j=0;j<m_map.getWidth();j++) {
            char tile = row[j];
            if(tile!=' ') {
                Organism* organism = m_organisms[tile];
                SpeciesType type = organism->getSpeciesType();
                switch(type) {
                    case plant:
                        Plant* p = (dynamic_cast<Plant*>(organism))->clone();
                        p->setX(j);
                        p->setY(i);
                        m_map.getTile(j,i)->setPlant(p);
                    case herbivore:
                        Herbivore* h = (dynamic_cast<Herbivore*>(organism))->clone();
                        h->setX(j);
                        h->setY(i);
                        m_map.getTile(j,i)->setAnimal(h);
                    case omnivore:
                        Omnivore* o = (dynamic_cast<Omnivore*>(organism))->clone();
                        o->setX(j);
                        o->setY(i);
                        m_map.getTile(j,i)->setAnimal(o);
                    default:
                        std::cerr << "SpeciesType Invalid in Ecosystem::populateMap";
                        //This should never trigger, for testing purposes
                }
            }
        }
    }
}

void Ecosystem::createSpeciesList(std::string speciesFile) {
    std::ifstream sFile{speciesFile};
    std::string s{};
    while (getline(sFile,s)) {
        Organism* o = parseSpecies(s);
        m_organisms[o->getID()] = o;
    }
}

Map Ecosystem::getMap() { return m_map; }
std::unordered_map<char,Organism*> Ecosystem::getSpecies() { return m_organisms; }

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

int mapWidth(std::string mapFile) {
    int width{0};
    std::ifstream mFile{mapFile};
    std::string s{};
    while (getline(mFile,s)) {
        width++;
    }
    mFile.close();
    return width;
}

int mapHeight(std::string mapFile) {
    int height{0};
    std::ifstream mFile{mapFile};
    std::string s{};
    getline(mFile,s);
    height = s.length();
    mFile.close();
    return height;
}

int indexOf(std::string& s,char c) {
    for (int i=0;i<s.length();i++) {
        if (s[i]==c) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        std::string mapFile{argv[0]};
        std::string speciesFile{argv[1]};
    }
    

    Ecosystem ecosystem{"map.txt","species.txt"};
    ecosystem.getMap().print();
}