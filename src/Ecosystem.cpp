#include "Ecosystem.h"

Ecosystem::Ecosystem() 
    : m_map{}, m_organisms{} {}
Ecosystem::Ecosystem(std::string mapFile, std::string speciesFile) {
    int width = mapWidth(mapFile);
    int height = mapHeight(mapFile);
    m_map = Map(height,width);

    createSpeciesList(speciesFile);
    populateMap(mapFile);
}

void Ecosystem::populateMap(std::string mapFile) {

}

void Ecosystem::createSpeciesList(std::string speciesFile) {
    std::ifstream sFile{speciesFile};
    std::string s{};
    while (getline(sFile,s)) {
        Organism o = parseSpecies(s);
        m_organisms[o.getID()] = o;
    }
}

Organism parseSpecies(std::string& s) {
    std::string type = s.substr(0,indexOf(s,' '));
    if (type.compare("plant")==0) {
        char id = s[6];
        s = s.substr(8,s.length());
        int spaceIdx = indexOf(s,' ');
        std::string s_regrowCoef = s.substr(0,spaceIdx);
        std::string s_energyPts = s.substr(spaceIdx+1,s.length());
        int regrowCoef = stoi(s_regrowCoef);
        int energyPts = stoi(s_energyPts);
        Organism organism = Plant(-1,-1,id,regrowCoef,energyPts);
    } else if (type.compare("herbivore")==0) {

    } else {

    }
    
    return Organism{};
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