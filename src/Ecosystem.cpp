#include "Ecosystem.h"

Ecosystem::Ecosystem() 
    : m_map{}, m_species{}, m_organisms{} {}
Ecosystem::Ecosystem(std::string& mapFile, std::string& speciesFile) 
    : m_species{}, m_organisms{} {
    //get the dimensions of the map
    int width = mapWidth(mapFile);
    int height = mapHeight(mapFile);
    m_map = Map(height,width);
    createSpeciesList(speciesFile);
    //create a unique list of all possible Organisms
    populateMap(mapFile);
    //populate the map with Organisms
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
                setUpOrganism(organism, j, i);
                //create an Organism with a matching ID from
                //the list of possible Organisms and
                //placed in its correct location
            }
        }
    }
}

void Ecosystem::setUpOrganism(Organism* organism, int x, int y) {
    SpeciesType type = organism->getSpeciesType();
    switch(type) { //casting to correct type and creating the Organism
        case plant:
            {
                Plant* p = (dynamic_cast<Plant*>(organism))->clone();
                p->setX(x);
                p->setY(y);
                m_map.getTile(x,y)->setPlant(p);
                m_organisms.insert(p);
            }
            break;
        case herbivore:
            {
                Herbivore* h = (dynamic_cast<Herbivore*>(organism))->clone();
                h->setX(x);
                h->setY(y);
                m_map.getTile(x,y)->setAnimal(h);
                m_organisms.insert(h);
            }
                break;
        case omnivore:
            {
                Omnivore* o = (dynamic_cast<Omnivore*>(organism))->clone();
                o->setX(x);
                o->setY(y);
                m_map.getTile(x,y)->setAnimal(o);
                m_organisms.insert(o);
            }
                break;
        default:
            break;
    }
}

void Ecosystem::createSpeciesList(std::string& speciesFile) {
    std::ifstream sFile{speciesFile};
    std::string s{};
    while (getline(sFile,s)) {
        //parse each line of species file to create 
        //a map of all possible unique Organisms
        Organism* o = parseSpecies(s);
        m_species[o->getID()] = o;
    }
}

Map Ecosystem::getMap() { return m_map; }

void Ecosystem::iterate() {
    std::vector<Organism*> dead{};
    for (Organism* o : m_organisms) {
        if (o->isDead()) { //check if a predator ate it before its turn
            dead.push_back(o);
        } else {
            takeTurn(o);
            if (o->isDead()) { //check if it died after its turn
                dead.push_back(o);
                m_map.getTile(o->getX(),o->getY())->setAnimal(nullptr);
            }
        }  
    }
    for (Organism* o : dead) { //clear dead Organisms
        m_organisms.erase(o);
    }
}

void Ecosystem::iterate(int steps) {
    for (int i=0;i<steps;i++) {
        iterate();
    }
}

void Ecosystem::takeTurn(Organism* organism) {
    SpeciesType type = organism->getSpeciesType();
    switch(type) { //takeTurn according to its underlying type
        case plant:
            {
                Plant* p = (dynamic_cast<Plant*>(organism));
                takeTurn(p);
            }
            break;
        case herbivore:
            {   
                Herbivore* h = (dynamic_cast<Herbivore*>(organism));
                takeTurn(h);
            }
            break;
        case omnivore:
            {
                Omnivore* o = (dynamic_cast<Omnivore*>(organism));
                takeTurn(o);
            }
            break;
        default:
            break;
    }
}
void Ecosystem::takeTurn(Plant* plant) {
    //if Plant is eaten grow
    if (plant->isEaten()) {
        if (m_map.getTile(plant->getX(),plant->getY())->hasAnimal()==false) {
            plant->grow();
        }
    }
}
void Ecosystem::takeTurn(Herbivore* herbivore) {
    std::vector<MapTile*> predator{};
    std::vector<MapTile*> food{};
    std::vector<MapTile*> empty{};
    sortTiles(herbivore, predator, food, empty);
    //sort possible tiles into actions
    MapTile* chosenTile{nullptr};
    if (predator.size()>0) { //if there is atleast one predator try run away
        chosenTile = predator[randomNum(predator.size())];
        tryEscape(herbivore, dynamic_cast<Omnivore*>(chosenTile->getAnimal()));
    } else {
        if (food.size()>0) { //if there are consumable Plants eat one at random
            chosenTile = food[randomNum(food.size())];
            herbivore->Animal::eat(chosenTile->getPlant());
        } else if (empty.size()>0) { //move to random empty tile if their exist
            chosenTile = empty[randomNum(empty.size())];
        }
        if (chosenTile!=nullptr) {
            moveAnimal(herbivore, chosenTile);
        }
    }
}
void Ecosystem::takeTurn(Omnivore* omnivore) {
    std::vector<MapTile*> food{};
    std::vector<MapTile*> empty{};
    sortTiles(omnivore, food, empty);
    //sort possible tiles into actions
    MapTile* chosenTile{nullptr};
    if (food.size()>0) { //if there are consumable food eat one at random
        chosenTile = food[randomNum(food.size())];
        if (chosenTile->hasAnimal()) {
            omnivore->eat(dynamic_cast<Herbivore*>(chosenTile->getAnimal()));
        } else {
            omnivore->Animal::eat(chosenTile->getPlant());
        }
    } else if (empty.size()>0){ //move to random empty tile if their exist
        chosenTile = empty[randomNum(empty.size())];
    }
    if (chosenTile!=nullptr) {
        moveAnimal(omnivore, chosenTile);
    }
}

void Ecosystem::sortTiles(Omnivore* omnivore, std::vector<MapTile*>& food, std::vector<MapTile*>& empty) {
    //sorts possible actions an omnivore can take
    //eat food or move
    std::vector<MapTile*> adjacent = m_map.getAdjacent(omnivore->getX(),omnivore->getY());
    for (int i=0;i<adjacent.size();i++) {
        MapTile* tile = adjacent[i];
        if (tile->hasAnimal()) {
            if (omnivore->canConsume(tile->getAnimal())) {
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

void Ecosystem::sortTiles(Herbivore* herbivore, std::vector<MapTile*>& predator, std::vector<MapTile*>& food, std::vector<MapTile*>& empty) {
    //sorts possible actions a herbivore can take
    //eat plant or move
    std::vector<MapTile*> adjacent = m_map.getAdjacent(herbivore->getX(),herbivore->getY());
    for (int i=0;i<adjacent.size();i++) {
        MapTile* tile = adjacent[i];
        if (tile->hasAnimal()) {
            if (tile->getAnimal()->getSpeciesType()==omnivore) {
                predator.push_back(tile);
            }
        } else if (tile->hasPlant()&&(tile->hasAnimal()==false)) {
            if (tile->getPlant()->isEaten()) {
                empty.push_back(tile);
            } else {
                if (herbivore->Animal::canConsume(tile->getPlant())) {
                    food.push_back(tile);
                }
            }
        } else {
            empty.push_back(tile);
        }
    }
}

void Ecosystem::moveAnimal(Animal* animal, MapTile* tile) {
    //move animal to another tile and use one energy
    m_map.getTile(animal->getX(),animal->getY())->setAnimal(nullptr);
    animal->setX(tile->getX());
    animal->setY(tile->getY());
    tile->setAnimal(animal);
    animal->setEnergy(animal->getEnergy()-1);
}

void Ecosystem::tryEscape(Herbivore* prey, Omnivore* predator) {
    //try escape from a predator
    if (prey->getX()==predator->getX()) { //if on same x-coord
        int oppositeY = prey->getY()+(prey->getY()-predator->getY());
        //get y-coord of tile away from predator
        bool escaped = tryEscapeTo(prey, prey->getX(), oppositeY);
        if (escaped==false) {
            if (randomNum(2)==1) { //pick another of the remaining two direction to run
                escaped = tryEscapeTo(prey,prey->getX()+1,prey->getY());
                if (escaped==false) { tryEscapeTo(prey,prey->getX()-1,prey->getY()); }
            } else { //try last possible tile to escape to
                escaped = tryEscapeTo(prey,prey->getX()-1,prey->getY());
                if (escaped==false) { tryEscapeTo(prey,prey->getX()+1,prey->getY()); }
            }
        }
    } else { //if on same y-coord
        int oppositeX = prey->getX()+(prey->getX()-predator->getX());
        //get x-coord of tile away from predator
        bool escaped = tryEscapeTo(prey, oppositeX, prey->getY());
        if (escaped==false) {
            if (randomNum(2)==1) { //pick another of the remaining two direction to run
                escaped = tryEscapeTo(prey,prey->getX(),prey->getY()+1);
                if (escaped==false) { tryEscapeTo(prey,prey->getX(),prey->getY()-1); }
            } else { //try last possible tile to escape to
                escaped = tryEscapeTo(prey,prey->getX(),prey->getY()-1);
                if (escaped==false) { tryEscapeTo(prey,prey->getX(),prey->getY()+1); }
            }
        }
    }
}

bool Ecosystem::tryEscapeTo(Herbivore* prey, int x,int y) {
    //try to escape to the specified tile, return true if sucessful
    MapTile* tile = m_map.getTile(x,y);
    if (tile!=nullptr) {
        if (tile->hasAnimal()) {
            return false;
        } else if (tile->hasPlant()) {
            if (tile->getPlant()->isEaten()) {
                moveAnimal(prey,tile);
                return true;
            } else {
                if (prey->canConsume(tile->getPlant())) {
                    prey->eat(tile->getPlant());
                    moveAnimal(prey,tile);
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            moveAnimal(prey,tile);
            return true;
        }
    }
    return false;
}

Organism* parseSpecies(std::string& s) {
    //parsing strings into information for Organisms
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

void Menu(Ecosystem& ecosystem) { //user interface
    std::cout << "Starting Map: \n";
    ecosystem.getMap().print();
    bool iterate{true};
    char input{};
    while (iterate) {
        std::cout << "Enter: (i - iterate once) (m - iterate multiple) (x - exit)\n";
        std::cin >> input;
        switch (input)
        {
        case 'i':
            std::cout << "After one iteration\n";
            ecosystem.iterate();
            ecosystem.getMap().print();
            break;
        case 'm':
            {
            int iters = enterNum(); //get a valid non-negative number from user
            std::cout << "After " << iters << " iterations\n";
            ecosystem.iterate(iters);
            ecosystem.getMap().print();
            break;
            }
            
        case 'x':
            std::cout << "Exited Ecosystem Simulator\n";
            iterate = false;
            break;
        default:
            std::cout << "Invalid input, try again.\n";
            break;
        }
    }
}



int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::string mapFile{argv[1]};
        std::string speciesFile{argv[2]};
        if (fileExist(mapFile)==false) { 
            std::cerr << "Can not find map file.\n";
            std::cout << "Aborting...\n";
            return 1;
        }
        if (fileExist(speciesFile)==false) { 
            std::cerr << "Can not find species list file.\n";
            std::cout << "Aborting...\n";
            return 1;
        }
        std::cout << "Starting Ecosystem Simulator (created by Justin Lin)\n";
        Ecosystem ecosystem{mapFile,speciesFile};
        Menu(ecosystem);
    } else {
        std::cerr << "Ecosystem requires two arguments, a map file and a species list file.\n";
        std::cout << "Aborting...\n";
        return 1;
    }
    return 0;
}