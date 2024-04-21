all: ecosystem.bin

ecosystem.bin: main.cpp Ecosystem.cpp Ecosystem.h Organism.o Plant.o Animal.o Omnivore.o Carnivore.o Map.o
	g++ -o Ecosystem.bin main.cpp Ecosystem.cpp Ecosystem.h Organism.o Plant.o Animal.o Omnivore.o Carnivore.o Map.o

organism.o: organism.cpp organism.h
	g++ -c organism.cpp organism.h

map.o: map.cpp map.h maptile.o
	g++ -c map.cpp map.h maptile.o

maptile.o: maptile.h

plant.o: plant.cpp plant.h organism.o
	g++ -c plant.cpp plant.h organism.o

animal.o: animal.cpp animal.h organism.o
	g++ -c animal.cpp animal.h organism.o

omnivore.o: omnivore.cpp omnivore.h animal.o
	g++ -c omnivore.cpp omnivore.h animal.o

carnivore.o: carnivore.cpp carnivore.h animal.o
	g++ -c carnivore.cpp carnivore.h animal.o



clean:
	rm -rf *.o *.bin