all: ecosystem.bin

gui:
	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

sample: ecosystem.bin
	./ecosystem.bin ../input/map.txt ../input/species.txt

ecosystem.bin: Ecosystem.cpp Ecosystem.h Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o enums.h util.o
	g++ -o ecosystem.bin Ecosystem.cpp Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o util.o

Map.o: Map.cpp Map.h MapTile.o MapTile.cpp MapTile.h
	g++ -c Map.cpp

MapTile.o: MapTile.cpp MapTile.h Plant.o Plant.cpp Plant.h Animal.o Animal.cpp Animal.h
	g++ -c MapTile.cpp

Omnivore.o: Omnivore.cpp Omnivore.h Animal.o Animal.cpp Animal.h Herbivore.o Herbivore.cpp Herbivore.h
	g++ -c Omnivore.cpp

Herbivore.o: Herbivore.cpp Herbivore.h Animal.o Animal.cpp Animal.h
	g++ -c Herbivore.cpp

Animal.o: Animal.cpp Animal.h Organism.o Organism.cpp Organism.h Plant.o Plant.cpp Plant.h
	g++ -c Animal.cpp

Plant.o: Plant.cpp Plant.h Organism.o Organism.cpp Organism.h
	g++ -c Plant.cpp

Organism.o: Organism.cpp Organism.h enums.h
	g++ -c Organism.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

clean:
	rm -rf *.o *.bin *gch