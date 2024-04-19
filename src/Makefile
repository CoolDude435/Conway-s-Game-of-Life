all: ecosystem.bin

ecosystem.bin: main.cpp ecosystem.cpp ecosystem.h organism.o plant.o animal.o omnivore.o carnivore.o map.o
	g++ -o ecosystem.bin main.cpp ecosystem.cpp ecosystem.h organism.o plant.o animal.o omnivore.o carnivore.o map.o

organism.o: organism.cpp organism.h
	g++ -c organism.cpp organism.h

map.o: map.cpp map.h
	g++ -c map.cpp map.h

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