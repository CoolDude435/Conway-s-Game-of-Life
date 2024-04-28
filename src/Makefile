all: Ecosystem.bin

#Ecosystem.bin: Ecosystem.cpp Ecosystem.h Map.o Herbivore.o Omnivore.o
#g++ -o Ecosystem.bin Ecosystem.cpp Ecosystem.h Map.o Herbivore.o Omnivore.o
Ecosystem.bin: Ecosystem.cpp Ecosystem.h Entity.o Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o
	g++ -o Ecosystem.h Entity.o Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o

Entity.o: Entity.cpp Entity.h
	g++ -c Entity.cpp Entity.h

Organism.o: Organism.cpp Organism.h Entity.o enums.h
	g++ -c Organism.cpp Organism.h Entity.o enums.h

Map.o: Map.cpp Map.h MapTile.o
	g++ -c Map.cpp Map.h MapTile.o

MapTile.o: MapTile.cpp MapTile.h Entity.o Animal.o Plant.o
	g++ -c MapTile.cpp MapTile.h Entity.o Animal.o Plant.o

Plant.o: Plant.cpp Plant.h Organism.o
	g++ -c Plant.cpp Plant.h Organism.o

Animal.o: Animal.cpp Animal.h Organism.o
	g++ -c Animal.cpp Animal.h Organism.o

Omnivore.o: Omnivore.cpp Omnivore.h Animal.o
	g++ -c Omnivore.cpp Omnivore.h Animal.o

Herbivore.o: Herbivore.cpp Herbivore.h Animal.o
	g++ -c Herbivore.cpp Herbivore.h Animal.o



clean:
	rm -rf *.o *.bin *gch