all: Ecosystem.bin

#Ecosystem.bin: Ecosystem.cpp Ecosystem.h Map.o Herbivore.o Omnivore.o
#g++ -o Ecosystem.bin Ecosystem.cpp Ecosystem.h Map.o Herbivore.o Omnivore.o
Ecosystem.bin: Ecosystem.cpp Entity.o Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o
	g++ -o Ecosystem.bin Ecosystem.cpp Entity.o Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o

Entity.o: Entity.cpp
	g++ -c Entity.cpp

Organism.o: Organism.cpp Entity.o 
	g++ -c Organism.cpp Entity.o

Map.o: Map.cpp MapTile.o
	g++ -c Map.cpp MapTile.o

MapTile.o: MapTile.cpp Entity.o Animal.o Plant.o
	g++ -c MapTile.cpp Entity.o Animal.o Plant.o

Plant.o: Plant.cpp Organism.o
	g++ -c Plant.cpp Organism.o

Animal.o: Animal.cpp Organism.o
	g++ -c Animal.cpp Organism.o

Omnivore.o: Omnivore.cpp Animal.o
	g++ -c Omnivore.cpp Animal.o

Herbivore.o: Herbivore.cpp Animal.o
	g++ -c Herbivore.cpp Animal.o



clean:
	rm -rf *.o *.bin *gch