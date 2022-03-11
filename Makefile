CC = g++
CFLAGS = -Wall -Werror -pedantic
OBJECTS = main.o CelestialBody.o Universe.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: NBody 
NBody: $(OBJECTS) 
	$(CC) $(CFLAGS) -o NBody $(OBJECTS) $(SFML)
main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
CelestialBody.o:CelestialBody.cpp CelestialBody.h
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o
Universe.o:Universe.cpp Universe.h
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o 
clean: 
	rm NBody $(OBJECTS)
	
