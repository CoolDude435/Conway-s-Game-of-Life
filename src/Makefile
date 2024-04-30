all: Ecosystem.bin

Ecosystem.bin: Ecosystem.cpp Ecosystem.h Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o enums.h
	g++ -o Ecosystem.bin Ecosystem.cpp Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o

Map.o: Map.cpp Map.h MapTile.o MapTile.cpp MapTile.h
	g++ -c Map.cpp

MapTile.o: MapTile.cpp MapTile.h Plant.o Plant.cpp Plant.h Animal.o Animal.cpp Animal.h
	g++ -c MapTile.cpp

Omnivore.o: Omnivore.cpp Omnivore.h Animal.o Animal.cpp Animal.h
	g++ -c Omnivore.cpp

Herbivore.o: Herbivore.cpp Herbivore.h Animal.o Animal.cpp Animal.h
	g++ -c Herbivore.cpp

Animal.o: Animal.cpp Animal.h Organism.o Organism.cpp Organism.h
	g++ -c Animal.cpp

Plant.o: Plant.cpp Plant.h Organism.o Organism.cpp Organism.h
	g++ -c Plant.cpp

Organism.o: Organism.cpp Organism.h enums.h
	g++ -c Organism.cpp

clean:
	rm -rf *.o *.bin *gch