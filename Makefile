all: ecosystem.bin

gui:
	g++ -o main main.cpp -lSDL2 -lSDL2main
#g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

sample: ecosystem.bin
	./ecosystem.bin ../input/map.txt ../input/species.txt

ecosystem.bin: src/Ecosystem.cpp src/Ecosystem.h Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o src/enums.h util.o
	g++ -o ecosystem.bin src/Ecosystem.cpp Organism.o Map.o MapTile.o Plant.o Animal.o Omnivore.o Herbivore.o util.o

Map.o: src/Map.cpp src/Map.h MapTile.o src/MapTile.cpp src/MapTile.h
	g++ -c src/Map.cpp

MapTile.o: src/MapTile.cpp src/MapTile.h Plant.o src/Plant.cpp src/Plant.h Animal.o src/Animal.cpp src/Animal.h
	g++ -c src/MapTile.cpp

Omnivore.o: src/Omnivore.cpp src/Omnivore.h Animal.o src/Animal.cpp src/Animal.h Herbivore.o src/Herbivore.cpp src/Herbivore.h
	g++ -c src/Omnivore.cpp

Herbivore.o: src/Herbivore.cpp src/Herbivore.h Animal.o src/Animal.cpp src/Animal.h
	g++ -c src/Herbivore.cpp

Animal.o: src/Animal.cpp src/Animal.h Organism.o src/Organism.cpp src/Organism.h Plant.o src/Plant.cpp src/Plant.h
	g++ -c src/Animal.cpp

Plant.o: src/Plant.cpp src/Plant.h Organism.o src/Organism.cpp src/Organism.h
	g++ -c src/Plant.cpp

Organism.o: src/Organism.cpp src/Organism.h src/enums.h
	g++ -c src/Organism.cpp

util.o: src/util.cpp src/util.h
	g++ -c src/util.cpp

clean:
	rm -rf *.o *.bin *gch

win10clean:
	del *.o
	del *.bin	