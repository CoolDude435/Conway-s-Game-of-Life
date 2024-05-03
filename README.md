# Ecosystem Simulator (Created By Justin Lin)
**Project Detail**
<br>
For CS3210 Final Project
<br>
Details: 
- this is an application which simulates an ecosystem under specified rules
- an ecosystem contains plants, herbivores, and omnivores
- during each iteration of the ecosystem, each organism will take an action
- actions include moving, eating, escaping
- users will be able to run the application using a valid map text file and species text file
- while application is running user can iterate ecosystem once or multiple times and also exit the program
<br>

How to build:
- run the make command in the terminal, this will build a binary name Binary.bin
<br>

How to run:
- run the command ./Binary.bin (arg1) (arg2) in the terminal
    - arg1 is the .txt file of the map
    - arg2 is the .txt file of the species list
___
**Author**
<br>
Justin Lin
___
**Tooling**
<br>
Programming Language: C++
<br>
IDE: VSCode Linux
<br>
Libraries:
- iostream
- string
- vector
- unordered_map
- unordered_set
- limits
- cstdlib
- ctime
- fstream
___
**Files**
<br>
*Makefile* - the Makefile for building Binary.bin
<br>
*Ecosystem.cpp, Ecosystem.h* - Class for Ecosystem Simulator application
<br>
*Map.cpp, Map.h* - Class for 2D map datastructure of ecosystem
<br>
*MapTile.cpp, MapTile.h* - Class for the tiles of the map
<br>
*enums.h* - relevant enums, only holds SpeciesType
<br>
*util.cpp, util.h* - holds relevant utilities
<br>
*Organism.cpp, Organism.h* - Base class for the Organism hierachy
<br>
*Plant.cpp, Plant.h* - Class for the Plant object, derives Organism
<br>
*Animal.cpp, Animal.h* - Abstract class for the Animal object, derives Organism
<br>
*Herbivore.cpp, Herbivore.h* - Class for the Herbivore object, derives Organism
<br>
*Omnivore.cpp, Omnivore.h* - Class for the Omnivore object, derives Organism
___
**Methods:**
___
**Ecosystem**

- Ecosystem() - default constructor
- Ecosystem(std::string& mapFile, std::string& speciesFile) - constructor using a map file and species file
- Map getMap() - getter for m_map
- void iterate() - iterate ecosystem once
- void iterate(int steps) - iterate ecosystem a number of steps
- void populateMap(std::string& mapFile) - populate map with Organisms in correct spots
- void setUpOrganism(Organism* organism, int x, int y) - creates Organisms based off of map and species
- void createSpeciesList(std::string& speciesFile) - create a map to match each unique Organism with its ID
- void takeTurn(Organism* organism) - organism takes a turn according to its type
- void takeTurn(Plant* plant) - specifies how a Plant takes its turn
- void takeTurn(Herbivore* herbivore) - specifies how a Herbivore takes its turn
- void takeTurn(Omnivore* omnivore) - specifies how a Omnivore takes its turn
- void sortTiles(Omnivore* omnivore, std::vector<MapTile*>& food, std::vector<MapTile*>& empty) - sorts adjacent tiles of a Omnivore according to actions it can take
- void sortTiles(Herbivore* herbivore, std::vector<MapTile*>& predator, std::vector<MapTile*>& food, std::vector<MapTile*>& empty) - sorts adjacent tiles of a Herbivore according to actions it can take
- void moveAnimal(Animal* animal, MapTile* tile) - moves an Animal to another MapTile
- void tryEscape(Herbivore* prey, Omnivore* predator) - defines how a Herbivore tries to escape an Omnivore
- bool tryEscapeTo(Herbivore* prey, int x, int y) - try to escape to a specific tile, return false if unable
- Organism* parseSpecies(std::string& s) - parses text into a Organism
- void Menu(Ecosystem& ecosystem) - the user iterface to use Ecosystem Simulator
___
**Map**
- Map() - default constructor
- Map(int height, int width) - constructor taking a height and width
- MapTile* getTile(int x, int y) const - gets the MapTile at a spot, return nullptr if out of bounds
- std::vector<MapTile*> getAdjacent(int x, int y) const - returns a vector of existing adjacent tiles to a spot
- int getWidth() const - getter for map width
- int getHeight() const - getter for map height
- void print() const - prints out the map, chars represent an Organism in that tile
___
**MapTile**
- MapTile() - default constructor
- MapTile(int x, int y, Plant* plant, Animal* animal) - constructor taking in xy-coordinates and pointers to a plant and animal
- int getX() const - getter for x-coordinate
- int getY() const - getter for y-coordinate
- void setX(int x) - setter for x-coordinate
- void setY(int y) - setter for y-coordinate
- bool hasPlant() - check if MapTile contains a Plant
- bool hasAnimal() - check if MapTile contains an Animal
- bool isEmpty() - check if MapTile contains no Plant and Animal
- Plant* getPlant() - getter for Plant pointer
- Animal* getAnimal() - getter for Animal pointer
- void setPlant(Plant* plant) - setter for Plant pointer
- void setAnimal(Animal* animal) - setter for Animal pointer
___
**util**
- int mapWidth(std::string& mapFile) - returns width of map file
- int mapHeight(std::string& mapFile) - returns height of a map file
- int indexOf(std::string& s,char c) - returns index of first instance of a char in a string
- unsigned int randomNum(unsigned int ceiling) - return a random number from 0 to ceiling-1
- bool fileExist(std::string& file) - returns true if a file exists
- int enterNum() - gets a valid non-negative number from user
___
**Organism**
- Organism() - default constructor
- Organism(int x, int y, char id) - constructor taking xy-coordinates and ID
- int getX() const - getter for x-coordinate
- int getY() const - getter for y-coordinate
- void setX(int x) - setter for x-coordinate
- void setY(int y) - setter for y-coordinate
- char getID() const - getter for m_id
- virtual bool isDead() = 0 - returns true if an Organism is dead, is a virtual - function (Plants don´t "die" while Animals do)
- virtual SpeciesType getSpeciesType() = 0 - returns a enum representing a Organism's species type (plant,herbivore,or omnivore), is a virtual function
___
**Plant**
- Plant() - default constructor
- Plant(int x, int y, char id, int regrowCoef, int energyPts) - constructor with info for parent class (Organism) and regrowCoef and energyPts
- int getRegrowCoef() const - getter for m_regrowCoef
- int getEnergyPts() const - getter for m_energyPts
- int getRegrowTimer() const - getter for m_regrowTimer
- bool isEaten() const - return true if m_isEaten is true
- void grow() - Plant grows one turns, also handles if fully grown
- void wasEaten() - Plant becomes eaten and starts regrowing process
- Plant* clone() const - creates a pointer to a clone of itself
- SpeciesType getSpeciesType() override - returns SpeciesType plant, overrides parent method
- bool isDead() override - returns false (plants don´t "die"), overrides parent method
___
**Animal**
- Animal() - default constructor
- Animal(int x, int y, char id, int maxEnergy) - constructor with info for parent class (Organism) and maxEnergy
- int getEnergy() const - getter for m_energy
- int getMaxEnergy() const - getter for m_maxEnergy
- void setEnergy(int energy) - setter for m_energy
- bool canConsume(Plant* plant) const - returns true if it can consume the Plant
- void eat(Plant* plant) - Animal eats the Plant gaining energy
- bool isDead() override - return true if m_energy is zero
___
**Herbivore**
- Herbivore() - default constructor
- Herbivore(int x, int y, char id, int maxEnergy) - constructor with info for parent class (Animal)
- Herbivore* clone() const - creates a pointer to a clone of itself
- SpeciesType getSpeciesType() override - returns SpeciesType herbivore, overrides parent method
- void wasEaten() - Herbivore was eaten set m_energy to zero
___
**Omnivore**
- Omnivore() - default constructor
- Omnivore(int x, int y, char id, int maxEnergy) - constructor with info for parent class (Animal)
- Omnivore* clone() const - creates a pointer to a clone of itself
- SpeciesType getSpeciesType() override - returns SpeciesType omnivore, overrides parent method
- bool canConsume(Animal* animal) const - returns true if it can consume the Animal
- void eat(Herbivore* herbivore) - Omnivore eats the Herbivore gaining its energy
___
**Notes:**
- In my implementation the order in which Organisms take their turn is based off of when they are created, it was reverse order for me (I used enhance for loop on a unordered_set)